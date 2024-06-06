//https://leetcode.com/problems/unique-binary-search-trees-ii/


//Unique Binary Search Trees II


/*

Approach - So we need to find the unique combinations of BST possible...
so how we are doing it is we will iterate over every every int from start to end and will get the left ans and the right answer for that integer 
Then we will make all possible combinations of left and right answers using 2 for loops and store the answer in the final vector

*/


class Solution {
public:
    vector<TreeNode*> allPossibleBST(int start, int end) {
        if(start>end){
            return {0};
        }
        if(start==end){
            return {new TreeNode(start)};
        }
        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = allPossibleBST(start, i - 1);
            vector<TreeNode*> right = allPossibleBST(i + 1, end);

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) { return allPossibleBST(1, n); }
};