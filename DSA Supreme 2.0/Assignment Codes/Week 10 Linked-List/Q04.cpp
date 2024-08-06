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

Another similar but easier way with 2 pointers 

// CPP program to print intersection of lists
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
    int data;
    Node* next;
      Node(int x) {
        data = x;
         next = NULL;
    }
};

// A utility function to return  intersection node
Node* intersectPoint(Node* head1, Node* head2)
{
    // Maintaining two pointers ptr1 and ptr2
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    if (ptr1 == NULL || ptr2 == NULL)
        return NULL;

    while (ptr1 != ptr2) {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr1 == ptr2)
            return ptr1;

        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL)
            ptr1 = head2;
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL)
            ptr2 = head1;
    }
    return ptr1;
}

// Driver code
int main()
{
    /*
    Create two linked lists

    1st Linked list is 3->6->9->15->30
    2nd Linked list is 10->15->30

    15 30 are elements in the intersection list
    */

    Node* newNode;
    Node* head1 = new Node(10);
    Node* head2 = new Node(3);
    newNode = new Node(6);
    head2->next = newNode;
    newNode = new Node(9);
    head2->next->next = newNode;
    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node(30);
    head1->next->next = newNode;
    head1->next->next->next = NULL;
    Node* intersect_node = NULL;

    // Find the intersection node of two linked lists
    intersect_node = intersectPoint(head1, head2);
    if(intersect_node == NULL)
      cout << "No intersection Point";
      else 
      cout << "Intersection Point = " << intersect_node->data << "\n";
    return 0;
}
