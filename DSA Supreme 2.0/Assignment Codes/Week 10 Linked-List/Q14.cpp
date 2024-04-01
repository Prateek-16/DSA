//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/


// Remove Zero Sum Consecutive Nodes from Linked List


/*
Toh A little Bit complex problem :
Approch : 
Step 1 : we will mentain a Map <int,ListNode*> type 
        where int will be the int will contain the sum and ListNode will be the Node at which that sum is found
Step 2 : Now we will continuously Update Sum for Each Node and check if sum is already mapped
        IF SUM IS ALREADY IN THE MAP - that means our sum of previous few nodes is becoming zero so we will need to remove them
        but before remove we need to deleted their entries from the map also
        IF NOT - we will enter values in the map 
        another case will be IF SUM = 0 {
            in this case we need to clear the whole map and put the head on current node, beacuse the sum of all preveous nodes have become 0 
        }
*/
class Solution {
public:
    void sanitize(unordered_map<int,ListNode*>&mp,int csum,ListNode* temp){
        int st = csum;
        while(true){
            st = st + temp->val;
            if(st==csum){
                break;
            }
            mp.erase(st);
            temp=temp->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL || (head->next==NULL && head->val == 0)){
            return NULL;
        }
        unordered_map<int,ListNode*>mp;
        ListNode* it = head;
        int csum=0;
        while(it){
            csum += it->val;
            if(csum==0){
                head=it->next;
                mp.clear();
            }
            else if(mp.find(csum)!=mp.end()){
                ListNode* temp = mp[csum];
                sanitize(mp,csum,temp->next);
                
                temp->next = it->next;
            }
            else{
                mp[csum]=it;
            }
            it=it->next;
        }
        return head;
    }
};