//https://leetcode.com/problems/remove-k-digits/description/

//remove K digits


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (char ele : num) {
            // While the current digit is smaller than the top of the stack, 
            // and we still have digits to remove (k > 0)
            while (!st.empty() && k > 0 && st.top() > ele) {
                st.pop();
                k--;
            }
            // Avoid pushing leading zeros onto the stack
            if (!st.empty() || ele != '0') {
                st.push(ele);
            }
        }
        
        // If k is still greater than 0, pop the remaining digits from the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Build the final answer string from the stack
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        // Reverse the string since the stack gives the digits in reverse order
        reverse(ans.begin(), ans.end());
        
        // If the result is empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};


***********************************************************

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