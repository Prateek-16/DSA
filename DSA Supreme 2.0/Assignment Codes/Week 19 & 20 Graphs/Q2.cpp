// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

// Kruskals algorithm for finding Minimum Spanning Tree

/*
MSP - Edges have minimum weight and are n-1 in total where n is the number of nodes.

Kruskals main working - Start from the edge with minimum weight and if the and if the edges u - v with minimum weight are not having the same
parent, then mege u and v in same conponent else skip to next...

basically we are building the mst from minimum weight edge using disjoint sets

all elements in a same set will have a parent value and if 2 nodes have the same parent that means there is a cycle forming in the msp
*/

/*
Approach - 1. So what is basically happening here is each node is initially forming its own component.

2. Then we have 2 vectors parent and rank
    parent : this vector stores the parent node of everyNode
    rank : this vector stores how many children can a node have

3. Initially each node is its own parent and rank is 0

4. Then we will pick the minimum weight edge with nodes u and v :
    check if parent of u and v are same :
        if true : then they belong to the same component so we should not merge to avoid cycles, so skip.
        if false : we will form a unionSet between nodes u and v basically merge 2 components. 

5. unionSet : this function will basically be used to merge 2 components.
    1. so suppose we want to union u and v node:
    2. so whosoever have higher rank will become the parent of other,
    3. and will increment its rank further.
*/

/*
So in short :
1. In starting all nodes are disjoint and first individual components.
2. Then we build a D.S such that it have weights of edges w in sorted order, along with the Nodes u and v.
3. Then starting from the lowest weighted edge we check if the nodes belong to same parent or not
    if true : then it means both nodes are in same component, so skip / continue
    if false : then it means both nodes are in different component , so setUnion / Merge the component.

4. setUnion Function : 
    Takes 2 Nodes as input then the node with the higher rank is made the parent of the other node, and its rank is increased by 1.
*/

class solution
{
public:
    static bool mycomp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        // if we reach here means they are from different components...
        if (rank[u] <= rank[v])
        {
            parent[u] = v;
            rank[v]++;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int spammingTree(int V, vector<vector<int>> adj[])
    {
        // Kruskal Algorithm
        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; i++)
        { // initial all nodes are parent of themself
            parent[i] = i;
        }

        vector<vector<int>> edges; // Making a DS to store u - v - w for every edge, sorted by weights.
        for (int u = 0; u < V; u++)
        {
            for (auto edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];
                edges.push_back({u, v, w});
            }
        }
        sort(edges.begin(), edges.end(), mycomp);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            u = findParent(parent, u);
            v = findParent(parent, v);
            if (u != v)
            {
                unionSet(u, v, parent, rank);
            }
        }
    }
}