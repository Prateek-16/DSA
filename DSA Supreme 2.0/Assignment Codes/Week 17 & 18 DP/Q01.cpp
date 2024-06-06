//https://leetcode.com/problems/perfect-squares/

//Perfect Squares

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

/*
Approach - Toh basically hume ek number dia gya hai N and hume bantana hai ki woh number kitne number ka perfect square sum hoga.
Toh simple approach yeah hai ki hum 1 se sqrt(n) tak loop karenge and then all possible outcomes nikalenge and usse minimum find kareenge

*/

class Solution {
public:
    int numSquareHelper(int n, vector<int>& dp) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = INT_MAX;
        int sqroot = sqrt(n);
        int i = 1;
        while (i <= sqroot) {
            int perfect_square = i * i;
            int numberofperfectsquare =
                1 + numSquareHelper(n - perfect_square, dp);
            if (numberofperfectsquare < ans) {
                ans = numberofperfectsquare;
            }
            i++;
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquareHelperTab(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            int ans = INT_MAX;
            int sqroot = sqrt(i);
            int start = 1;
            while (start <= sqroot) {
                int perfect_square = start * start;
                int numberofperfectsquare =
                    1 + dp[i-perfect_square];
                if (numberofperfectsquare < ans) {
                    ans = numberofperfectsquare;
                }
                start++;
            }
            dp[i] = ans;
        }
        
        return dp[n];
    }

    int numSquares(int n) {
        //vector<int> dp(n+1, -1);
        int ans = numSquareHelperTab(n) - 1;
        return ans;
    }
};