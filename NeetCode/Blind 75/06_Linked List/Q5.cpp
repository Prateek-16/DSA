//https://leetcode.com/problems/linked-list-cycle/description/

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, 
pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false. 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
*/

/*
Approach - Simple approach will be using a simple Map to map if a node is already visited or not, use this approach to pass online coding test.

bool hasCycle(ListNode *head) {
    std::map<ListNode*, bool> visited;
    ListNode* current = head;

    while (current != nullptr) {
        if (visited[current]) {
            return true; // Cycle detected
        }
        visited[current] = true;
        current = current->next;
    }

    return false; // No cycle found
}

Approach 2: Using slow fast pointers
1. initialize slow and fast pointers at head 
2. while : fast can move 2 time( that means fast -> next and fast -> next -> next is not NULL)
    move slow once
    move fast twice
3. if the cycle exist the fast ans slow will definately meet at some point
    so when slow == fast : Return true
4. if there is no cycle fast will reach at the end of the linked list ie NULL
    return false outside the loop
*/