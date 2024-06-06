//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

//Check if word is valid after substitutions

class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a') return false;
        stack<char>st;
        for(char ch: s){
            st.push(ch);
            if(ch=='c'){
                st.pop();
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                    }
                    else{
                        st.push('b');
                        st.push('c');
                    }
                }
                else{
                    st.push('c');
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};