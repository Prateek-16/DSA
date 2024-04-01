//https://www.geeksforgeeks.org/problems/burning-tree/1

//Burning Tree


class Solution {
  public:
    Node* targetfinder_parentmap(Node* root,unordered_map<Node*,Node*>&ParentNode,int target){
        
        Node* targetNode = 0;
        queue<Node*>q;
        q.push(root);
        ParentNode[root]=0;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp->data==target){
                targetNode = temp;
            }
            if(temp->left){
                q.push(temp->left);
                ParentNode[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                ParentNode[temp->right]=temp;
            }
        }
        return targetNode;
    }
    
    int burn(Node* targetNode,unordered_map<Node*,Node*>&ParentNode){
        int t = 0;
        queue<Node*>q;
        unordered_map<Node*,bool>visited;
        q.push(targetNode);
        visited[targetNode] = 1;
        while(!q.empty()){
            
            int size = q.size();
            bool isfireSpreaded = 0;
            
            for(int i = 0; i<size; i++){
                
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = 1;
                    isfireSpreaded = 1;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = 1;
                    isfireSpreaded = 1;
                }
                if(ParentNode[temp] && !visited[ParentNode[temp]]){
                    q.push(ParentNode[temp]);
                    visited[ParentNode[temp]] = 1;
                    isfireSpreaded = 1;
                }
            }
            if(isfireSpreaded){
                t++;
            }
        }
        return t;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>ParentNode;
        Node* targetNode = targetfinder_parentmap(root,ParentNode,target);
        return burn(targetNode,ParentNode);
    }
};