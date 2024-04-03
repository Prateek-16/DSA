//https://leetcode.com/problems/merge-k-sorted-lists/description/

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/

/*
Approach - There is a Heap based solution of this problem but we will solve it with linked lists only.

Approach 2:
1. we know the merge 2 list function where we use 2 pointers for merging.
2. now we need to merge K sorted list so we can use the exact same function for merging.
3. But instead of randomly merging linked list serially using a single loop, we will merge differently
4. so normal merging will be to merge 1st and 2nd then merge the result with 3rd then the result with 4th and so on.
    but this solution will take O(n*k) TC instead what we can do is :

5. we can merge 1st and 2nd and then merge 3rd with 4rd then 5th with 6th and so on.
    then merge the result of 1,2 with the result of 3,4 and so on.
    in this way we will do O(n) merge logK time, so TC will be O(nlogK).

6. This solution is taught by Neetcode. 
*/