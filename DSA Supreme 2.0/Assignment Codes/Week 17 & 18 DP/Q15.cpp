//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/


//Minimum Insertion Steps to Make a String Palindrome


/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

*/

/*
Approach - So the question is simple we need to tell the minimum number of additions right to make the string a palindrome !
so can we say to add minimum characters we will need maximum palindroming substring already present :

if we have the LPS we can subtract it will the size of the total string and then we will have the minimum length of charcter we need to all

so the crux is :
1. Find the LPS in the given Substring ( reverse and then find the LCS )
2. subtract length of the string with the length of the LPS
and this will be the final answer

*/

class Solution {
public:
    int solvewithTabulation(string& text1, string& text2, int i, int j) {
        vector<vector<int>> dp(text1.length() + 1,vector<int>(text2.length() + 1, 0));
        for (int it = text1.length() - 1; it >= 0; it--) {
            for (int jt = text2.length() - 1; jt >= 0; jt--) {
                int ans = 0;
                if (text1[it] == text2[jt]) {
                    ans = 1 + dp[it + 1][jt + 1];
                } else {
                    ans = 0 + max(dp[it][jt + 1], dp[it + 1][jt]);
                }
                dp[it][jt] = ans;
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string& s) {
        string rev_s = s;
        reverse(rev_s.begin(),rev_s.end());
        return solvewithTabulation(s,rev_s,0,0);
    }
    int minInsertions(string s) {
        int lcs = longestPalindromeSubseq(s);
        int ans = s.length() - lcs ;
        return ans;
        
    }
};