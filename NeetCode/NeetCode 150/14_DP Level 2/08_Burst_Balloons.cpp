//https://leetcode.com/problems/burst-balloons/description/


/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/


/*
Approach - Okay so this is a bit different problem...
    what we want to do here is not build a solution like 1st balloon to burst then 2nd to burst then 3rd and so on...


    Because if we do so we no longer will have independent subproblems for the bigger problem what that means is :
        lets say [3,1,5,8] --> we burst ballon 1 that ie - 3*1*5 + ans of left subarray + ans of right subarray

        but the problem is that the left and the right subarray are not independent because once we burst 1 the array becomes [3,5,8]
        so the 5 in the right subarray depends on 3 which is in the left subarray and thus we dont have indepent sub problems to work with

    so we cant do this by top down approach...

    lets think of another way that is which will be the last ballon to get burst ?
    so lets say input is [3,1,5,8] and we add 1 on both ends for simplicity so array becomes [1,3,1,5,8,1]
    now our start is at index (1) and end is at index (n-2)

    now between this start to end we want to find which ballon will we burst the last (actually we have to itratively consider all one by one)
    but lets say we burst 5 at the last.

    so what do you think will be on the right and left of 8 when we burst that ballon at last , i think it will be like this [1,5,1]
    ie nums[start - 1] * nums[i] * nums[end + 1]    where i is the current possible last burst ballon
    okay so this was the 1st step now we need recursive calls

    so if ballon 5 is getting burst at the last we can say that it will definately be present is a step before like [1,x,5,1].

    so to find that we will do 2 recursive calls one on the left and another on the right ie : solve( start , i-1 ) & solve( i+1 , end )

    so how this will look is :
    if 5 is the last balloon to burst then nums[start - 1] * nums[i] * nums[end + 1] + solve( start , i-1 ) + solve( i+1 , end )
    where i is the index of 5.


    so now why solve( start , i-1 ) + solve( i+1 , end ) are indepent calls ? 
    lets see we know for sure that ith index is of 5 which is definately present in the array for upper recursive calls, since we burst it as last balloon
    so i-1 and i+1 both depend on a constant which is 5 and it does not belong to any of the other recursive calls. that is why we know that its independent subproblems


    SO NOW LETS THINK OF THE WHOLE FLOW OF THE PROGRAM :
    given : an nums array 
    return : maximum coins ie a integer

    1. Add 1 on the start of the array and the end of the array.
    2. intialize start at 1 and end at n-2.
    3. make a 2D DP for 2 varibales which are actually changing ie start and end. both of size n (can be before the additon of 1s or after)

    3. int solve function call (nums , start , end , dp)

        //Base Case 
        if start > end :
            return 0;
        
        //DP check 
        if DP[start][end] != -1
            return DP[start][end];

        //Main Case 
        //what we do here is consider each balloon between start and end as the last burst balloon

        let coin = INT_MIN  //since we will maximize this number

        loop from i = start to i = end
            //coin will hold the maximum value out of all the iterations.

            coin = max( coin , nums[start]*nums[i]*nums[end] + solve(nums,start,end,dp) + solve(nums,start,end,dp) )
        
            // its important to understand why we are doing nums[start]*nums[i]*nums[end] and not nums[i-1]*nums[i]*nums[i+1].
            // it is because we considering ith balloon as the last balloon to be burst in the range start to end so only start -1 and end + 1 will be its neighbouring balloons
        
        after the loop we store the coin value in dp[start][end]
        then return dp[start][end]
*/