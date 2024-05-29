#include <iostream>
#include <vector>
#include <stack>

void topologicalSortUtil(int v, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::stack<int>& Stack) {
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

std::vector<int> topologicalSort(int V, const std::vector<std::vector<int>>& adj) {
    std::stack<int> Stack;
    std::vector<bool> visited(V, false);

    // Call the recursive helper function to store the Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }

    // Store the result in a vector
    std::vector<int> result;
    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }

    return result;
}

int main() {
    // Number of vertices
    int V = 6;
    std::vector<std::vector<int>> adj(V);

    // Adding edges to the directed graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    std::vector<int> result = topologicalSort(V, adj);

    std::cout << "Topological Sorting of the given graph is: ";
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
