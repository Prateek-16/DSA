//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

*/

/*
Approach - So simple approach will be using recursion :
basically we will mentain a index pointer and increment in each recursive call and when it reaches the end that will be the base case for the recusion
for each index we will check if it is the stock is lower that day then the lowest_stock if true : then we will set the current stock as lowest and move to next index
if not the lowest stock then we will check the profit by subtracting the current price  from the proice on the lowest dat
if the difference is greater then the highest price then we will save it and call for next index.

Another approach will be using 2 pointers L and R starting from 0 and 1 index
they will loop over the array until r > size of the array
if price of left < price of right then check if the price difference is maximum 
if price of right > left then move left to right 
and in both cases do right ++;

this way we can find the best time to buy and sell
*/