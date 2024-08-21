// PROBLEM 01: Convert BST into Sorted Double Linked List

/*
Time Complexity: O(N)
Space Complexity: O(H)
Where N is number of nodes of BST and H is height of BST
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

void convertBSTtoDLL(Node* root, Node* &head){
    // Base case
    if(root == NULL){
        return;
    }

    // Reverse Inorder Traversal
    // R
    convertBSTtoDLL(root->right, head);

    // N
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    // Updating the head (GALTI YANHI HO RHI THI)
    head = root;

    // L
    convertBSTtoDLL(root->left, head);
}

void printDLL(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<< temp->data << " ";
        temp = temp->right;
    }
    cout<<endl;    
}

int main(){

    int inorder[] = {5, 50, 60, 100, 200, 300};
    int size = 6;
    int start = 0;
    int end = size - 1;

    Node* head = NULL;
    convertBSTtoDLL(root, head); 
    cout << "Sorted Double Linked List: " << endl;
    printDLL(head);

    return 0;
}


*************************************************************


class Solution {
public:
    Node* prevNode;
    Node* listHead;

    // Main function to convert a BST to a sorted circular doubly-linked list.
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;   // If the tree is empty, return nullptr.

        // Reset the prevNode and listHead pointers before starting the DFS.
        prevNode = nullptr;
        listHead = nullptr;

        // Perform a depth-first search to traverse the tree in order.
        DFSInOrder(root);

        // After the DFS is done, connect the head and tail to make it circular.
        prevNode->right = listHead;
        listHead->left = prevNode;

        return listHead;    // Return the head of the doubly linked list.
    }

    // Helper DFS function to perform in-order traversal.
    void DFSInOrder(Node* currentNode) {
        if (!currentNode) return;  // Base case: if the current node is null, just return.

        // Traverse the left subtree first (in-order traversal).
        DFSInOrder(currentNode->left);

        // When processing the current node:
        if (prevNode) {
            // If prevNode is not null, link it with the current node.
            prevNode->right = currentNode;
            currentNode->left = prevNode;
        } else {
            // If this is the leftmost node, it will be the head of the doubly linked list.
            listHead = currentNode;
        }
      
        // Move prevNode to the current node before traversing the right subtree.
        prevNode = currentNode;

        // Traverse the right subtree.
        DFSInOrder(currentNode->right);
    }
};