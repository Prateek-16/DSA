//https://leetcode.com/problems/minimum-cost-for-tickets/description/


//Minimum Cost For Tickets


/*
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
*/


/*
Approach - Simple approach hai Har ek Day yani day 1 , day 3 , day 20 ek ek karke lenge and then recursive call kar denge
then 3no options ka minimum find kar lenge
*/


class Solution {
public:
    int mincostTicketsMem(vector<int>& days, vector<int>& costs, int i,
                          vector<int>& dp) {

        if (i >= days.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        // 1 day pass
        int cost1 = costs[0] + mincostTicketsMem(days, costs, i + 1, dp);
        // 7day pass
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost2 = costs[1] + mincostTicketsMem(days, costs, j, dp);
        // 30days pass
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost3 = costs[2] + mincostTicketsMem(days, costs, j, dp);
        dp[i] = min(cost1, min(cost2, cost3));
        return dp[i];
    }

    int mincostTicketsTab(vector<int>& days, vector<int>& costs, int i,
                          vector<int>& dp) {
        int n = days.size();
        dp[n] = 0;

        for (int index = n-1; index >= 0; index--) {
            // 1 day pass
            int cost1 = costs[0] + dp[index+1];
            // 7day pass
            int passEndDay = days[index] + 7 - 1;
            int j = index;
            while (j < days.size() && days[j] <= passEndDay) {
                j++;
            }
            int cost2 = costs[1] + dp[j];
            // 30days pass
            passEndDay = days[index] + 30 - 1;
            j = i;
            while (j < days.size() && days[j] <= passEndDay) {
                j++;
            }
            int cost3 = costs[2] + dp[j];
            dp[index] = min(cost1, min(cost2, cost3));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return mincostTicketsTab(days, costs, 0, dp);
    }
};