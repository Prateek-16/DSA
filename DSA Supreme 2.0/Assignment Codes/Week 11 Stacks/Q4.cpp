//https://leetcode.com/problems/next-greater-node-in-linked-list/

//Next Greater Node In Linked List


class Solution {
public:
    void reverse_list(ListNode*& prev, ListNode*& curr, ListNode*& next) {

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return;
    }

    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        reverse_list(prev, curr, next);

        stack<int> st;
        st.push(0);
        vector<int> ans;

        while (prev != NULL) {

            while (st.top() != 0 && st.top() <= prev->val) {
                st.pop();
            }
            ans.push_back(st.top());

            st.push(prev->val);

            prev = prev->next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};