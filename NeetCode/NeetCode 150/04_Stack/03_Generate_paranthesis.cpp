//https://leetcode.com/problems/generate-parentheses/description/


/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/


/*
Approach - So simply by reading thr question we can understand that we will use include exclude type of time here
so we need to mentain the count of our open para and the closing para
    if open para is less than n : then we can always include a opeing paranthesis
    but we can only include a closing paranthesis when close para is less than open para
    this prevent us from conditions like this " ) ( " , we wound not be  able to include the first closing paranthesis when there are 0 opening paranthesis

Flow : 
    1. open = 0 and close = 0
    2. initalize vector string ans & a empty string s = ""
    3. call a solve function with inputs : n , open , close , ans , s

        void solve function :
            1. base case condition : open == n and close == n 
                then ans.push_back(s);
                return;

            2. condition for open para ie open < n
                solve( n , open + 1, close , ans , s + "(" )
            
            3. condition for close para ie close < open 
                solve( n , open, close + 1 , ans , s + ")");

    4. return ans;
        
*/
