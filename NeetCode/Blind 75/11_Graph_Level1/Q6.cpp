//https://neetcode.io/problems/count-connected-components


/*
There is an undirected graph with n nodes. There is also an edges array, where edges[i] = [a, b] means that there is an edge between node a and node b in the graph.

Return the total number of connected components in that graph.

Example 1:

Input:
n=3
edges=[[0,1], [0,2]]

Output:
1
Example 2:

Input:
n=6
edges=[[0,1], [1,2], [2,3], [4,5]]

Output:
2
*/


/*
Approach - Similar to Kruskal's algorithm : where we will use parent vector and the rank vector
1. initially all nodes will form seperate components , and will be there own parent with rank 1
2. Then itrate on the neighbors and find parents of the each edge , if not the same the call union and mentain a count 
*/