//https://leetcode.com/problems/reducing-dishes/description/


//Reducing Dishes


/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
*/

/*
Approach - We need to maximize this  -  time[i] * satisfaction[i] ...
we kow time will gradually increase from 1 to N.
so what we can do is to sort the satisfaction in increasing order,
so that the dish with the maximum satisfaction will be multiplied with most time.
what else we can do is skip dishes which means we can include or exclude them

so with each i we will either include the dish or exclude it and then will return the maximum.

*/


class Solution {
public:
    int solvewithMem(vector<int>& sat,int i, int time,vector<vector<int>>&dp){
        if(i==sat.size()){
            return 0;
        }
        if(dp[i][time] !=-1){
            return dp[i][time];
        }
        int include = sat[i] * time + solvewithMem(sat,i+1,time+1,dp);
        int exclude = solvewithMem(sat,i+1,time,dp);
        return dp[i][time] = max(include,exclude);
    }
    int solvewithTab(vector<int>& sat){
        vector<vector<int>>dp(sat.size()+1,vector<int>(sat.size()+2,0));
        for(int i = sat.size()-1;i>=0;i--){
            for(int j = sat.size();j>=1;j--){
                int include = sat[i] * j + dp[i+1][j+1];
                int exclude = dp[i+1][j];
                dp[i][j] = max(include,exclude);
            }
        }
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        // return solvewithMem(satisfaction,0,1,dp);
        return solvewithTab(satisfaction);
    }
};