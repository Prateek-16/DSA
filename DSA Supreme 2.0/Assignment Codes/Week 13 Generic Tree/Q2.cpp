//https://leetcode.com/problems/balanced-binary-tree/description/

//Balanced binary tree

//************************************************************************************************


/*
This is the longer Method To Find the Hieght of a Binary Tree
Its simple and easy to understand
Step 1 - Find max depth of root ->left and root->right 
step 2 - difference Between Left and Right should be Not More than 1
Step 3 - Check id root->left isbanacled and root->right isBalanced
Step 4 - if all true the return true;
*/


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        int height=max(left,right)+1;
        return height;  
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        int left_height=maxDepth(root->left);
        int right_height=maxDepth(root->right);
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(left && right && abs(left_height-right_height)<=1){
            return true;
        }
        else{
            return false;
        }
        
    }
};

//****************************************************************************************************

/*Now the Faster Method will be 
SINCE WE ARE ALREADY FINDING THE LEFT AND RIGHT HEIGHT IN MAX HEIGHT FUNCTION WE CAN COMPARE THERE ITSELF 
IF THE DIFFERENCE OF LEFT AND RIGHT MORE THAN 1 */

class Solution {
public:
    bool height = true;
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int curr_height = abs(right - left);
        if (curr_height > 1) {
            height = false;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        maxDepth(root);
        if (height) {
            return true;
        } else {
            return false;
        }
    }
};