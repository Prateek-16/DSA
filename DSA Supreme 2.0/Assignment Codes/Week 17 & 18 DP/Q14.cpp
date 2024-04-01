// https://leetcode.com/problems/interleaving-string/

//Interleaving String

/*

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

*/

/*

Approach - So we can do this by :
using 3 Itrators on s1 s2 and s3 namely i , j , k and then check if s1i == s3k or s2j == s3k respectively
the main curx will be to use 2 if condition while checking this beacuse :
suppose s1[i] == s3[k]  but also s2[j] == s3[k] so if we use if else statement we can only explore one of the 2 possible conditions 
and that condition might be a false condition but the other one can be a true condition
therefore we will use a if statement and will explore all possible conditions

*/

class Solution {
public:
    bool solveWithMem(string& s1, string& s2, string& s3, int i, int j, int k,
                      vector<vector<vector<int>>>& dp) {
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        bool flag = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            flag = flag || solveWithMem(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            flag = flag || solveWithMem(s1, s2, s3, i, j + 1, k + 1, dp);
        }
        return dp[i][j][k] = flag;
    }
    bool solveWithTab(string& s1, string& s2, string& s3) {

        vector<vector<vector<int>>> dp(
            s1.size() + 1,
            vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, 0)));

        dp[s1.size()][s2.size()][s3.size()] = true;
        for (int i = s1.size(); i >= 0; i--) {
            for (int j = s2.size(); j >= 0; j--) {
                for (int k = s3.size() ;k >= 0; k--) {
                    if (i == s1.size() && j == s2.size() && k == s3.size()) {
                        continue;
                    }
                    bool flag = false;
                    if (i < s1.size() && s1[i] == s3[k]) {
                        flag = flag || dp[i + 1][j][k + 1];
                    }
                    if (j < s2.size() && s2[j] == s3[k]) {
                        flag = flag || dp[i][j + 1][k + 1];
                    }
                    dp[i][j][k] = flag;
                }
            }
        }
        return dp[0][0][0];
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return solveWithMem(s1, s2, s3,0,0,0,dp);
    }
};