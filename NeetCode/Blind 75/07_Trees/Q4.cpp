//https://leetcode.com/problems/subtree-of-another-tree/description/

/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
*/

/*
Approach : So the question wants us to find if the subtree is present in the main tree or not.
1. we have just done a question which compares if 2 trees are equal or not, we can use that here to see if subtree is present in the main tree
2. so we will traverse the main tree, and for each node we will check if the subtree is present or not from that node.
    if the tree matches the directly return true
3. now we will do recursive call for left and right nodes of curr Node in the main tree, and return the OR of their answers.


So basically we are traversing the main tree and the at each Node we check if the subtree is present from that node or not.

*/