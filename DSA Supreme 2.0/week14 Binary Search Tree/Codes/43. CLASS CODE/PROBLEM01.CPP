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