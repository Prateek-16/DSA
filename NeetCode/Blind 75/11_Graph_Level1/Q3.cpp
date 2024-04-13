//https://leetcode.com/problems/pacific-atlantic-water-flow/description/


/*

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

*/


/*
Approach - Basically we have a grid which has pasific ocean on its top and left and atlantic ocean on its bottom and right
grid has m rows and n cols with each block having its own height and water can flow from higher to lower level or equal levels

we need to tell from with blocks can the water flow to both pasific and atlantic ocean

Simple Approach - 1. Go to every index i , j in the grid and make a dfs call
2. if we can reach to both pasific and atlantic oceans ( borders ) add the indexes i , j to a final answer vector

3. This is a time heavy approach with TC : O(m.n)^2

A simple change to this can bring down the complexity significantly

Change is : instead of moving from each blocks to the ocean , moving from the ocean towards each block
    in this was the we will only traverse a block once ( visited concept ) and will reduce the complexity to : O(m.n)

Better Approach -  1. Make 2 boolean vectors named altantic and passific
2. these vector will store true if water from a block can reach the specific ocean
3. Then we will loop over them and for the cases where both altantic[i][j] and passific[i][j] is true , we store the block i, j in a answer vector

How to traverse : 
    DFS traversal : for Passific : we know it covers top and left ,
                                    so all the blocks of the top and left will be called for dfs 
                                    then from those blocks if we can reach a neibouring block of height > = to current block and visited is false
                                        we will the call for that new block
                                in this way we will do a dfs traversal for the whole grid 
                    for atlantic : we know it covers bottom and right ,
                                    so all the blocks of right and bottom will be called for dfs
                                    then we will do similar dfs as above

This is How we can solve this problem efficiently
                                    
*/