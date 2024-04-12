//https://leetcode.com/problems/unique-paths/description/


/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/


/*
Approach - so we only have 2 directions to move right and down 
so create a function solve with inputs : i , j , m , n , dp
i and j are the current indexes and m and n are the total rows and columns

BASE CASE : if (i == m -1) & (j == n -1) , return 1...
    if (i >= m) || (j >= n) , return 0... ( out of index )

Check DP : if(dp[i][j] = -1) , return dp[i][j];

MAIN BODY : else {
            return ( ans from i+1 ) + ( ans from j+1) [Moving to right and bottom once]
}

Since only right and bottom motion are allowed there is no case for overlapping so no need to backtrack
*/