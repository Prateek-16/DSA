// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

// Predecessor and Successor

class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        Node* pred = NULL;
        Node* succ = NULL;
        Node* curr = root;
        while (curr) {
            if (curr->key > key) {
                succ = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        curr = root;
        while (curr) {
            if (curr->key < key) {
                pred = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        pre = pred;
        suc = succ;
    }
};