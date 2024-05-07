//https://leetcode.com/problems/lru-cache/description/


/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/


/*
Approach - So we need to design a LRU cache, we can do this using a DoublyLinkedList

    Visually :
        Head ------- Tail 
    
    Head and tail are the 2 Nodes between which our LRU cache will be created
    when we add a new node it will be next to the head
    when we remove a node it will be prev to the tail

    We need to access these Nodes with a Key so we need a HashMap also

    The HashMap will store the key to Node Pointer { key -> Node Pointer }

    with the HashMap Also we can Find if our capacity is Full or Not

Flow : 
    1. Make a class for a double-linked list Node
    2. Initialize the capacity variable, the Head and tail Node and the HashMap { key -> *Node }
    3. Make a Function to add the Node ( always add Next to the head node ) // Most Recently used
    4. Make a function to remove the Node ( remove the given Node ) // Least recently used

    5. Function LRUCache ( capacity ) 
        This function will set the capacity of the LRUCache
        and will also  link the head and tail node together

    6. Function get ( key_ )
        1. check in the map if the key exists in the map, If it does :
            1. Get the Pointer to the Node
            2. Remove the Node From the Doubly-linked list
            3. Add the Node Back in the list ( most recently used )
            4. Return the value of the Node
        2. If it doesn't exist :
            1. return -1;

    7. Function put( key_, value_ )
        1. check in the map if the key exists in the map, If it does :
            1. Get the Pointer to the Node
            2. Remove the Node from the Map
            3. Delete the Node
        2. Check if the size of the map is greater than the size of the capacity, If it does :
            1. remove the last from the map ie (tail -> prev)
            2. delete the Node
        3. Create a new Node with key_ and value_
        4. Add the Node to the map
        5. add the Node to the Linked list
*/