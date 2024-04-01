// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/


//Best Time to Buy and Sell Stock III


/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, 
as you are engaging multiple transactions at the same time. You must sell before buying again.

*/


/*
Approach - The Approach for this question is similar to previous one where we can do multiple transactaions but,
we need to complete one before starting another so we need to mentain a buy variable which tell us if we need to buy the stcok or sell it.

but adiitionally in this question we can only do 2 transactions so we will simply send a variable called limit and then,
after each sell we will decrease the limit by one and when limit reaches zero we will return 0 and stop.

this was the main crux of the approach

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

    int solvewithTab(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int limit=1;limit<3;limit++ ) {
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
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(
        //     prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // return solvewithMem(prices, 0, 1, dp, 2);
        return solvewithTab(prices);
    }
};