//https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/


//find the minimum and maximum number of nodes between critical-points


/*
pehele toh critical points ka logic dekho 
then remeber Max Nodes between 2 critical points will be always first and last so store 1st CP
and Min you need to calcualte along the way using prev critical point
*/


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> ans = {-1,-1};
        ListNode* prev = head;
        if(!prev) return ans;

        ListNode* curr = head->next;
        if(!curr) return ans;

        ListNode* ahead = head->next->next;
        if(!ahead) return ans;
        
        int first = -1;
        int last = -1;
        int minDis = INT_MAX;
        int i = 1;
        while(ahead){
            bool isCP = ( prev->val > curr->val && ahead->val > curr->val) || 
                        ( prev->val < curr->val && ahead->val < curr->val);

            if(isCP){
                // means this point is a cp
                if(first==-1){
                    first=i;
                    last=i;
                }
                else{
                    minDis = min(minDis,i-last);
                    last=i;
                }
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            ahead=ahead->next;
        }
        int maxDis = last-first;

        if(maxDis==0){
            return ans;
        }
        else{
            ans[0]=minDis;
            ans[1]=maxDis;
        } 
        return ans;
    }
};