//https://leetcode.com/problems/ones-and-zeroes/description/


//Ones and Zeroes


/*
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
*/

/*
Approach - Its a simple Question 
First we will change the given string into a integer and then we will do include exclude
we will only include if the zeros and ones after including is more than or equal to zero
and we can alwasy exclude 

then the Max of the two will be the final answer
*/

class Solution {
public:
    void convert(vector<string> strs, vector<pair<int, int>>& newstrs) {
        for (auto it : strs) {
            int zero = 0;
            int one = 0;
            for (auto ch : it) {
                if (ch == '0')
                    zero++;
                else
                    one++;
            }
            newstrs.push_back({zero, one});
        }
    }
    int solvewithMem(vector<pair<int, int>>& newstrs, int m, int n, int i,
                     vector<vector<vector<int>>>& dp) {

        if (i == newstrs.size())
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int zero = newstrs[i].first;
        int one = newstrs[i].second;
        int include = 0;
        int exclude = 0;
        if (m - zero >= 0 && n - one >= 0) {
            include = 1 + solvewithMem(newstrs, m - zero, n - one, i + 1, dp);
        }
        exclude = 0 + solvewithMem(newstrs, m, n, i + 1, dp);
        return dp[i][m][n] = max(include, exclude);
    }
    int solvewithTab(vector<pair<int,int>>& newstrs, int i, int m, int n) {
        vector<vector<vector<int>>> dp(
            newstrs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = newstrs.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    int zero = newstrs[i].first;
                    int one = newstrs[i].second;
                    int include = 0;
                    int exclude = 0;
                    if (j - zero >= 0 && i - one >= 0) {
                        include = 1 + dp[i + 1][j - zero][k - one];
                    }
                    exclude = 0 + dp[i+1][j][k];
                    dp[i][j][k] = max(include, exclude);
                }
            }
        }
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> newstrs;
        vector<vector<vector<int>>> dp(
            strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        convert(strs, newstrs);
        return solvewithMem(newstrs, m, n, 0, dp);
    }
};