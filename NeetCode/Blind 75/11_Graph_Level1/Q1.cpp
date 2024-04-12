//https://leetcode.com/problems/number-of-islands/description/


/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/


/*
Appraoch - So simple hai question :
    step 1 : make a map vis <pair<int,int>,bool> also make a count variable
    step 2 : Loop over each index in the grid
    step 3 : if for any x , y :
            grid[x][y] = '1' && vis[x][y] = false
            call bfs(x,y,grid,vis)
            count++;
    step 4 : return count 

BFS function input : x , y, grid , vis 

    this function will do bfs traversal on all the connected land from index x , y
    and will mark all those indexes as visited

    This is a simple BFS traversal where :
        1. initialise a queue for <int,int>
        2. enter the src x and src y in the queue
        3. mark them as visited
        4. while ( q is not empty )
            1. get front element
            2. pop the queue
            3. now check in all 4 derections of the current x , y if its possible to move 
                for that call check function
            4. if check function is true : push the new index in the queue and mark the new index as visited
        
Check function inputs : x , y , grid , visited , m , n 
    1. This function will check we index x , y is safe to move or not
        conditions : 
            1. out of bound conditions
            2. grid[x][y] == '1'
            3. vis[x][y] == false
            If all true then return true,
            else return false
*/