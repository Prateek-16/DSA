//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

//Prims Algorithm for finding minimum spanning tree

/*

MSP - Edges have minimum weight and are n-1 in total where n is the number of nodes.

Prims Main Working - Start from any Node and check for all adjacent nodes if the weights could be reduced, 
if possible then reduce it and change the parent node.

When all the Nodes are traversed then Parent Array will have the MSP connections

*/

/*
Approach : 
Step 1 : Initialize 3 vectors, 
    1. Key (this will store the weights of the Nodes , Initially INT_MAX)
    2. MSP (this will store the nodes which are already in the msp , Initially false)
    3. parent (this will store the parent of the nodes , Initially -1)

    Now for starting Node (which is generally node 0)
    the weight to reach there will be 0 so :
    set Key[0] = 0;

Step 2 : Processing :
    1. Get Minimum Weight Node from Key (so return the index not the weight) which is not visited yet ie MSP = false.
        cond : msp = false && weight if key[i] is minimum : then return index,
    2. Now using Adj list find all the neighbours of the node for which :
        msp = false && Edge_weight < key[neighbour],
        if true then update :
        key[neighbour] = edge_weight && parent[neighbour] = index
    3. Keep repeating until all the nodes in msp are visited
*/


class Solution
{
    int getMinimum(vector<int>& key,vector<int>& mst){
        int temp = INT_MAX;
        int index = -1;
        for(int i=0;i<key.size();i++){
            if(key[i] < temp && mst[i]==false){
                temp = key[i];
                index = i;
            }
        }
        return index;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>key(V,INT_MAX);
        vector<int>mst(V,false);
        vector<int>parent(V,-1);
        
        key[0] = 0;
        
        while(true){
            int u = getMinimum(key,mst);
            if(u == -1){  //This Condition means that all mst is true ie visited
                break;
            }
            mst[u] = true;
            
            for(auto edge: adj[u]){     //visiting all the neighbors of the node u,
                int v = edge[0];        // v is the edge node of edge u - v
                int w = edge[1];        // w is the eight of edge u - v
                
                if(w < key[v] && mst[v]==false){    //Simple condition for updation of key 
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

        //Till here MSP is created and Now we are finding the sum

        int sum = 0;
        
        for(int u = 0;u<parent.size();u++){
            if(parent[u] == -1){
                continue;
            }
            for(auto edge: adj[u]){
                int v = edge[0];
                int w = edge[1];
                if(v==parent[u]){
                    sum += w;
                }
            }
        }
        return sum;
    }
};
