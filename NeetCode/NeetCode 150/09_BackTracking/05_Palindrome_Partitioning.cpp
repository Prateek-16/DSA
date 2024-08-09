//https://leetcode.com/problems/palindrome-partitioning/description/


/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/


/*
Approach - So this is also a similar question 
Lets break down the question: the question want us to return all possible set of palindromic substring which will be partitioned from a given string s
So one thing we can understand is that is we want to make substrings of the given string and then we need to check if these substring are palindromic or not
if the are palindromic then we will move on to the next index

So it is similar to the previous questions we have seen, only thing is we will have a extra function called ispalindromic to check if the string is palindromic or not


Flow : function with inputs : string s , index , answer vector , current vector 

    Base Case : if the string index is more than the size of the string s, then pushback current in the answer vector and return

    Now 1 case : Loop kar from index to end() with itrator "i"
        and then form a substring from index to current itrator "i"
        NOW CHECK IF THIS SUBSTRING IS A PALINDROMIC STRING OR NOT
        if true : 
            then this can one one possible case, so store this substring in the current vector and do function call for index = current itrator i + 1
            this function will check for the next itration indexes if they are palindromic or not, if they are this function will store them in the current vector
            After this function call we also need to backtrack our current substring and remove it from the current vector for next substring

FOr example : 
    input : "aab"
    so i will start from index = 0 and loop till end
        inside this loop will form 3 substrings 
        1. - "a", will check if a is a palindrome or not which it is 
            so now we will store "a" and then do recursive call for index = 1
            after this recursive call we will remove "a" from the current vector and then loop again
            
        2. "aa", will check if aa is a palindrome or not which it is

        similarily will check if "aab" is a palindrome or not
    
    Also there will be inside function calls going on which will build the result for us.


*/


class Solution {
public:
    void partition_helper(string s,int index,vector<string>&curr,vector<vector<string>>&ans){
        if(index>=s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<s.length();i++){
            string r = s.substr(index, i - index + 1);
            if(ispalindrome(r)){
                curr.push_back(r);
                partition_helper(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
        return;
    }

    bool ispalindrome(string st){
        int s=0;
        int e=st.length()-1;
        while(s<e){
            if(st[s]!=st[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        vector<vector<string>>ans;
        partition_helper(s,0,curr,ans);
        return ans;



        
    }
};