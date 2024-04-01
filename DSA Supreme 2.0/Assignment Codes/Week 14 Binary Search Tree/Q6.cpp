//https://www.geeksforgeeks.org/problems/median-of-bst/1

//Median of a Binary search tree

/*
Median can be found simply by stroing the inorder and find n/2 and n/2+1th term 
but we will find the median in strickly O(1) space complexity

Steps:
Step 1 : Use morris traveral to find Number of Nodes
Step 2 : Then again use Morris Inorder Traversal To find Inorder But Not Acutally Store It,
         But Simplly Store (n/2)th and ((n/2)+1)th and ((n+1)/2)th Nodes Data
Step 3 : Finally check is N is Odd Or Even And return the Median Accordingly
*/
int morrisTraversalPreorder(Node* root) {
    int i = 0;
    while (root) {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->left == NULL) {
            i++;
            root = root->right;
        } else {
            // Find inorder predecessor
            Node* current = root->left;
            while (current->right && current->right != root)
                current = current->right;

            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == root) {
                current->right = NULL;
                root = root->right;
            }

            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else {
                i++;
                current->right = root;
                root = root->left;
            }
        }
    }
    return i;
}

float find_median(Node* root, int n) {
    int i = 0;
    int odd1 = (n + 1) / 2, oddval1 = -1;
    int even1 = n / 2, evenval1 = -1;
    int even2 = (n / 2) + 1, evenval2 = -1;
    while (root) {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->left == NULL) {
            i++;

            if (i == odd1) {
                oddval1 = root->data;
            }
            if (i == even1) {
                evenval1 = root->data;
            }
            if (i == even2) {
                evenval2 = root->data;
            }
            root = root->right;
        } else {
            // Find inorder predecessor
            Node* current = root->left;
            while (current->right && current->right != root)
                current = current->right;

            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == NULL) {
                current->right = root;
                root = root->left;

            }

            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else {
                i++;
                current->right = NULL;

                if (i == odd1) {
                    oddval1 = root->data;
                }
                if (i == even1) {
                    evenval1 = root->data;
                }
                if (i == even2) {
                    evenval2 = root->data;
                }
                root = root->right;
            }
        }
    }
    if (n & 1) {
        return oddval1;
    } else {
        return (evenval1 + evenval2) / 2.0;
    }
}

float findMedian(struct Node* root) {
    // Code here
    int n = morrisTraversalPreorder(root);

    return find_median(root, n);
}