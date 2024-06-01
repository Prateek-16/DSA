//https://leetcode.com/problems/coin-change-ii/description/


/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
*/


/*
Approach (simple recursion + memoisation):
    1. so the main thing is see is we can use one coin infinate number of times so one thins is clear that when we do recursive calls we should not increase the index
    so how to design the solution :
        // Base case : if out of index return 0 or we will figure something for amount == 0 and amount < 0 also
        // DP check 
        // Main case :
        since we can take any number of coins and that too any one of them we definatly have to use a for loop over the coins vector
        so loop from i = index to end 
            in the loop we will add all the answers from recursive calls 
            but how to make these calls ?
            recursive call = for ith itration we call the recursion at index = i and subtract coins[i] from amount

            Now why we sending index as i and not the same as above index 
            lets see : suppose coins = [1,2,5] & amount = 5
            what are the ways we can make these 1 , 2 , 2 or 2 , 1 , 2 or 2 , 2 , 1
            so all these 3 are the same entries so all these will return a + 1 ans so we want to avoid that : how can we do that ?
            one way is to store this complete path in a set in a ordered manner and the search the set if the current combination already exist in the set or not

            but this is ot effective so better thing to do is suppose when we call for 1 , 2 , 2 then we move on to 2's combinations we should make sure than we dont search backwards to form any combinations
            because if there does exist a combination if would have been already considered by previous combination
            so when searching for 2's combinations we cant take 1 in the set similarly we cant include 1 and 2 in the set combinations of 3


Flow : 
    1. make a dp for coin.size() to amount 
    2. call a solve function 

    3. int solve ( coins , index , amount , dp )
        //BASE CASE 1 
        index out of bound or amount < 0 : return 0 

        //BASE CASE 2
        amount == 0 : return 1

        //DP CHECK
        if dp[index][amount] != - 1 : return dp[index][amount]

        //MAIN CASE :
        loop from i = index to i < coins.size() 
            for each index i add its recursive answer to a variable let say ans

            ans + = recursive calls ie solve ( coins , i , amount - coins[i] , dp )     //Hope you understand why we send i at index , to avoid duplicates

        After Loop ends 
        return dp[index][amount] = ans

        
*/