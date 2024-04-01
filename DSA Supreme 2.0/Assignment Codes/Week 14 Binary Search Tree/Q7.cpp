//https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1


//Check whether the BST contains a dead end.


class Solution{
  public:
    void solve(Node* root,unordered_map<int,bool>& visited,bool &ans){
        if(root==NULL){
            return;
        }
        visited[root->data]=true;
        if(root->left==NULL && root->right==NULL){
            int x1 = root->data + 1;
            int x2 = root->data -1 == 0 ? root->data : root->data - 1;
            if( visited.find(x1) != visited.end() && visited.find(x2) != visited.end() ) {
                ans = true;
                return;
            }
        }
        solve(root->left,visited,ans);
        solve(root->right,visited,ans);
        
        
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        //preorder traversal
        bool ans = false;
        unordered_map<int,bool>visited;
        solve(root,visited,ans);
        return ans;
    }
};