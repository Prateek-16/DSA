//https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/


/*

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 
*/

/*
Approach - So lets understand the question :
we have Multiple components of computers.
there components are connected internally but are disconnected from each other. Like a disconnected graph

We need to connect all these disconnected components, without buying extra wires so we need know if its possible to connect these disconnected components
using the extra wires of internally connected components

Main Observation : to connect N node we need n-1 edges.
So we can easily find the number of disconnected components using DFS and visited array
But if we can somehow find the number of extra wires in internal components then we can return an answer
ie  if (extrawires > number of disconnected components - 1) then : return number of disconnected components -1 
    else : return -1 ( not Possible )

So how to find this Number of extrawires ? 
Humne Kruskal's algorithm mai dekha tha kaise multiple disconnected components ko combine karte hai Parent and Rank ki help se
Toh usi mai ek cheez keh sakte hai ki :
    if node u and v hacve same parent means they are already connected so the edge / wire from u to v is useless hence it is extra wire

Simple !!

Flow :
1. Initialisation of parent vector and rank vector 
2. Write the findparent ans setUnion functions
3. traverse on the graph and get nodes u and v for each edge
4. findParents of u and v
5. If different parents then :
    setunion u and v
   else means same parents so : 
    it is extraedge
6. Now find NoofComponents using parent array:
    loop on parent array :
        if parent[i] is i then : 
            its a component so noofcomponents++ 
7. Required edge = NoofComponents - 1 
8. if ExtraEdge >= Required edge :
    return Required edge.
   else :
    return false.
*/