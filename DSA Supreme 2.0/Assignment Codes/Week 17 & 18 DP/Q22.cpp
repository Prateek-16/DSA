//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/


//Best Time to Buy and Sell Stock with Transaction Fee


/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

*/

/*
Approach - Since we can engage in multiple transactions this question is similar to Buy and sell stock 2.
but here we have a transaction fee and we need to pay the transaction fee when we sell stock.
so we can simply deduct the transaction fee on selling the stock.
*/

class Solution {
public:
    int solvewithMem(vector<int>& prices, int index, bool buy,vector<vector<int>>&dp,int fee) {
        if (index >= prices.size()) {
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if (buy) {
            int buyProfit = solvewithMem(prices, index, 0,dp,fee) - prices[index];
            int skipProfit = solvewithMem(prices, index + 1, 1,dp,fee);
            profit = max(buyProfit, skipProfit);
        } else {
            int sellProfit = prices[index] + solvewithMem(prices, index + 1, 1,dp,fee) - fee;
            int SkipProfit = solvewithMem(prices, index + 1, 0,dp,fee);
            profit = max(sellProfit, SkipProfit);
        }
        return dp[index][buy] = profit;
    }
    int solvewithTab(vector<int>&prices,int fee){
        vector<vector<int>>dp(prices.size()+1 , vector<int>(2,0));
        for(int index = prices.size()-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if (buy) {
                    int buyProfit = dp[index][0] - prices[index];
                    int skipProfit = dp[index+1][1];
                    profit = max(buyProfit, skipProfit);
                } else {
                    int sellProfit = prices[index] + dp[index+1][1] - fee;
                    int SkipProfit = dp[index+1][0];
                    profit = max(sellProfit, SkipProfit);
                }
                dp[index][buy] = profit;

            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>>dp(prices.size()+1 , vector<int>(2,-1));
        // return solvewithMem(prices,0,1,dp,fee);
        return solvewithTab(prices,fee);
    }
};