//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

//Delete N nodes after M nodes of a linked list

/*
Simple Problem hai 
Step 1 - Pehele M nodes itrate karo 
Step 2 - Then N nodes ko Delete KArna hai toh ek Next pointer ya prev pointer chahiye hoga 
Step 3 - Easily delete karo
*/

/*
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(!head) return;
        
        Node*temp=head;
        
        for(int i=0;i<M-1;i++){
            if(!temp) return ;
            temp=temp->next;
        }
        
        if(!temp) return ;
        
        Node*pos=temp;
        
        temp=pos->next;
        
        pos->next=NULL;
        
        for(int i=0;i<N;i++){
            
            if(!temp) break;
            
            Node*temp2=temp->next;
            
            temp->next=NULL;
            
            delete temp;
            
            temp=temp2;
        }
        pos->next=temp;
        
        linkdelete(temp,M,N);
        
    }
};