//https://leetcode.com/problems/house-robber-iii/description/


//House Robber 3


/*
Approach - This is a simple question  we will simply use include / exclude principle in this question
Step 1 - Include the current Node : then you cant include its direct left or right children
Step 2 - Exclude the current node then you can include its direct left or right children
*/


class Solution {
public:
    int solvewithMem(TreeNode* root,unordered_map<TreeNode*,int>&dp){
        if(!root){
            return 0;
        }
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }
        //include
        int sum_include = 0;
        int rob_house = root->val;
        if(root->left){
            int left_ans = solvewithMem(root->left->left,dp)+ solvewithMem(root->left->right,dp);
            sum_include += left_ans;
        }
        if(root->right){
            int right_ans = solvewithMem(root->right->left,dp) + solvewithMem(root->right->right,dp);
            sum_include += right_ans;
        }
        sum_include += rob_house;

        //Exclude
        int sum_exclude = solvewithMem(root->left,dp) + solvewithMem(root->right,dp);

        return dp[root] = max(sum_include,sum_exclude);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return solvewithMem(root,dp);
    }
};