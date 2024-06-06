//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

//Construct a binary search tree from preorder traversal

/*
2 Methods : 
        1. sort the preorder and use inorder to construct TC-O(nlogn)
        2. using Min and Max range and Do single Itration TC-O(n)
*/

class Solution {
public:
    TreeNode* solve(int& i, int max, int min, vector<int>& preorder) {
        if (i >= preorder.size()) {
            return NULL;
        }
        TreeNode* root = NULL;
        int ele = preorder[i];
        if (ele > min && ele < max) {
            root = new TreeNode(ele);
            i++;
            root->left = solve(i, ele, min, preorder);
            root->right = solve(i, max, ele, preorder);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int max = INT_MAX;
        int min = INT_MIN;
        int i = 0;
        return solve(i, max, min, preorder);
    }
};