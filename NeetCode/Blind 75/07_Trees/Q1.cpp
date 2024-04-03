//https://leetcode.com/problems/invert-binary-tree/description/

/*
Given the root of a binary tree, invert the tree, and return its root.

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []
*/

/*
Approach - To invert a binary tree we need to swap its left and right nodes
2. we will simply do this with recursion, we will go at each level and then get its left and right tree with recursion,
   then we will connect the left tree with the right pointer and the right tree with the left pointer.
3. Base case will be if the node is null return null
*/
