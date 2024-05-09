//https://leetcode.com/problems/n-queens/description/


/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
*/


/*
Approach - So we need to place the queens in a n*n board

    How we are approaching this question is we will fix the coloumns before hand only, like indexes
    and for each index which is the column we will figure out a row where we can place the queen

    Thats a very raw explanation of the problem

    Lets understand the problem more :
        so what we will do is mentain 3 vectors 1. horizontal 2. diagonal up 3. diagonal down
        these three vectors will be used to find if there is a queen which already exist in diagonal or the row or not

        So how we are solving the problem is :
            we will start from column 0 :
                we will loop on all the rows in that column (input ie index)
                then for each set of row and column we will check if we can place the queen there or not
                if we can place the queen then we will place the queen mark it in the 3 vectors (will tell how) and move on to the next column ie index

            So how will we check if we can place the queen at a given row and column or not ?
                so since we will be moving coloumn by column we alreay know that each column will have only 1 queen so we need not check the same column
                but we need to check the Horizontal Row and the diagonals ( up and down )

                How can we check the horizontal row ?
                suppose whenever we place the queen at some row and column we take that row index and mark it as 1 in a vector called horizontal
                this vector horizontal will contain the rows indexes where there is a queen as 1 and rest as 0
                so we can check the row index in this vector if its 1 or 0 and know if we are safe horizontally

                Now Diagonals :
                    there are 2 types of diagonal upward diagonal and downward diagonal.
                    also remember since we are moving coloumn by column to place the queens we need to only check the diagonal behind our current index we need not need to go to next columns ie indexes

                    downward diagonal :
                    this is simple : we can visually observe that downwards diagonally thr sum of row and column is always equal
                    so i can mentain a vector for this and suppose i am placing a queen at m,n indexes so i can mark the downward diagonal[m+n] as 1 so we know for all other elements downwards that there is already a queen in this diagonal.
                    and there can be only 1 queen in a diagonal

                    Upward diagonal :
                    This is a bit tricky : so the thing is for upward diagonal the difference of coloumn index - row index is same for the whole diagonal
                    by subtracting can make the indexes negative so we need to do index shifting by n-1

                    so for upward diagonal we will set upward diagonal[column index - row index + n - 1] as 1 so that whole diagonal knows that this diagonal is occupied by queen

                    So this is how we will check if that row , column index is safe for the queen or not
                    if its safe the we will mark the queen on the board and also mark it in the 3 vectors
                    once done we will do recursive calls for the next index or coloumn
                    then we will backtrack is remove the queen from that row index and select some other possibile row index
                    
*/