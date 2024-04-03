//https://leetcode.com/problems/reorder-list/description/

/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]
*/

/*
Approach - we will do this by finding the middle,and there reversing the list after the middle, then its just merging 2 linked list
1. used slow and fast pointer to find the middle at slow pointer but also mentain a prev pointer which stay one node behind slow.
2. set prev -> next = NULL ( to seperate the list in to 2 parts)
3. then the slow pointer will act as head of another linked list,
   now using the slow as head reverse this list ( using 3 pointer prev , curr , next).
4. Now merge these 2 list l1 and l2 such that l1[first] -> l2[first] -> l1[second] -> l2[second]..and so on
*/