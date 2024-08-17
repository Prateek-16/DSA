https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// Diagonal Traversal of binary tree

/*So what we are doing here is Basically
Step 1 - We are taking a queue and pushing the root in it
Step 2 - we are Now Moving to the right ie Diagonal and saving these values
Step 3 - while Moving to The Right if and Node has a Left also we will Push it inside the Queue
Step 4 - once we are done for that diagonal the queue will automatically start for the left nodes or next diagonal
*/

vector<int> diagonal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        Node *tempNode = q.front();
        q.pop();
        while (tempNode)
        {
            ans.push_back(tempNode->data);
            if (tempNode->left)
            {
                q.push(tempNode->left);
            }
            tempNode = tempNode->right;
        }
    }
    return ans;
}