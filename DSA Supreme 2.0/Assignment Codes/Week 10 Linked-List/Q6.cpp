//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1


//flattening a linked list


/*
Interesting Question this is :
the question is kind of similar to Merge Two sorted lists
Catch - We need to recursively call until the last Node And from there start merging the lists because only then our next pointers will be correct
so its simple actually 
You need to recursively go until the end node and from there you need to call merge list functions
*/


/*
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
Node* mergeTwoLists(Node* list1, Node* list2) {

        if(list1==NULL && list2==NULL){
            return list1;
        }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }

        Node* temp1=list1;
        Node* temp2=list2;
        Node* head3=NULL;
        Node*prev=NULL;
        
        if(temp1->data > temp2->data){
            prev=temp2;
            head3=prev;
            temp2=temp2->bottom;
        }
        else{
            prev=temp1;
            head3=prev;
            temp1=temp1->bottom;
        }
        
        while(temp1!=NULL && temp2!=NULL){
            if (temp1->data > temp2->data){

                prev->bottom=temp2;
                prev=prev->bottom;
            
                temp2=temp2->bottom;
            }
            else{
                prev->bottom=temp1;
                prev=prev->bottom;
    
                temp1=temp1->bottom;
            }
        }
        
        if(temp1==NULL && temp2==NULL){
            return head3;
        }
        
        if(temp1==NULL){
            while(temp2!=NULL){
                prev->bottom=temp2;
                prev=prev->bottom;
                temp2=temp2->bottom;
            }
        }
        
        if(temp2==NULL){
            while(temp1!=NULL){
                prev->bottom=temp1;
                prev=prev->bottom;
                temp1=temp1->bottom;
            }
        }
        
        return head3;
    }
Node *flatten(Node *root)
{
    if(!root) return root;
    Node* head=mergeTwoLists(root,flatten(root->next));
    return head;
}