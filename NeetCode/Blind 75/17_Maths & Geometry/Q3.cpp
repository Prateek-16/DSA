//https://leetcode.com/problems/set-matrix-zeroes/description/


/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

/*
Approach - For inplace consider the first row and the first column of the matrix are a marker
and for the first coloumn set marker as a individual variable col0 to avoid overlap at 0,0

Now loop on the martix :
    1. if at any index i,j there is a 0 :
        so set row marker [i][0] as 0
        and set col marker [0][j] is 0 
        for seting the col marker check if the col j == 0
        if true then set col0 variable as 0 instead

    2. Now Loop from 1,1 to end
        and see if for any i,j the rowmarker or coloumn marker is marked as 0
        if true then :
            mark the i,j index also as 0
    
    3. Now Set the Row Marker and Column Marker
        if col0 is 0 : then set the whole row marker as 0
        if martix [0][0] is 0 : then set whole col marker as 0
*/