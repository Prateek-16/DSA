//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/


//Vertical Order Traversal of a Binary Tree

/*

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions
(row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]

Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

*/

/*
Approach - So the explanation is simple but implementation of the case is tricky.

toh we have rows and columns for each node and we need to do (row + 1, col - 1) and (row + 1, col + 1) for left and right children
so dimag mai level order traversal a raha hai.

ek queue banaenge aur usme 3 cheeze hongi : pair < Node* , pair < row , column > >
ek map banaenge aur useme key ko coloumn rakhenge, so that sabse chota coloumn yani leftmost coloumn map mai sabse pehele a jae and easily itrate karke final answer bana paye.
so map mai coloumn mapped hoga rows and values ( multiple nodes can have same column ) ke sath.
values sorted honi chahiye isliye ek multiset ka use kar lenge ( unlike set jo sorted but unique values sort karta hai, multiset can store sorted and duplicated values ).

so map will be like this < col , map < row , value > >

Now level order traversal karo until queue is empty:
    1. get front Node, and remove it from queue
    2. front Node first is the Node* pointer (temp) second is the row and column pair, extract all these values
    3. Now push in map[column][row].insert(temp->data)
    4. Node if left of temp exist then push it by do column - 1 and row + 1
    5. similarly if right of temp exist then push it by do column + 1 and row + 1

Now We will have the Map
itrate this map mp first is column and second is map of row to values
then itrate the inner map using mp.second
there copy the values in a curr vector and after the inner loop enter these values in the answer vector.

*/
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode *, pair<int, int>>> q; // Node, (row,col)
        map<int, map<int, multiset<int>>> mp;      // col -> row -> [sorted row data]
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            TreeNode *&curr_node = front.first;
            auto &coordinates = front.second;
            int &row = coordinates.first;
            int &col = coordinates.second;

            mp[col][row].insert(curr_node->val);

            if (curr_node->left)
            {
                q.push({curr_node->left, {row + 1, col - 1}});
            }
            if (curr_node->right)
            {
                q.push({curr_node->right, {row + 1, col + 1}});
            }
        }
        for (auto it : mp)
        { // it -> col
            auto &colmap = it.second;
            vector<int> curr;
            for (auto colmap_it : colmap)
            {
                auto &row_set = colmap_it.second;
                curr.insert(curr.end(), row_set.begin(), row_set.end());
            }
            ans.push_back(curr);
        }
        return ans;
    }
};