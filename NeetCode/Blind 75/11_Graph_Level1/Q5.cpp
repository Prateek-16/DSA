//https://neetcode.io/problems/valid-tree


/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.

Example 1:

Input:
n = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 4]]

Output:
true
Example 2:

Input:
n = 5
edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]

Output:
false
*/


/*
Approach - To make a valid tree :
    1. there should be no cycle in the graph
    2. Number of edges should be n-1 (n = no. of nodes) or all nodes should be visited

    Simple cycle detection karna hai 
    and then visited vector ki hep se check kar lena if any node is left unvisited
    
*/