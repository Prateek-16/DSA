//https://www.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1

//Replace every element with the least-greater element on its right

/*Hint - Make BST in Reverse Order , and find Inorder successor */


class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        this->data=val;
        this->right=NULL;
        this->left=NULL;
    }
    
};
class Solution{
    public:
    Node* insert(Node*root,int arr,int& succ){
        if(root==NULL){
            return new Node(arr);
        }
        if(arr>=root->data){
            root->right = insert(root->right,arr,succ);
        }
        else{
            succ = root->data;
            root->left = insert(root->left,arr,succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(n,-1);
        Node* root = 0;
        for(int i=arr.size()-1;i>=0;i--){
            int succ = -1;
            root = insert(root,arr[i],succ);
            ans[i]=succ;
        }
        return ans;
    }
};