//https://leetcode.com/problems/subsets/description/


/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/


/*
Approach - So the Solution is simple and will be used regularly
in these types of question where you want to find all possible combinations we generally use Backtracking approach

How this works is :
    we want to find the powerset to do so we will make combinations of each element with some other elements 
    for eg : 1 will combine with 2 , 3 and then this comined form will conbine with next elements

    so this is how the solution is formed

    what we do is take a index "i" then from that index we will loop from i to the end()
    inside the loop we check for duplicates ie if i and i-1 are same, 
    if they are then we continue that case we actually dont need this case here because the constraint is that there will be not duplicates, but just mentioning here 

    if not, then add the ith element to the vector of current elements then
    do recursive call to the next itrative index, this call will further form the combinations of the current elements
    after the recursive call, we need to backtrack and remove the ith element from the current vector

    for eg we have [1,2,3] so lets say we have [1] in the current vector and then we loop over [2,3] and insert them into the current vector one by one like
    [1,2] and then [1,3] to do so we need to backtrack and remove the ith element for next iteration
*/