//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head. 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

/*
Approach 1 :
1. Get the length of whole LinkedList
2. subract n from total length and store in a variable count
3. if count is 0 :
    then return head->next ( means we will remove 1st element)
4. otherwise return set 2 pointers prev and curr and itrate over LL until count is 0
5. Now we are at the position where we need to delete the curr node element so simply,
    point prev -> next to curr ->next and deleete curr

Approach 2 :
1. set 2 pointers at the start and Move fast pointer until n is 0
2. if fast is at null then return head -> next
3. otherwise until fast is not null move slow and fast
4. Now our slow pointer will be at a prev position from the nth node from end , so we need to delete the next element
5. simply do slow -> next = slow-> next -> next

*/