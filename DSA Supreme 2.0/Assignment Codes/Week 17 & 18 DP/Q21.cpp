//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/


//Best Time to Buy and Sell Stock IV


/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
*/


/*

Approach - Similar to previous question where we have at most 2 transactions but here we have atmost k transactions,
so we need to simply change the limit from the preveious question from 2 to k.

*/

class Solution {
public:
    int solvewithMem(vector<int>& prices, int index, bool buy,
                     vector<vector<vector<int>>>& dp, int limit) {
        if (index >= prices.size() || limit <= 0) {
            return 0;
        }
        if (dp[index][buy][limit] != -1) {
            return dp[index][buy][limit];
        }
        int profit = 0;
        if (buy) {
            int buyProfit =
                solvewithMem(prices, index + 1, 0, dp, limit) - prices[index];
            int skipProfit = solvewithMem(prices, index + 1, 1, dp, limit);
            profit = max(buyProfit, skipProfit);
        } else {
            int sellProfit = prices[index] +
                             solvewithMem(prices, index + 1, 1, dp, limit - 1);
            int SkipProfit = solvewithMem(prices, index + 1, 0, dp, limit);
            profit = max(sellProfit, SkipProfit);
        }
        return dp[index][buy][limit] = profit;
    }

    int solvewithTab(vector<int>& prices,int k) {
        vector<vector<vector<int>>> dp(
            prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int limit=1;limit<k+1;limit++ ) {
                    int profit = 0;
                    if (buy) {
                        int buyProfit = dp[index + 1][0][limit] - prices[index];
                        int skipProfit =
                            dp[index+1][1][limit];
                        profit = max(buyProfit, skipProfit);
                    } else {
                        int sellProfit =
                            prices[index] +
                            dp[index+1][1][limit-1];
                        int SkipProfit =
                            dp[index+1][0][limit];
                        profit = max(sellProfit, SkipProfit);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }


    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>> dp(
        //     prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solvewithMem(prices, 0, 1, dp, k);
        return solvewithTab(prices,k);
    }
};