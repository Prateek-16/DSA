//https://leetcode.com/problems/reverse-linked-list/description/

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

/*
Approach - 2 Ways Irative and Recursive

Itrative 

1. In itrative way we need to set 3 pointers prev curr and nextNode
2. itrate until Curr is NULL
    we will do :
        1. nextNode = curr -> next 
        2. curr -> next = prev
        3. prev = curr
        4.curr = nextNode
3. return prev

Recursive 
1. if head or head next is null : 
    return head
2. store the recursive solution of head->next in a pointer object NewHead
3. then do :
    head->next->next = head
    head->next = null

4. return NewHead
*/