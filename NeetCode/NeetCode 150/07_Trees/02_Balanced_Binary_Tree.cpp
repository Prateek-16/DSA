//https://leetcode.com/problems/balanced-binary-tree/description/


/*
Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
*/


/*
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

So we need to find the left and right depth and it should not be more than one
So make a global flag variable which is initially true, but will turn false when the tree is not balanced

We know the function of Max Depth, which finds the maximum depth for each Node, Inside that Funcgtion only we can if the tree is balanced of not
    if abs(right_height - left_height) > 1 , then tree is not balanced, so change the flag to false

at the end after the max depth function return the flag
*/