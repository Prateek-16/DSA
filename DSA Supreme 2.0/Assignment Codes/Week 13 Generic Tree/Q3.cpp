//https://leetcode.com/problems/same-tree/description/

//Are Two Trees Identical

/*Basically we are given 2 Nodes So Check if 
Step 1 - Both the Node Current Is same 
Step 2 - then call for left and then the right
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};