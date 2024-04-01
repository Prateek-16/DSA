//https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/


//double a number represented as a linked list


/*
Step 1 - Reach at the end of the linked List (by recursion)
Step 2 - use a carry by reference variable and find carry and current Node value (basically Multiple node -> data with 2 and find the carry)
step 3 - Once this fuction is done check if carry is Note 0, if not the then Make a new node and enter carry into, this will be the new head
*/

class Solution {
public:
    void solve(ListNode* head, int &carry){
        if(head==NULL){
            return;
        }
        solve(head->next,carry);
        int prop = head->val * 2 + carry;
        carry = prop / 10;
        head->val = prop % 10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head,carry);
        if(carry){
            ListNode* carryNode = new ListNode(carry);
            carryNode->next = head;
            return  carryNode;
        }
        return head;  
    }
};