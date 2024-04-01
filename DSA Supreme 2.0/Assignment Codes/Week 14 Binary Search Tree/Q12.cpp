//https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


//Merge Two BST


class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        stack<Node *> s1;
        stack<Node *> s2;
        vector<int> ans;
        Node *temp1 = root1;
        Node *temp2 = root2;
        while (temp1 || temp2 || !s1.empty() || !s2.empty())
        {
            while (temp1)
            {
                s1.push(temp1);
                temp1 = temp1->left;
            }
            while (temp2)
            {
                s2.push(temp2);
                temp2 = temp2->left;
            }
            
            if ( s1.empty() || (!s2.empty() && s1.top()->data >= s2.top()->data))
            {
                auto temp = s2.top();
                ans.push_back(temp->data);
                s2.pop();
                temp2 = temp->right;
            }
            else
            {
                auto temp = s1.top();
                ans.push_back(temp->data);
                s1.pop();
                temp1 = temp->right;
            }
        }
        return ans;
    }
};