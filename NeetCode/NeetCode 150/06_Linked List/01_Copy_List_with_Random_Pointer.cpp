//https://leetcode.com/problems/copy-list-with-random-pointer/description/


/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/


/*
Appproach - So we need to make a deep copy means actual new nodes
Steps :
    1. Loop on the original list using a temp pointer, and insert a new node called copy between the original list
        so now the list should be like this : 
            1 org -> 1 new -> 3 org -> 3 new -> 8 org -> 8 new -> NULL
    2. Now we need to set the random pointers
        Loop again using the temp pointer and set : 
            temp -> next -> random ( temp will be at org node , its next is the new node and its random will be set )
                    =
            temp -> random ? temp -> random -> next : NULL
        (checking if random pointer exists for temp node and if it does we are setting it to temp-> random (org node) -> next(new Node) , and if it does not then null)
    3. Once this is done we are all set we just need to seperate the new Node from the org nodes
        so set the head of the new Node are head -> next
        and again loop with temp :
            get temp -> next in a cloned Node 
            set temp -> next to temp -> next -> next ( org to org node )
            if cloned node -> next exists ( new to org node ) then
            cloned node -> next -> next also exists ( new to new node ) so set it from cloned node -> next
            and finally move temo to next ( eariler made connection from org node to org node)
            
*/