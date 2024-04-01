//https://leetcode.com/problems/binary-tree-inorder-traversal/description/


// Morris Traversal


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == NULL) {
                // visit Curr and Move Right
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Now left exist so before moving to the left we will connect
                // curr with its inorder predececor
                TreeNode* pred = curr->left;
                while (pred->right &&
                       pred->right != curr) { // so the other condition prevent
                                              // us from looping infinitely if
                                              // pred is already connect to curr
                    pred = pred->right;
                }
                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } else { // means pred is already connected with curr with also
                         // means we have visited the left and now we can move
                         // to the right of the currrent node
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};