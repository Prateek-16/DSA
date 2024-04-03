//https://leetcode.com/problems/spiral-matrix/description/


/*

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

    1 2 3   Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    4 5 6
    7 8 9   Output: [1,2,3,6,9,8,7,4,5]

*/


/*

Approach - So we need to print in spiral order 
to do so we will take some variables :
    1. first row
    2. first column
    3. last row
    4. last column
    5. Total number of elements in the matrix ((last column + 1) * (last row + 1)).

while loop until number of elements is 0 
    1. first itrate on the first row ( left to right ) :
        for i = first column to i = last column  && total elements > 0 :
            matrix[firstrow][i]
            total elements --

    once first row is completed make sure to increase the level of firstrow for next itration
    firstRow++

    2. Now itrate on last column ( top to bottom ):
        for i = first row to i = last row && total elements > 0 :
            matrix[i][last column]
            total elements --
        
    Once complete decrease Last column for next itration
    LastColoumn--

    3. Now itrate on Last Row ( right to left ):
        for i = last column to i = first column && total elements > 0 :
            matrix[last Row][i]
            total elements --

    Once complete , decreament Last Row for next itration
    last row --

    4. Now itrate on first column ( bottom to top )
        for i = last row to i = first row && total elements > 0 :
            matrix[i][first column] 
            total elements --


Following this order will return the spiral order print of the last column
*/