//https://leetcode.com/problems/merge-two-sorted-lists/description/


//Merge two Sorted lists


/*
Simple Solution hai - 
Step 1 - 2 pointers set karlo 
Step 2 - then comapre karte jao simple, jasie arrays mai karte the 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL && list2==NULL){
            return list1;
        }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        

        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* head3=NULL;
        ListNode*prev=NULL;

        if(temp1->val > temp2->val){
            prev=temp2;
            head3=prev;
            temp2=temp2->next;
        }
        else{
            prev=temp1;
            head3=prev;
            temp1=temp1->next;
        }
        while(temp1!=NULL && temp2!=NULL){

            if (temp1->val > temp2->val){

                prev->next=temp2;
                prev=prev->next;
            
                temp2=temp2->next;
            }
            else{
                prev->next=temp1;
                prev=prev->next;
    
                temp1=temp1->next;
            }
        }
        if(temp1==NULL && temp2==NULL){
            return head3;
        }
        if(temp1==NULL){
            while(temp2!=NULL){
                prev->next=temp2;
                prev=prev->next;
                temp2=temp2->next;
            }
        }
        if(temp2==NULL){
            while(temp1!=NULL){
                prev->next=temp1;
                prev=prev->next;
                temp1=temp1->next;
            }

        }
        return head3;

        
    }
};

