//https://leetcode.com/problems/range-sum-of-bst/


//Range sum of bst


class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return 0;
        }
        int ele = root->val;
        if (ele >= low && ele <= high) {
            sum += ele;
        }
        if (ele > low) {
            rangeSumBST(root->left, low, high);
        }
        if (ele < high) {
            rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};