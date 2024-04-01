//https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

// Maximum sum of non adjacent nodes

/* 
Approach is Very Simple 
Step 1 - pair {in,ex}  Either Include the current Node or Exclude the Cureent Node
    IF INCLUDING :
        You cannot include  left or right node therfore 
            in = left_ans.second (excluding left Node )+ right_ans.second (excluding right Node) + curr 

    IF EXCLUDING :
        You May or May Not Include or Exclude left or right node.
        Therefore you will find which evr will give you maximum value either include or exclude for both left and right nodes

        ex = max(left_ans.first,left_ans.second) + max(right_ans.first,right_ans.second)
                        |               |                       |            |
                (including Left)(Excluding left)      (Including right)(Excluding right)
    Return {in,ex}            
*/
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node * root){
        if(root==NULL){
            return {0,0};
        }
        auto left_ans = solve(root->left);
        auto right_ans = solve(root->right);
        //include
        int curr = root->data;
        int in = left_ans.second + right_ans.second + curr;
        
        //exclude
        int ex = max(left_ans.first,left_ans.second) + max(right_ans.first,right_ans.second);
        return {in,ex};
    }
    int getMaxSum(Node *root) 
    {
        auto p = solve(root);
        return max(p.first,p.second);
    }
};