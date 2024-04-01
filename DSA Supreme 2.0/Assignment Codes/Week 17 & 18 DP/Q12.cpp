//https://leetcode.com/problems/stone-game-iii/


//Stone Game 3


/*
Alice and Bob take turns, with Alice starting first.
On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.
The objective of the game is to end with the highest score, 
and the winner is the player with the highest score and there could be a tie.

Example 1:

Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. 
            Now the score of Bob is 7 and Bob wins.
*/

/*
Approach - So we are solving it by a different approach here. 
what we will do is instead of finding the solution idividually for bpth alice and bob
we will find the ans of " Alice - Bob ". if ans > 0 then Alice wins, if Less than 0 then bob wins, if equals to 0 then tie.

So woh kaise hoga

main crux of the code: 


for (int X = 1; X <= 3; X++) {
            if (index + X - 1 >= stoneValue.size()) {
                break;
            }
            total += stoneValue[index + X - 1];
            sum = max(sum, total - solvewithMem(stoneValue, index + X, dp));
        }

here we are iterating form 1 to 3 and then finding the total for each case and then :
we are subtracting the recursive answer ( this answer will be of Bob / next player) 
we are subtracting the recursive answer because we want "Alice - Bob"

*/


class Solution {
public:
    int solvewithMem(vector<int>& stoneValue, int index, vector<int>& dp) {
        if (index == stoneValue.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int sum = INT_MIN;
        int total = 0;
        for (int X = 1; X <= 3; X++) {
            if (index + X - 1 >= stoneValue.size()) {
                break;
            }
            total += stoneValue[index + X - 1];
            sum = max(sum, total - solvewithMem(stoneValue, index + X, dp));
        }
        return dp[index] = sum;
    }
    int solvewithTab(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size()+1, 0);
        for (int index = stoneValue.size() - 1; index >= 0; index--) {
            int sum = INT_MIN;
            int total = 0;
            for (int X = 1; X <= 3; X++) {
                if (index + X - 1 >= stoneValue.size()) {
                    break;
                }
                total += stoneValue[index + X - 1];
                sum = max(sum, total - dp[index + X]);
            }
            dp[index] = sum;
        }
        return dp[0];

    }
    string stoneGameIII(vector<int>& stoneValue) {
        //vector<int> dp(stoneValue.size(), -1);
        int ans = solvewithTab(stoneValue);
        if (ans > 0) {
            return "Alice";
        } else if (ans < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};