//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/

/*
Approach - 1. So we know inorder means LNR and preorder means NLR so the top node of the preorder will be the root node.
2.  using this information what if we get the top node from the preorder and then somehow find that nodes index in the inorder,
    we will then know that all the elements on the left of the inorder or lets say the range (low to index -1) will be on the left side of the root node
    and all the elements on the right of the inorder or lets say the range (index + 1 to high) will be on the right side of the root
3.  So we will do exactly the same, we will map the inorder values to its index in the inorder.
4.  we will use a index variable which will traverse over the preorder, to find the root node value and create a new node with that value.
5.  then we locate that variable in the inorder and find its index_inorder.
6.  then we know all the elements on the left will be attached to the left of the root node.So we will do recursive call for range (low to index -1)
    and all the elements on the right will be attached to the right side of the root node.So we will do recursive call for range (index + 1 to high)
7.  at last return the root.
*/