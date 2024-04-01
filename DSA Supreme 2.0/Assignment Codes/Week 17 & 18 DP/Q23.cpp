// https://leetcode.com/problems/target-sum/description/

// Target Sum

/*
Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

*/

/*
Approach - So we can either put a + sign or a - sign and we want to achieve the target when index is equal to nums.size()
so simple use include exclude approach and once give a +ve sign to the current number and get upcoming recursive solution
then give a -ve sign to the current number and get upcoming recursive solution and the return the maximum of the 2 solutions.

so we have a sum variabele so for once we will add to the sum the current number and for once we will subtract the curent number from sum.
Then return the maximum of the 2 solutions
*/

class Solution
{
public:
    int solvewithMem(vector<int> &nums, int target, int index, int sum,
                     map<pair<int, int>, int> &dp)
    {
        if (index >= nums.size())
        {
            return sum == target ? 1 : 0;
        }
        if (dp.find({index, sum}) != dp.end())
        {
            return dp[{index, sum}];
        }
        int op1 = solvewithMem(nums, target, index + 1, sum + nums[index], dp);
        int op2 = solvewithMem(nums, target, index + 1, sum - nums[index], dp);
        return dp[{index, sum}] = op1 + op2;
    }
    int solvewithTab(vector<int> &nums, int target)
    {
        map<pair<int, int>, int> dp;
        dp[{nums.size(), 0}] = 1;

        int total = 0;
        for (auto it : nums)
        {
            total += it;
        }
        for (int index = nums.size() - 1; index >= 0; index--)
        {
            for (int sum = -total; sum <= total; sum++)
            {
                int op1 = dp.find({index + 1, sum + nums[index]}) != dp.end()
                              ? dp[{index + 1, sum + nums[index]}]
                              : 0;
                int op2 = dp.find({index + 1, sum - nums[index]}) != dp.end()
                              ? dp[{index + 1, sum - nums[index]}]
                              : 0;
                dp[{index, sum}] = op1 + op2;
            }
        }
        return dp[{0, target}];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // map<pair<int,int>,int>dp;
        // return solvewithMem(nums, target, 0, 0,dp);
        return solvewithTab(nums, target);
    }
};