//https://leetcode.com/problems/rotate-image/description/


/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/


/*
Approach - So to rotate A matrix in place we need to do 2 things :
1. Transpose the Matrix
2. Mirror the Matrix ( reverse the Matrix )

1. Transpose the matrix :
    1 1 2      1 3 5
    3 4 4  ->  1 4 4
    5 6 7      2 4 7

How to do transpose ? 
    Loop  i from 0 to N :
        inner Loop j from i to N[i].size() :
            swap (N[i][j] , N[j][i])

2. Mirror the Matrix : 
1. Loop i from 0 to N :
    for each vector ( row ) call reverse function.    
    
*/