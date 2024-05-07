//https://leetcode.com/problems/binary-tree-right-side-view/description/


/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
*/


/*
Approach - we Know that at each level of the tree we will only have one node as the right side view, we can use this information to determine the right side view
we will use a empty vector to store the right side view and a level variable which is initially 0

whenever level and right side view vectors will be of the same size,that means we are on the same level and the value for this level is not yet stored.
also we will traverse the tree tree such that we will first cover the right values only, so then we will add the current node value to the vector

then we will do recursive calls to right node and left nodes, also increase the level by +1 

we should also remember that right recursive call will be above the left call beacuse, we need the right side view

when we need to left side view, the left would be ablove right
*/