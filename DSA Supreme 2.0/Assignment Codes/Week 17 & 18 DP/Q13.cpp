//https://leetcode.com/problems/burst-balloons/


//Burst Balloons


/*
Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

*/

/*
This Problem Looks Easy but we cant directly apply top down approach here, because of non independent sub problems,
so we need to move from bottom up in this problem 

this means instead of going like first ballon burst then next then next towards the last ballon,
we need to move from the last ballon toward the first ballon

this is done to make proper independent sub problems.
*/

/*
So to move bottom up this is the crux 

for (int i = start; i <= end; i++) {
            coin = max(coin, nums[start - 1] * nums[i] * nums[end + 1] +
                                 solvewithMem(nums, start, i - 1, dp) +
                                 solvewithMem(nums, i + 1, end, dp));
        }

Explaination - Here we are Checking from the start to the end which balllon would have possibly been burst,
we are checking all possible values and from start to the end.

another think to notice her is how we are doing :

    "nums[start - 1] * nums[i] * nums[end + 1]" 

        instead of 

    "nums[i - 1] * nums[i] * nums[i + 1]"

so if were to go top down which meaning checking which would be the best ballon to burst the 2nd part would have been correct,
but we are going bottom up and we have already buirsted the ballons we are check which ballon would be the most suitable burst
in that case 2st part is correct 

please understand this peoblem more by using Decision tree method

*/

class Solution {
public:
    int solvewithMem(vector<int>& nums, int start, int end,
                     vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int coin = INT_MIN;
        for (int i = start; i <= end; i++) {
            coin = max(coin, nums[start - 1] * nums[i] * nums[end + 1] +
                                 solvewithMem(nums, start, i - 1, dp) +
                                 solvewithMem(nums, i + 1, end, dp));
        }
        return dp[start][end] = coin;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return solvewithMem(nums, 1, nums.size() - 2, dp);
    }
};