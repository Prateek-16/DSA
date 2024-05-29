struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& in){
        if(root==NULL){
            return;
        }

        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode *solve(vector<int>&in, int start, int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)>>1;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = solve(in,start,mid-1);
        root->right = solve(in,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        int start=0;
        int end = in.size()-1;
        //inoder to balanced Binary tree - just find min at each step and divide the nodes into 2
        return solve(in,start,end);
    }
};