//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

//Minimum Add to Make Parentheses Valid

//*******************************MY APPROACH**************************************
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto it : s){
            if(!st.empty() && it ==')' && st.top()=='('){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        return st.size(); 
    }
};
//all Push() , pop() operations are performed

//*******************************Lakshay's approach********************************
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count = 0;
        for(auto it : s){
            if(it=='('){
                st.push(it);
                count++;
            }
            else{
                
                if(!st.empty()){
                    st.pop();
                    count--;
                }
                else{
                    count++;
                }
            }
        }
        return st.size(); 
    }
};

//in this approach we are only Pushing the operning brackets and not the closeing brackets

