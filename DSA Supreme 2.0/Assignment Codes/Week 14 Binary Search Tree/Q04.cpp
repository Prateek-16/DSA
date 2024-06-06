//https://www.geeksforgeeks.org/problems/brothers-from-different-root/1


//Brothers From Different Roots


class Solution {
public:
    int countPairs(Node* root1, Node* root2, int x) {
        // inorder comparision
        Node* temp1 = root1;
        Node* temp2 = root2;
        int ans = 0;
        stack<Node*> t1, t2;
        while (true) {
            while (temp1) {
                t1.push(temp1);
                temp1 = temp1->left;
            }
            while (temp2) {
                t2.push(temp2);
                temp2 = temp2->right;
            }
            if (t1.empty() || t2.empty()) {
                break;
            }
            auto curr_top1 = t1.top();
            auto curr_top2 = t2.top();
            int sum = curr_top1->data + curr_top2->data;
            if (sum == x) {
                ans++;
                t1.pop();
                t2.pop();
                temp1 = curr_top1->right;
                temp2 = curr_top2->left;
            } else if (sum > x) {
                t2.pop();
                temp2 = curr_top2->left;
            } else {
                t1.pop();
                temp1 = curr_top1->right;
            }
        }
        return ans;
    }
};