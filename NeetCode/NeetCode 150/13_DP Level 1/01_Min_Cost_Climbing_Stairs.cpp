// https://leetcode.com/problems/min-cost-climbing-stairs/description/

/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/

/*
Approach - So we will write a function to find the cost and then run that function from 2 indexes ie 0 and 1 and return the minimum

Recursive approach :
    1. Base Case : if index is outside the cost array return 0

    2. Main Case : get the answer for 1 jump index + 1 and for 2 jump index + 2 using recursion and store then seperately
        return the minimum of the 2 with added current cost

Memoisation :
    1. Simply use a 1D Dp to store the current cost for each indexes
    2. if for any index the cost is not -1, then it must have been previously calculated so return it

Tabulation :
    1. Create a DP vector of size cost array + 1 and all values being 0.
    2. Initialise the Base Case :
        1. size DP is of size cost array + 1 let the last index be already 0, beacause we want to reach the end with minimum cost and if we are already at the end the cost will be 0
    3. Loop from cost array size - 1 to 0 :
        now we need to build the answer for this index using the already filled indexes.
        so this index depends on index + 1 and index + 2 :
        so simply check if index + 1 exist in the DP :
            if it does the then store its answer, otherwise let it be 0
        check if index + 2 exist in the DP :
            if it does the then store its answer, otherwise let it be 0

        Now store the minimum of both + 1 and + 2 in current index with added cost of cost[index]

    4. At end return the min of index 1 or index 0
*/
