//https://leetcode.com/problems/word-search/description/

/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/


/*
Approach - Bruce force approach 

1. loops to reach each cell of the grid ( 2 for loops )
2. Check if the current cell character is equal to the first character of our word
    if true then call the function dfs

bool function dfs Inputs : grid, total row and col, current cell i and j , word , index ( for itratin gon the word )

    base case : 
        check if i and j out of bounds using row and col or if grid[i][j] != word[index]
            if true then return false

    
    since we are here we can say that the grid[i][j] == word[index] so if index is the last of word then we can return true
    we also do this to avoid out of bound errors

    if index is not last we need to do recursive calls for the next index but before that
    we will do grid[i][j] = "#"     (so that we dont come back to this already traversed index we can also do this using a visited grid)
    recursive calls in all 4 directions with index + 1
    backtrack so grid[i][j] = word[index]   (restoring the character)
*/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, int row,int col) {
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[index] ) {
            return false;
        }
        if (index == word.length() - 1) {
            return true;
        }

        board[i][j] = '#';
        if (dfs(board, word, index + 1, i - 1, j, row, col) ||
            dfs(board, word, index + 1, i + 1, j, row, col) ||
            dfs(board, word, index + 1, i, j - 1, row, col) ||
            dfs(board, word, index + 1, i, j + 1, row, col)) {
            return true;
        }
        board[i][j] = word[index];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};