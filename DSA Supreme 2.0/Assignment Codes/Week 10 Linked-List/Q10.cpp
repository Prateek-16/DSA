//https://leetcode.com/problems/merge-nodes-in-between-zeros/description/


// Merge Nodes in Between Zeros


/*
Simple Hai JabTak Node ka data -> 0 nahi a jata tabtak itrate karte jao and csum mai nodes ka data ki value store akrte jao
jab data 0 a jae toh ek new node bana lo us data ke sath and uspar ek head2 and iteration use karte New linked list bana lena
*/


class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode*temp=head->next;
        int sum=0;
        ListNode*head2=NULL;
        ListNode*it = NULL;

        while(temp){
            sum = sum + (temp->val);
            if(temp->val==0){
                ListNode* newNode = new ListNode(sum);
                head2=newNode;
                it=newNode;
                temp=temp->next;
                break;
            }
            temp=temp->next;
        }
        sum=0;
        while(temp){
            sum+=temp->val;

            if(temp->val==0){
                ListNode* newNode = new ListNode(sum);
                it->next=newNode;
                it=it->next;
                sum=0;
            }
            temp=temp->next;
        }
        return head2;

        
    }
};