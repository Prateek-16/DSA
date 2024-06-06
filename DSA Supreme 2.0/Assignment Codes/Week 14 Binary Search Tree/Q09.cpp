//https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?count=25&page=5&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM

// Flatten a BST

TreeNode<int>* inorder(TreeNode<int>*root,TreeNode<int>* &prev){
    if(root==NULL){
        return NULL;
    }
    inorder(root->left,prev);
    prev->right = root;
    prev->left = NULL;
    prev = root;
    inorder(root->right,prev);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    TreeNode<int>* dummy = new TreeNode<int>(-1);
    TreeNode<int>* prev = dummy;
    inorder(root,prev);
    prev->left = NULL;
    prev->right = NULL;
    return dummy->right;
}