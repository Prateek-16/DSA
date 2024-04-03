//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
*/

/*
Approach - We Know that this is a BST so the inorder traversal will be sorted and the kth smallest value willl be the kth value from the start.
1. so the naive approach will be to calculate the complete inorder traversal then find the kth smallest value.

BUT whats better is to keep a track of the kth smallest value along with calcualting the inorder.
2. so inorder means LNR:
    if root is null return -1;
    1. process root left and store the result. If the result is not -1 return it.
    2. process the current node by reducing k by 1 and check if K is equal to 0, if true return k.
    3. now process the right node and return its result.

we can also simplify this by making a void function and passing result by reference as a argument
*/