//https://leetcode.com/problems/binary-tree-level-order-traversal/description/

/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
*/

/*
Approach - So to solve this problem we need to do BFS traversal on the tree
1. if the root is null , return empty vector.
2. Make a queue and push root node into the queue. 
3. Then until the queue is empty:
    1. Make a Temp vector and loop for the size of the queue
    2. Inside the loop, push all the nodes -> val in the temp vector, and push any left and right nodes in the queue.
    3. once the inner for loop ends, push the temp vector into the final answer vector, beacuse the temp vector will contain all the nodes of the current level
4. Once the otter while loop ends, then whole tree would have been traversed.
*/