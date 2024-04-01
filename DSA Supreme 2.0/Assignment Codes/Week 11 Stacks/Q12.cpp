//https://leetcode.com/problems/longest-valid-parentheses/

//Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxLen=0;
        for(int i =0;i<s.length();i++){
            char it=s[i];
            if(it=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                int len = i - st.top();
                maxLen = max(maxLen,len);
            }
        }
        return maxLen;
        
    }
};