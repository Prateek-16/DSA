//https://leetcode.com/problems/reverse-nodes-in-k-group/description/


/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/


/*
Approach - Dekho har K interval par reverse karna hai and if K se less Node Bachi ho tho Nhaai karna 

Solution : Recursive + Linked List

ISKO KARNE SE PEHELE YEH DEKH LENA KI HOW TO REVERSE A LINKED LIST

So We will write a recursive Solution : 
    Base Case 1 : IF head Reached NULL return head
    Base Case 2 : We need to reverse K node But check even if K node exist Next to Head or Not, if Not the return head without any changes

    // Main Logic For 1 Case : 
        1. Since we have At least k nodes, reverse these K nodes
        2. After Reverse :
            previous pointer will be the new Head, and
            current pointer & next pointer will be at the head of unreversed Linked List
        3. Now reverse is done , now call the recursion
        4. Before that check if current pointer or Next pointer is NULL, if Not then : 
            Do recursive call with head = current pointer or next pointer and K
            Store this recursive ans in a ListNode pointer
        5. Now we need to attach this answer to over reversed Linked List
        6. Attach this recursive answer to the original Head->next 
        7. Return previous pointer

This Problem can be better Understood by Drawing the Linked List and the Pointers.
*/