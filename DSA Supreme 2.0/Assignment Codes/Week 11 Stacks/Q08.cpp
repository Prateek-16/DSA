//https://leetcode.com/problems/decode-string/

//Decode a string

class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(char ch:s){
            if(ch==']'){

                string inner_bracket_string="";
                while(!st.empty() && st.top()!="["){
                    string top=st.top();
                    inner_bracket_string+=top;
                    st.pop();
                }

                st.pop();    //popping the opening bracket

                string n_times="";
                while (!st.empty() && isdigit(st.top()[0])){
                    n_times+=st.top();
                    st.pop();
                }

                // now we have the numeric value but it will be reversed in order

                reverse(n_times.begin(),n_times.end());

                int n;
                n=stoi(n_times);

                string curr_string="";
                while(n--){
                    curr_string+=inner_bracket_string;
                }

                st.push(curr_string);

            }
            else{
                string temp(1,ch);
                st.push(temp);
            }
        }
        string final_string;
        while(!st.empty()){
            final_string+=st.top();
            st.pop();
        }
        reverse(final_string.begin(),final_string.end());
        return final_string;
        
    }
};