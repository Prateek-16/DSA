//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/


/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
*/


/*
Approach - Toh simple question hai longest increasing path find karna hai ?
toh maine kya bola 2 for loops lagao and har index par jao... and ek function call kar dena solve jisse pata chalega ki is index par maximum incresing path kya hoga

also ek 2D DP bana lena

So lets write this function :
    solvewithMem ( i , j , matrix , dp )
    //Base Case :
        if i is less than 0 or greater than matrix.size() or j is less than 0 or greater than matrix[0].size()
        then return 0 because indexes are out of bounds.

    //DP check :
        if dp[i][j] != -1 , then return dp[i][j]
    
    //Main Case :
        make a vector of pair indices {0,1} {0,-1} {1,0} {-1,0} ... right left bottom top
        make a variable called max length = 1
        now loop 4 time :
            find new i and new j 
            new i = i + indices[it]
            new j = j + indices[it]

            now check if these new indices are in bound of matrix and also matrix[new i][new j] is greater than matrix[i][j]
            if true then :
                max_length = max(max_length, 1 + solve(new i, new j))
        
        now save max length in dp[i][j] and also return it...

*/ 