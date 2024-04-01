//https://leetcode.com/problems/word-break/description/


//Word Break


/*
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
*/


/*
Approach - So this question looks easy we will simply iterate over string s recursively and try to match the word from tyhe dictionary at each iteration
but this is not so easy because:

Input ->  s: "aaaaaaa" dict = ["aaa","aaaa"]

so in this case we will iterate over s until we get "aaa" then there will be a match 
so now left s = "aaaa" and again we will itrate over dict and again "aaa" will match
so left over will be "a" and then we will return false.

but this is not how this should be done right !!!!!!! in the second case s="aaaa" we should check for aaa and aaaa both and this is the catch of this question

basically even if the word match try to match again will more word length thats it 
*/


class Solution {
public:
    bool check(string& word, vector<string>& wordDict) {
        for (auto it : wordDict) {
            if (it == word) {
                return true;
            }
        }
        return false;
    }
    bool solveWithMem(string& s, vector<string>& wordDict, int start,
                      vector<int>& dp) {
        if (start == s.size()) {
            return true;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); i++) {
            word += s[i];
            if (check(word, wordDict)) {
                flag = flag || solveWithMem(s, wordDict, i + 1, dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }
    bool solveWithTab(string& s, vector<string>& wordDict, vector<int>& dp) {
        dp[s.size()] = 1;
        for (int start = s.size() - 1; start >= 0; start--) {
            string word = "";
            bool flag = false;
            for (int i = start; i < s.size(); i++) {
                word += s[i];
                if (check(word, wordDict)) {
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, -1);
        return solveWithTab(s, wordDict, dp);
    }
};