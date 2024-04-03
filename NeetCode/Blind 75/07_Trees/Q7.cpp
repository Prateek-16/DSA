//https://leetcode.com/problems/validate-binary-search-tree/description/

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
*/

/*
Approach - So this looks like a easy problem where the first thought will be that : 
            okay lets compare the left Node value less than root and the right node value greater than root and then do recursive calls.
            but this will be wrong beacuse suppose our root is 5 and on its right is 9 so no problem here, but now the left of 9 is 3.
            so according to our algorithm there should be no problem in 9 > 3 but since we are on right side of 5 so we can not have 3 on right

so we understand that we cannot just compare the root with its left and right child we need to check that all nodes on left and right are smaller and greater respectively.

so what we can do is :
1. we can use bounds ie upperBound and lowerBound :
    1. For root the upperBound and lowerBound can be negative infinity to positive infinity.
    2. For the left of the root the upperBound and lowerBound will be negative infinity to root->val respectively.
    3. For the right of the root the upperBound and lowerBound will be root->val to positive infinity respectively.
2. and this is how we will keep on updating the upperBound and lowerBound for each node,
    and check if the node lies in the range of upperBound and lowerBound.
*/