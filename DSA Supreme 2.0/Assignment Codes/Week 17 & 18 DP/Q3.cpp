//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/


//Minimum ASCII Delete Sum for Two Strings


/*
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
*/

/*
Approach - Toh start ese karete hai ki 2 pointers le lete hai i and j dono string ke lye
then hum check karenge ki s[i] == s[j] is true or not:
    1. if true then toh seedha seedha i+1 and j+1 kardo
    2. if not true then :
                        a: ek baar i+1 karo and cost add kar lo
                        b: ek baar j+1 karo and cost add kar do
bas and base case dekhna padhega
base case - manle ek string khatam hui toh dusre string ke jitne bhi bache hue characters hai woh sare add ho jaenge cost mai
*/


class Solution {
public:
    int solveWithDp(string& s1, string& s2, int i, int j,
                    vector<vector<int>>& dp) {
        int cost = 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == s1.size() || j == s2.size()) {
            for (int x = i; x < s1.size(); x++) {
                cost += s1[x];
            }
            for (int y = j; y < s2.size(); y++) {
                cost += s2[y];
            }
        } else if (s1[i] == s2[j]) {
            cost = solveWithDp(s1, s2, i + 1, j + 1, dp);
        } else {
            int cost1 = s1[i] + solveWithDp(s1, s2, i + 1, j, dp);
            int cost2 = s2[j] + solveWithDp(s1, s2, i, j + 1, dp);
            cost = min(cost1, cost2);
        }
        dp[i][j] = cost;
        return dp[i][j];
    }

    int solveWithTab(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        for (int i_ind = s1.size() - 1; i_ind >= 0; i_ind--) {
            dp[i_ind][s2.size()] = s1[i_ind] + dp[i_ind + 1][s2.size()];
        }
        for (int j_ind = s2.size() - 1; j_ind >= 0; j_ind--) {

            dp[s1.size()][j_ind] = s2[j_ind] + dp[s1.size()][j_ind + 1];
        }
        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                int cost = 0;
                if (s1[i] == s2[j]) {
                    cost = dp[i + 1][j + 1];
                } else {
                    int cost1 = s1[i] + dp[i + 1][j];
                    int cost2 = s2[j] + dp[i][j + 1];
                    cost = min(cost1, cost2);
                }
                dp[i][j] = cost;
            }
        }

        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) { return solveWithTab(s1, s2); }
};