// PROBLEM 05: K-th ancestor of a node in Binary Tree (GFG)
#include<iostream>
#include<queue>
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

bool ancestor(Node* root, int nodeVal, int &k, int &ans) {
    // Base case
    if(root == NULL){
        return false;
    }

    // 1 case hum solve kar lenge
    // Step 01: First find the given nodeVal Location
    // agar nodeVal location mil jati hai to
    if(root->data == nodeVal){
        // me check kr loonga ki k==0 
        if(k == 0){
            ans = root->data;
            return false;
        }
        --k;
        return true;
    }
    else{
        // agar nodeVal location nahi mil jati hai to
        // Step 02: Recursion solve kr lega
        bool leftSub = ancestor(root->left, nodeVal, k, ans);
        if(leftSub == true){
            // me check kr loonga ki k==0 
            if(k == 0){
                ans = root->data;
                return false;
            }
            --k;
            return true;
        }
        bool rightSub = ancestor(root->right, nodeVal, k, ans);
            if(rightSub == true){
            // me check kr loonga ki k==0 
            if(k == 0){
                ans = root->data;
                return false;
            }
            --k;
            return true;
        }
    }
}

int main(){
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    int nodeVal = 80;
    int k = 2;
    int ans = -1;
    ancestor(root, nodeVal, k, ans);
    cout<< "ANS: " << ans << endl;

    return 0;
}

/*
Binary Tree Input: 10 20 40 70 -1 -1 80 90 -1 -1 100 -1 -1 50 -1 -1 30 -1 60 -1 -1

OUTPUT:
Level Wise Order: 
10 
20 30 
40 50 60 70 
90 100 
*/