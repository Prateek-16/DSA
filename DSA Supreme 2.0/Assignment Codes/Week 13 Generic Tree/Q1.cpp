//https://leetcode.com/problems/diameter-of-binary-tree/

//Diameter of Binary Tree

//************************************************************************************************
/* This is the slower version to find the diameter of a binary tree
in this version we ae calling max depth for every node and then max depth return the maximum  of its left height and the right height*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int height = max(left, right) + 1;
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_max = maxDepth(root->left);
        int right_max = maxDepth(root->right);
        int possible_max = left_max + right_max;
        int max_depth_left = diameterOfBinaryTree(root->left);
        int max_depth_right = diameterOfBinaryTree(root->right);
        return max(possible_max, max(max_depth_left, max_depth_right));
    }
};

//*************************************************************************************************************

// We can simply use maxdepth function to calculate the depth as well as the diamter of the tree

class Solution {
public:
    int Max_dia = 0;
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int dia = left + right;
        Max_dia = max(dia,Max_dia);
        int height = max(left, right) + 1;
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        maxDepth(root);
        return Max_dia;
    }
};
