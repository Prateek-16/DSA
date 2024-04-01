// 6. Level order traversal in level wise

/*
    Time Complexity: O(N), where N is total number of nodes in binary tree
    Space Complexity: O(L), where L is maximum number of nodes in the level of binary tree
*/


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

// It returns the root node of created tree
Node* createTree(){
    cout<< "Enter the value: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    // Step 1: Create Node
    Node* root = new Node(data);
    // Step 2: Create Left Subtree
    root->left = createTree();
    // Step 3: Create Right Subtree
    root->right = createTree();

    return root;
}

// Level order traversal in level wise
void levelOrderTraversalLevelWise(Node* root){
    queue<Node*> q;

    // Initial Push the Root Node and NULL to the Queue
    q.push(root);
    q.push(NULL);

    // Now start the traversal on queue
    // jab tak queue empty nahi ho jata ho
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        
        // Not Valid -> Ek aur level complete ho chuki hai
        if(frontNode == NULL){
            cout<<endl;
            if(!q.empty()){ 
                // Yeh wala case lagana hum bhool jate hai
                // this is important case --> 
                // kyunki jab most last level khatam hogi to null
                // push nhi hona chaiye queue 
                // otherwise queue never empty --> to code fat jayega
                q.push(NULL);
            }
        }
        // Valid -> Abhi level complete nhi hue hai
        else{
            cout<< frontNode->data << " ";

            if(frontNode->left != NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right != NULL){
                q.push(frontNode->right);
            }
        }
    }
}

int main(){
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    return 0;
}

/*
Binary Tree Input: 10 20 40 -1 -1 50 90 -1 -1 100 -1 -1 30 60 -1 -1 70 -1 -1

OUTPUT:
Level Wise Order: 
10 
20 30 
40 50 60 70 
90 100 
*/