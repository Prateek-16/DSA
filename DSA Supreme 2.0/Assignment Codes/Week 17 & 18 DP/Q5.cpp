//https://leetcode.com/problems/distinct-subsequences/description/


//Distinct Subsequences


/*
Question - Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"

Output: 3

Explanation:
    As shown below, there are 3 ways you can generate "rabbit" from s.
    rabbbit
    rabbbit
    rabbbit
*/

/*

Approach - So question simple hai bas ek crux hai question ka: 
toh hume ek baar match karni hai strings and agar match ho jae toh dono pointers ko age badha do.
and agar chahiye match ho ya na ho s string ke pointer ko badhao

ese kyu kara ??

suppose s = "rrabbbit"  t = "rabbit"
toh agar 1st r of s and t match ho gya then humne i+1 and j+1 kar dya toh 2nd r of s and t toh skip ho jaenga 
isislye usko avoid karne ke lye s ke pointer ko always i+1 karna hi hai 


means agar match hua toh i and j dono +1 honge and i fir aur +1 hoga alag se 

*/


class Solution {
public:
    int solveWithMem(string& s, string& t, int i, int j,
                     vector<vector<int>>& dp) {
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (s[i] == t[j]) {
            ans += solveWithMem(s, t, i + 1, j + 1, dp);
        }
        ans += solveWithMem(s, t, i + 1, j, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveWithTab(string& s, string& t, vector<vector<int>>& dp) {
        for (int i = 0; i <= s.size(); i++) {
            dp[i][t.size()] = 1;
        }
        for (int i_ind = s.size() - 1; i_ind >= 0; i_ind--) {
            for (int j_ind = t.size() - 1; j_ind >= 0; j_ind--) {
                int ans = 0;
                if (s[i_ind] == t[j_ind]) {
                    ans = (ans%1000000007 + (dp[i_ind + 1][j_ind + 1])%1000000007)%1000000007;
                }
                ans = (ans%1000000007 + (dp[i_ind + 1][j_ind])%1000000007)%1000000007;
                dp[i_ind][j_ind] = ans;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        return solveWithTab(s, t, dp);
    }
};
