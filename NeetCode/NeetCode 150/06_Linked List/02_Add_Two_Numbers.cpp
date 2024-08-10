//https://leetcode.com/problems/add-two-numbers/description/


/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/


/*
Approach - Its given that the number in the list are already reversed, so we can easily add the numbers
Steps :
    1. Initalize a dummy Node as Head for answer list and a curr pointer on this dummy
    2. Also initialize carry as 0
    3. Loop until both the list pointers reaches NULL
        1. get the value of l1 pointer Node and l2 pointer Node , and if l1 or l2 are at null then store 0
        2. calculate the sum ie val1 + val2 + carry
        3. set new carry = sum/10
        4. set curr -> next as new Node ( sum % 10 )
        5. move curr to curr->next
        6. check if l1 is not null , then move l1 to its next.
        7. check if l2 is not null , then move l2 to its next.
    4. After the loop if the carry still exist :
        1. create a new node with value carry and set it to current next
    5. return dummy -> next

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return dummy->next;
        
    }
};