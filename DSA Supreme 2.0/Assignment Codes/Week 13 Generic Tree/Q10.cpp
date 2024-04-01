//https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

// Sum of the longest bloodline of a tree


class Solution
{
public:
    pair<int,int> height(Node* root){
        if(root==NULL){
            return {0,0};
        }
        auto lh = height(root->left);
        auto rh = height(root->right);
        if(lh.first == rh.first){
            return {lh.first + 1 , max(lh.second,rh.second)+ root->data};
        }
        else if(lh.first > rh.first){
            return {lh.first+1,lh.second + root->data};
        }
        else{
            return {rh.first+1,rh.second + root->data};
        }
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        auto n = height(root);
        return n.second;
    }
};