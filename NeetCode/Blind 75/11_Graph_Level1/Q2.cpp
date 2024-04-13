//https://leetcode.com/problems/clone-graph/description/


/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
*/


/*
Approach - So we need to return a deep copy of the given graph 
and a single node of a graph will have 2 things 1. value & 2. list neighbors

Question is easy but the code can be confusing,
Simple explanation for approach : Hum map banaenge jo original node ke against cloned node ko store karega

So bas ek traversal karna hai and jab bhi original node mile then uske lye ek map mai cloned node ceate karni hai
then neighbors set karne hai cloned node ke 
at end of traversal return karna hai head of cloned node

Steps : 
    1. Create a map for <Node*, Node*>  // original node -> Cloned node
    2. we will be given a starting node, make a new Node called clonedNode from this starting node value, & also map the original node with the new node
        Node* cloneNode = new Node(node->val);
    3. BFS Traversal starts : create a queue , and push the original node in the queue
    4. While q is empty :

        1. get front node 
        2. pop the queue

        3. Now itrate on the neighbors of the front node  // for (int i = 0; i < front->neighbors.size(); i++)
            1. create a pointer to the neighbor node ie : Node* neighbor = front->neighbors[i];
            2. check if the neighbor is already in the map, ie : already visited node
                if not present in the map :
                    means we need to add this neighbor node to the map, for that we need to create a cloned node of this neighbor
                    ie : mp[neighbor] = new Node(neighbor->val);
                also if not present in the map, push the neighbor in the queue
            3. Now we need to Make this neighbor connection for the cloned node also ( Most important step )
                connection : front node -> neighbor is -> neighbor node
                we need to make these connections for our cloned nodes, and we can access the cloned node with the map using original nodes
            4.  connection : mp[front node] -> neighbor is -> mp[neighbor node]
                ie mp[front]->neighbors.push_back(mp[neighbor]);
    5. Now after the BFS traversal we need to return the first cloned node


*/