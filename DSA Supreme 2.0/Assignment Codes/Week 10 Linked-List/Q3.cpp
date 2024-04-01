//https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1


//Print Nth node from end of linked list


/*
So single Iration mai Nth Node from the end Find karne ke lye 
step 1 - Take 2 pointers at head and move one point n time ahead;
step 2 - Now move both pointers until front/ahead pointer is at null
Step 3 - at this point the behind pointer will be at the nth node from the end
*/
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           Node* temp1 = head;
           Node* temp2 = head;
           while(n){
               if(temp2){
                   temp2=temp2->next;
                   n--;
               }
               else{
                   return -1;
               }
               
           }
           while(temp2!=NULL){
               temp1=temp1->next;
               temp2=temp2->next;
           }
           return temp1->data;
           
    }
};
