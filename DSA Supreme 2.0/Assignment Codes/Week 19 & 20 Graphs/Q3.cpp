//https://leetcode.com/problems/find-eventual-safe-states/description/


/*

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Illustration of graph

Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]

Output: [2,4,5,6]

Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]

Output: [4]

Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.

*/


/*

Approach - A Terminal Node is with no outgoing edges, to find a safe node we need to make sure that the safe Node is not a part of a cycle.
beacuse if there is a cycle on any edge of a node it will keep on rotating and never reach a terminal node

Step 1 - So we need to detect the cycle in the graph, beacuse if there is a cycle then there will be No terminal node in that cycle.
We will do this by DFS (logical thinking)

Step 2 - DFS cycle Detection : use a DFSTrack and visited Array and if both are true the there is a cycle and backtrack.

Step 3 - use a vector<bool>safeNode to store if a node is safe(1) or not safe(0). initially all Nodes are not safe(0).

Step 4 - Do DFS cycle detection using dfsTrack and visited (see code in week 20 )

Step 5 - Do a Little Modification in the code :
    when we are backtracking and seting dfstrack[src] = 0 , then we know that src is not a part of any cycle so do safeNode[src] = 1.

*/

class Solution {
public:
    bool checkCyclicDFS(int src, unordered_map<int, bool> &visited, 
    unordered_map<int, bool> &DFSTrack, vector<vector<int>>& graph,vector<bool>& safeNode){
        visited[src] = true;
        DFSTrack[src] = true;
        for(auto it: graph[src]){
            if(!visited[it]){
                bool rec_ans = checkCyclicDFS(it,visited,DFSTrack,graph,safeNode);
                if(rec_ans==true){
                    return true;
                }
            }
            if(visited[it] == 1 && DFSTrack[it] == 1){
                return true;
            }
        }
        DFSTrack[src]=false;
        safeNode[src] = 1;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int V = graph.size();
        vector<bool>safeNode(V,0);
        unordered_map<int, bool> visited; 
        unordered_map<int, bool> DFSTrack;
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                checkCyclicDFS(i,visited,DFSTrack,graph,safeNode);
            }
        }
        for(int i = 0;i<V;i++){
            if(safeNode[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};