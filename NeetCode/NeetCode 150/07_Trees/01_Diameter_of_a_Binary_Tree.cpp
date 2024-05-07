//https://leetcode.com/problems/diameter-of-binary-tree/description/


/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
*/


/*
Approach - Diameter of a Binary Tree is the length of the longest path, where root node may or may not pass through
Simple Appraoch - 
    1. root Node ke liye, uske right side ka max distance le auo and left side ka max distance le auo, then 
    dono ko add karke + 1 kardo , woh root node ke liye max diameter hoga,

    but we know rthat root node may or may not be included, so yahi cheez sari m=ndoes ke liye kare and max ko ek varibale mai store kara lena, and return at last
    sare node ke lye karne ke lye hume traverse karn apadhega, to preorder traver kar lo

But is Approach mai Multiple Recursive call hori hai , and bahut jayada time complexity hai

So Max Distance wale function mai chote se changes akrenge :
    1. Hum kya kar rahe the , left and right ki max depth la rahe the and then diameter find find kar hare the current node ke lye and yahi kaam har node ke lye kar rahe the
    instead of this,  Max Distance wale function mai chote se changes akrenge

    Kisi bhi node ka max distance kase niklega ? jab hum uska left and right distance m=nikalenge and dono mai se jo max hoga usme + 1 karke return kar denge
    but agar hum max distance function mai hi node ka left and right distance find kar rahe hai toh indono ko add karke hume diameter bhi toh mil sakta hai,
    and max diameter ko ek global variable mai store kara lenge
    

    Thats it !!
*/