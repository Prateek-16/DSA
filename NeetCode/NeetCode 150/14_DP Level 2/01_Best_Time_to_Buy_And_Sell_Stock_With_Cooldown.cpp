//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/


/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
*/


/*
Approach - Okay so lets visualize this problem in form of a tree, where each branch will be the possible decison we can take

Once lets understand the requirements :
    1. We can only sell a stock if we have previously bought the stock.
    2. Once we sell the stock we have a cooldown period where cant buy another stock for a day.

So we will need a boolean varible called Can_buy which will tell if we can buy the current stock or not. intially it will be true.

Lets visualize this problem :
    1. At the start profit is 0 and we can buy the stock, so we have 2 options at this step :
        either buy the stock or not buy the stock and move to next step.

        so profit for current step if :
            1. we buy the stock : profit = recurive call(index + 1 , !Can_buy) - nums[index]    //since we are buying we will loose the profit.
            2. we dont buy the stock : profit = recurive call(index + 1 , Can_buy)  //No loss, since we dont buy the stock

    2. At next step we can either sell the stock or do nothing ( for the recusive call made by 1.1 ) or we can buy the stock or do nothing ( for the recusive call made by 1.2 )
    this is like a tree structure with each node having 2 branches or possiblities.

        when we sell the stock :
            profit = recurive call(index + 2 , !Can_sell) + nums[index] //since we are selling we will add the profit
            also notice that we are doing index + 2 , this is done to consider the 1 day cooldown period after we sell the stock

    This is how this code works !


FLow : 
    1. Intializes the Can_buy = true and a 2d DP [prices.size()][2] initially at -1.
    2. call int solve function ( prices, can_buy, index, dp)

        //Check for Base Case :
        1. if index is our of range : return 0;

        //Check for DP case :
        2. if dp[index][can_buy] != -1 : return dp[index][can_buy];

        //Main Case :
        if(can_buy){
            //Buy
            Buy_case = solve(!can_buy, index + 1) - prices[index]
            Leave_case = solve(can_buy, index + 1)
            dp[index][can_buy] = max (buy_case, leave_case)
        }
        else{
            //sell
            sell_case = solve(!can_buy, index + 2) + prices[index]
            Leave_case = solve(can_buy, index + 1)
            dp[index][can_buy] = max (sell_case, leave_case)
        }
        
        return dp[index][can_buy]

*/