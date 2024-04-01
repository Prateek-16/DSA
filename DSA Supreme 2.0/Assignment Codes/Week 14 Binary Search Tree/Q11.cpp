//https://www.interviewbit.com/problems/valid-bst-from-preorder/

        // Valid BST from preorder

        /*
        Hint - We have already Done BST from PreOrder using I traversor and Min and Max  range
        so if any Node is out of the range I wont completly traverse the preorder
         and we will know that by comparing the size of i and preorder
         */

        class Solution
{
public:
    TreeNode *solve(int &i, int max, int min, vector<int> &preorder)
    {
        if (i >= preorder.size())
        {
            return NULL;
        }
        TreeNode *root = NULL;
        int ele = preorder[i];
        if (ele > min && ele < max)
        {
            root = new TreeNode(ele);
            i++;
            root->left = solve(i, ele, min, preorder);
            root->right = solve(i, max, ele, preorder);
        }
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int max = INT_MAX;
        int min = INT_MIN;
        int i = 0;
        solve(i, max, min, preorder);
        return i == preorder.size();
    }
};
