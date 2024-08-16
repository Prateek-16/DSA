// PROBLEM 01: Balanced Binary Tree (Leetcode-110)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
TC - O(n)
SC - O(n)

class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    bool ans = true;
    maxDepth(root, ans);
    return ans;
  }

  // Returns the height of root and sets ans to false if root unbalanced.
  int maxDepth(TreeNode* root, bool& ans) {
    if (root == nullptr || !ans)
      return 0;
    const int left = maxDepth(root->left, ans);
    const int right = maxDepth(root->right, ans);
    if (abs(left - right) > 1)
      ans = false;
    return max(left, right) + 1;
  }
};


************************************************************

class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);
        int finalH = max(leftH, rightH) + 1;
        
        return finalH;
    }

    bool isBalanced(TreeNode* root) {
        // Base case
        if(root == NULL){
            // Hum leaf node ko balanced tree assume kar rhe hai
            return true;
        }

        // 1 case hum solve kr lenge
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool currentNode = (diff <= 1);

        // Ab recursion baki ka solve khud kar lega
        bool leftSub = isBalanced(root->left);
        bool rightSub = isBalanced(root->right);

        // Check ki tree balanced hai ya nhi
        if(currentNode && leftSub && rightSub){
            return true;
        }
        else{
            return false;
        }
    }
};