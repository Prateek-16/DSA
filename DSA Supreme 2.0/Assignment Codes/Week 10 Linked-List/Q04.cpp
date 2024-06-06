//https://leetcode.com/problems/intersection-of-two-linked-lists/


//intersection of two linked lists

/*
Simple approach - Using Map compare data and return the points with same data
Interview approach - set 2 pointers at A and B then itrate until any one becomes NULL
Handle some edge cases here such as no intersection at all
Then find will pointer becomes NULL first and then count len until next pointer also become NULL
Then traverse again but this time move the 1st pointer Len node ahead
at some node both will intersect and return that node
*/
class Solution {

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a=headA;
        ListNode*b=headB;
        while(a->next && b->next){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;

        }
        if(a->next==0 && b->next==0 && a!=b){//condition for when a and b are two seprate linked list
            return NULL;
        }
        if(a->next==NULL){ // if a is over and b is not
        int len=0;
            while(b->next!=NULL){
                len++;
                b=b->next;
            }
            while(len--){
                headB=headB->next;
            }
            while(headA!=headB){
                headA=headA->next;
                headB=headB->next;
            }
        }
        else{
            int len=0;
            while(a->next!=NULL){
                len++;
                a=a->next;
            }
            while(len--){
                headA=headA->next;
            }
            while(headA!=headB){
                headA=headA->next;
                headB=headB->next;
            }
        }
        return headA;


        

        
    }
};