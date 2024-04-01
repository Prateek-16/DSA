//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

//Removes duplicates in string

class Solution {
public:
    string removeDuplicates(string s) {

        stack<char>st;
        int n=s.length();
        int i=0;
        while(i<n){
            if(st.empty()){
                st.push(s[i]);
                i++;
            }
            else if(st.top()==s[i]){
                st.pop();
                i++;
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        string new_s;
        while(true){
            if(st.empty()){
                break;
            }
            else{
                new_s+=st.top();
                st.pop();
            }
        }
        reverse(new_s.begin(),new_s.end());
        return new_s;
        
    }
};