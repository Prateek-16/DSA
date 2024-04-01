//https://leetcode.com/problems/find-duplicate-subtrees/description/

//Find Duplicate Subtrees

class Solution {
public:
    // basically we are encoding the subtree in a special type string to save
    // the time
    vector<TreeNode*> ans;
    unordered_map<string, int> subtreemap;

    string preorder(TreeNode* root) {
        if (!root)
            return "N";

        string curr = to_string(root->val);
        string l = preorder(root->left);
        string r = preorder(root->right);
        string s = curr + "," + l + "," + r;

        if (subtreemap.find(s) != subtreemap.end()) {
            if (subtreemap[s] ==
                1) { // for each kind of string we only need to return a single
                     // root, therefore checking
                ans.push_back(root);
            }
            subtreemap[s]++;
        } else {
            subtreemap[s] = 1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};