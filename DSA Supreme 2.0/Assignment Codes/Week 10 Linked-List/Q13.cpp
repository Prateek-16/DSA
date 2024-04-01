//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/


//Swapping Nodes in a Linked List

/*
So we need to swap Kth node from start and Kth from the end = so i have done this by simply reaching these Nodes and swaping the values
but in interview we will be asked to swap the links of the nodes. which makes this a lot harder
*/
class Solution {
public:
    ListNode* KthNode(ListNode* head,int k){
        ListNode* temp = head;
        if(temp==NULL){
            return NULL;
        }
        while(k-1){
            if(temp){
                temp=temp->next;
            }
            else{
                return NULL;
            }
            k--;
        }
        return temp;
    }
    ListNode* Kth_end_node(ListNode* head,int k){
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        if(temp1==NULL){
            return NULL;
        }
        while(k){
            if(temp2){
                temp2=temp2->next;
            }
            else{
                return NULL;
            }
            k--;
        }
        while(temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    } 
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kth_from_begg = KthNode(head,k);
        ListNode* kth_from_end = Kth_end_node(head,k);
        int temp = kth_from_begg->val;
        kth_from_begg->val = kth_from_end->val;
        kth_from_end->val = temp;
        return head;
    }
};