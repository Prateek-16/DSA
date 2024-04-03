//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” 

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

/*
Approach - So we have 2 approachs one recursive and one itrative

Recursive approach
1. so we know that this is a BST, so we can use the preoperty of a BST that on left we have all smaller elements and on right we have all greater elements.
2. if both P and Q are smaller then the root node the Do recursive call on the left of the root node.
3. if both P and Q are greater then the root node the Do recursive call on the right of the root node.
4. if botth the conditions are not true then that means that One is smaller than the other greater than the root node, so in this case we return the root node.

Itrative approach
1. it will have the same conditions : 
    1. if both P and Q are smaller then the root node the do itrative shift to root -> left.
    2. if both P and Q are greater then the root node the do itrative shift to root -> right.
    3. if none of the conditions are true then that means that one is smaller than the other greater than the root node, so in this case we return the root node.
*/