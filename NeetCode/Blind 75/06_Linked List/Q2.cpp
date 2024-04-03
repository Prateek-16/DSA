//https://leetcode.com/problems/merge-two-sorted-lists/description/

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
*/

/*
Approach - Simple 2 pointer approach to merge two lists
1. set a pointer on head1 and another on head2
2. compare p1 and p2 and set the smaller as newHead and move the pointer one point ahead for that pointer
3. until any one pointer is null:
    compare p1 and p2 and keep linking the smaller one to a temp pointer which will itrate on newHead.
4. Once one pointer reaches null itrate until other is also null and link all the elements
*/