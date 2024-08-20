//https://leetcode.com/problems/find-duplicate-subtrees/description/

//Find Duplicate Subtrees


***********************************************************


#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
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
    unordered_map<string, int> subtreeCounter;  // Used for counting occurrences of subtrees.
    vector<TreeNode*> duplicateSubtrees;        // Stores the roots of duplicate subtrees.

    // Function to find all duplicate subtrees in a binary tree.
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverseAndSerialize(root);
        return duplicateSubtrees;
    }

    // Helper function to perform DFS traversal and serialize each subtree.
    string traverseAndSerialize(TreeNode* node) {
        if (!node) return "#";  // Use "#" to represent null pointers.

        // Serialize the current subtree rooted at node.
        string serialization = to_string(node->val) + "," + traverseAndSerialize(node->left) + "," + traverseAndSerialize(node->right);

        // Increment the count for this serialized subtree.
        ++subtreeCounter[serialization];

        // If this is the second time we've seen this subtree, add it to the answer.
        if (subtreeCounter[serialization] == 2) {
            duplicateSubtrees.push_back(node);
        }

        // Return the serialization of this subtree.
        return serialization;
    }
};


********************************************************************


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