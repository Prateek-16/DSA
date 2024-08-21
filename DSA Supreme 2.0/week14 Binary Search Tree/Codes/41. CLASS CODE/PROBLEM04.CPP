// PROBLEM 04: Target value present or not in BST

/*
    Time complexity:
    Skewed BST: O(N) or O(H) in the worst case
    Balanced BST: O(log N) in the average case

    Space Complexity: O(H)
    In the worst case: H is equal to O(N)
    In the average case: H is equal to O(log N) 

    Where H is height of BST and N is number of nodes in BST
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

// Target value found or not
bool searchInBST(Node* root, int target){
    // Base Case
    if(root == NULL){
        return false;
    }

    // 1 case hum solve kr lenge
    if(target == root->data){
        return true;
    }

    // ab recursion solve kar lega
    if(target > root->data){
        return searchInBST(root->right, target);
    }
    if(target < root->data){
        return searchInBST(root->left, target);
    }
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    cout<< "Enter the target:" << endl;
    int target;
    cin >> target;

    while (target != -1)
    {
        bool ans = searchInBST(root, target);
        if(ans == true){
            cout << "FOUND" << endl;
        }
        else{
            cout << "NOT FOUND" << endl;
        }
        cout<< "Enter the target:" << endl;
        cin >> target;
    }
    

    return 0;
}

/*
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1

Enter the target: 80
OUTPUT: FOUND

Enter the target: 2222
OUTPUT: NOT FOUND
*/