//https://leetcode.com/problems/path-sum-iii/


//Path sum 111 OR K Sum Path


class Solution {
public:
    int pathexist(TreeNode* root, long long int targetSum) {
        int curr_path = 0;
        if (root == NULL) {
            return 0;
        }
        targetSum = targetSum - root->val;
        if (targetSum == 0) {
            curr_path++;
        }
        int left_path = pathexist(root->left, targetSum);
        int right_path = pathexist(root->right, targetSum);
        curr_path = curr_path + left_path + right_path;
        return curr_path;
    }
    void solve(TreeNode* root, int targetSum, int& count) {
        if (root == NULL) {
            return;
        }
        int curr_node_path = pathexist(root, targetSum);
        count += curr_node_path;

        solve(root->left, targetSum, count);
        solve(root->right, targetSum, count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        solve(root, targetSum, count);
        return count;
    }
};

*******************************************************

class Solution {
 public:
  int pathSum(TreeNode* root, int sum) {
    if (root == nullptr)
      return 0;
    return dfs(root, sum) +            //
           pathSum(root->left, sum) +  //
           pathSum(root->right, sum);
  }

 private:
  int dfs(TreeNode* root, int sum) {
    if (root == nullptr)
      return 0;
    return (sum == root->val) +                //
           dfs(root->left, sum - root->val) +  //
           dfs(root->right, sum - root->val);
  }
};