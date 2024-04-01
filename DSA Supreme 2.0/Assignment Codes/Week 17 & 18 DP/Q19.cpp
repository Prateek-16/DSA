//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/


//Best Time to Buy and Sell Stock II


/*
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/


/*
Approach - so there are itrative approaches also but here we will be using DP + Rec so how to do this question ?
we can perform multiple buy and sell but the condition is that we much buy before we sell 
so we will use a boolean variable which will tell us if we need to buy or sell

if BUY - if we are buying we will subtract the buying cost from the Recursive answer from index + 1 , because when we buy we loose the money
our 2nd case will be to skip that day and simplly move index + 1

then choose the max of the 2 .

if SELL - if we are selling we will add on the profit or the price for the current index on the recursive answer  than we gain from index + 1
or we can skip that day

then choose the max of the 2

so this is how we will solve this question:

also during buy : if we are choosing to buy the current stock we need not to give the recursive call to index + 1 beacuse the question says we can buy and sell on the same day

*/


class Solution {
public:
    int solvewithMem(vector<int>& prices, int index, bool buy,vector<vector<int>>&dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if (buy) {
            int buyProfit = solvewithMem(prices, index, 0,dp) - prices[index];
            int skipProfit = solvewithMem(prices, index + 1, 1,dp);
            profit = max(buyProfit, skipProfit);
        } else {
            int sellProfit = prices[index] + solvewithMem(prices, index + 1, 1,dp);
            int SkipProfit = solvewithMem(prices, index + 1, 0,dp);
            profit = max(sellProfit, SkipProfit);
        }
        return dp[index][buy] = profit;
    }
    int solvewithTab(vector<int>&prices){
        vector<vector<int>>dp(prices.size()+1 , vector<int>(2,0));
        for(int index = prices.size()-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if (buy) {
                    int buyProfit = dp[index][0] - prices[index];
                    int skipProfit = dp[index+1][1];
                    profit = max(buyProfit, skipProfit);
                } else {
                    int sellProfit = prices[index] + dp[index+1][1];
                    int SkipProfit = dp[index+1][0];
                    profit = max(sellProfit, SkipProfit);
                }
                dp[index][buy] = profit;

            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) { 
        // vector<vector<int>>dp(prices.size()+1 , vector<int>(2,-1));
        // return solvewithMem(prices, 0, 1,dp);
        return solvewithTab(prices);
    }
};