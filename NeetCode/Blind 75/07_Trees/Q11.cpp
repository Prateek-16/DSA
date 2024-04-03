// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, 
so please be creative and come up with different approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []
*/

/*
Approach - TOh 2 operation karne hai serialization and deserialization 
Serialization:
    1. In this step we will itrate the tree, and do some kind of encode of root value :
        if root == NULL then s += "N,"
        else s+= to_string(root->value) + ","
    so these step can easily encode the tree in s.
    and our distiction markerr is ","

Deserialization:
    1. suppose hume input mai index = i mil raha hai
    2. then agar i > s.length , return null
    3. now initialise a j pointer at i
    4. and while s[j] != ',' 
        1. store all the s[j] in a string num
    5. then set i = j + 1 (beacuse j is at , vala index)

    6. Now we have the string num 
        so if num is "N" means return null
    
    7. else create a new Node root with val = stoi(num)
    8. root->left = left recursive call
    9. root->right = right recursive call

thod thoda deserialization mushkil hai queue ka use bhi karna ka try karna.
*/