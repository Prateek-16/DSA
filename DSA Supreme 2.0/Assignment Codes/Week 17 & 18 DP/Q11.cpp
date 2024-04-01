//https://leetcode.com/problems/stone-game-ii/


//Stone Game II 


/*
Approach - so take a integer variable M and itrate till 1 to 2M and these many are the piles of stones one can pick 
so at each step you pick the stone add it to the total and then recursively call ahead.

Also since there are 2 players we are mentaining a bool variable to tell us whose turn is it right now 
we need alice to have the maximum number of stone so we will maximize alice and will minimize bobs result

*/


class Solution {
public:
    int solvewithMem(vector<int>& piles, int index, int M, bool alice,vector<vector<vector<int>>>&dp) {
        if (index >= piles.size()) {
            return 0;
        }
        if(dp[index][M][alice]!=-1){
            return dp[index][M][alice];
        }
        int ans = alice ? INT_MIN : INT_MAX;
        int total_sum = 0;
        for (int X = 1; X <= 2 * M; X++) {
            if (index + X - 1 >= piles.size()) {
                break;
            }
            total_sum += piles[index + X - 1];
            if (alice) {
                ans = max(ans, total_sum +
                                   solvewithMem(piles, index + X, max(M, X), !alice,dp));
            } else {
                ans = min(ans, solvewithMem(piles, index + X, max(M, X), !alice,dp));
            }
        }
        return dp[index][M][alice] = ans;
    }
    int solvewithTab(vector<int>& piles){
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));

        for(int index=piles.size()-1;index>=0;index--){
            for(int M = piles.size();M>=1;M--){
                for(int alice = 0;alice<=1;alice++){
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total_sum = 0;
                    for (int X = 1; X <= 2 * M; X++) {
                        if (index + X - 1 >= piles.size()) {
                            break;
                        }
                        total_sum += piles[index + X - 1];
                        if (alice) {
                            ans = max(ans, total_sum + dp[index + X][max(M, X)][!alice]);
                        } else {
                            ans = min(ans, dp[index + X][max(M, X)][!alice]);
                        }
                    }
                    dp[index][M][alice] = ans;

                }
            }
        }
        return dp[0][1][1];

    }
    int stoneGameII(vector<int>& piles) { 
        //vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        //return solvewithMem(piles, 0, 1, true,dp);
        return solvewithTab(piles);
    }
};