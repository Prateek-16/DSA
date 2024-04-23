//https://leetcode.com/problems/valid-sudoku/description/


/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/


/*
Approach - Only 3 conditions are needed :
    1. no same in one row
    2. no same in one column
    3. No same in one small 3X3 sub-box

    We will use a hashmap to check the condition
    1. simply do using 2 for loops outter on rows and inner on cols 
        create a map for each new row and check if there is any repetition then return false
    2. Simply do using 2 for loops outter on cols and inner on rows
        create a map for each new col and check if there is any repetition then return false
    3. Bit tricky
    Simply treat each 3*3 grid as a single block and loop over these blocks (by skipping rows and cols 3 times)
        then get values of starting row , starting column , ending row and ending column and call a function
        which will return if the block (3 * 3)  is valid or not


    Iska a Optimised Solution bhi hai , but woh mujhe samaj nahi aya
     
*/