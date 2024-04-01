//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


// Binary tree zig-zag level order traversal


/*
iven the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between). 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/


/*
Approach - So we need to do level order traversal only and because we are return a vector of vvector we will do a for loop inside the while
which is itrate for the size of the queue, this size will contain the nodes of the current level.

so simplly what we can do is mentain a flag variable and when the flag is true we can reverse the array for the current level
that it !!
*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        bool count = false;
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            if (count) {
                reverse(temp.begin(), temp.end());
            }
            count = !count;
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root);
    }
};