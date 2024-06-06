//https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

//Is binary tree a heap

/*
Solution - Heap follows 2 Properties :

        1. It is a CBT - to confirm this we are using the flag approach 
        2. Its Parent is Greater/Smaller than Both the Children 

That's it ! these are the 2 simple Properties and we have written FUnctions to find them

*/

class Solution {
public:
    bool isCBT(struct Node* root) {
        if (root == NULL) {
            return true;
        }
        bool null_encounter = false;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            struct Node* temp = q.front();
            q.pop();
            if (temp == NULL) {
                null_encounter = true;
                continue;
            }
            q.push(temp->left);
            q.push(temp->right);

            if (null_encounter && temp) {
                return false;
            }
        }
        return true;
    }

    bool isvalid(struct Node* root) {
        if (root == NULL) {
            return true;
        }

        int left_child = 0;
        int right_child = 0;

        if (root->left) {
            Node* left_node = root->left;
            left_child = left_node->data;
        }
        if (root->right) {
            Node* right_node = root->right;
            right_child = right_node->data;
        }

        bool left_ans = isvalid(root->left);
        bool right_ans = isvalid(root->right);

        if (left_ans && right_ans && left_child < root->data &&
            right_child < root->data) {
            return true;
        } else {
            return false;
        }
    }
    bool isHeap(struct Node* tree) {
        bool a1 = isCBT(tree);
        bool a2 = isvalid(tree);
        if (a1 && a2) {
            return true;
        } else {
            return false;
        }
    }
};