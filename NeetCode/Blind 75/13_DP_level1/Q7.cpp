//https://leetcode.com/problems/coin-change/description/


/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
*/


/*

Approach - We have a set of coin and a total amount and we need to make that amount using minimum number of coins.
So include and exclude approach hogi here...
1. Function solve : attributes (array of coins, amount , dp )

    Step 1. base case : if amount is 0 return 0
    Step 2. 2 variables 1. ans (stores the number of coins)
                        2. mini (stores the minimum of all mini's)

    Step 3. Now loop over all coins in the given set :
        if for any coin, value <= amount, consider that coin
            means : store next_rec_ans = solve( amount - coin value , array of coins, dp )
            if this next_rec_ans is not INT_MAX :
                then ans = 1 + next_rec_ans ( 1 is for current coin )
    Step 4. After each itration in the for loop, we need to minimize the coins so :
        mini = minimum of ( ans , mini )

    Step 5. return mini

    step 6. dp array mentain bhi karte chalna repeating subproblems hai
           
*/