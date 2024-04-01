//https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1


//Inorder Successor in BST


class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node * ans = NULL;
        int temp = x->data;
        Node* curr = root;
        while(curr){
            if(curr->data > temp){
                ans = curr;
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        
        return ans;
    }
};