//https://leetcode.com/problems/same-tree/description/

/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false
*/

/*
Approach - So if we want to compare two trees are the same or not, we need to check if they are structurally identical and have same value.
1. Check if root1 -> val && root2 -> val is NULL
    if true then return true;
2. check if root1 -> val is NULL || root2 -> val is NULL
    if true then this means :: 
        since maira and wala case nahi chala that means either koi ek not null hai ya dono, so or wale case se woh check ho jaega
        if true then one is not null and other is null SO RETURN FALSE
3. till now we have checked for root being null now compare root data:
    if root1-> val == root2-> val then :
        find bools for root -> left and right
        return and of left and right ( this means that if both left and right are true then only we will return true)
    else :
        this condition means that root1-> val != root2-> val hence return false
*/