//https://leetcode.com/problems/word-search-ii/description/


/*

Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Example 1:

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:

Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

*/


/*
Approach - 

Step 1 - form a trie DS of the given input words
Step 2 - Itrate over all the indexes in the grid and search

Function Search :
    inputs - grid , index i and j , number of row and cols , root node of trie , empty string word , vector string ans

    working -   1. first check for out of bounds indexes and revisiting same index ( grid[i][j] == '#' )
                if true return;
                2.  Now for the current character at i , j find if this exists in root's children
                    if not return
                    if true then add the character in the word string & check if its the last character 
                        if its the last then push the word into the answer vector and mark it not last
                        we will mark the last character as not last, to avoid same copies of the word
                    then move node to the child node
                3. Now change the index character to '#' to avoid revisiting same index
                4. Do recursive calls in all 4 directiond from that index to search the word further
                5. change the index character back to ch (stored earlier)
*/