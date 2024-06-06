//https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1


//Transform to sum tree

/*
Given a Binary Tree of size N , where each node can have positive or negative values. 
Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree.
The values of leaf nodes are changed to 0.
Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0

/*
Simple hai questions main jo cheez samajnio hai woh yeh hai ki

Curr Node Jo hogi uski value hogi : 
        Left_Tree_sum + Right_tree_sum ;

But jo value curr node return karegi woh hogi :
        left_tree_sum + Right_tree_sum + curr_Node->val ;

And Leaf Node wale Case Ki alag condition hai Ki uski value = 0 But return should be same

basically jab hum Node mai value store karange then : Node ke data ko consider nahi karenge
but jab hum Node ki value ko return karenge then : Node ke data ko consider karenge

*/

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (node->left == NULL && node->right == NULL)
        {
            int temp = node->data;
            node->data = 0;
            return temp;
        }
        int lans = sum(node->left);
        int rans = sum(node->right);
        int temp2 = node->data;
        node->data = lans + rans;
        return temp2 + node->data;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
};