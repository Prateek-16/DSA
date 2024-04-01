//https://leetcode.com/problems/remove-k-digits/description/

//remove K digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            char ele = num[i];
            if (k > 0) {
                while (!st.empty() && st.top() > ele) {
                    st.pop();
                    k--;
                    if (k == 0) {
                        break;
                    }
                }
            }
            st.push(ele);
        }
        // case where K is still Left after whole Itration
        if(k>0){
            while (!st.empty() && k) {
                st.pop();
                k--;
            }
        }
        string ans;
        // Now The Stack will Have the answer
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        while (ans.size() > 0 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};