//https://leetcode.com/problems/make-array-strictly-increasing/description/


//Make Array Strictly Increasing


/*
Question :
Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
If there is no way to make arr1 strictly increasing, return -1.

Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
*/

/*
Approach - 
*/


class Solution {
public:
#define INF (1e9 + 1)
    int solveWithMem(vector<int>& arr1, vector<int>& arr2, int prev, int ind,
                     map<pair<int, int>, int>& dp) {
        if (ind >= arr1.size()) {
            return 0;
        }
        if (dp.find({prev, ind}) != dp.end()) {
            return dp[{prev, ind}];
        }
        int op1 = INF;
        if (prev < arr1[ind]) {
            op1 = solveWithMem(arr1, arr2, arr1[ind], ind + 1, dp);
        }
        int op2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            int index = it - arr2.begin();
            op2 = 1 + solveWithMem(arr1, arr2, arr2[index], ind + 1, dp);
        }
        return dp[{prev, ind}] = min(op1, op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int, int>, int> dp;
        sort(arr2.begin(), arr2.end());
        int ans = solveWithMem(arr1, arr2, -1, 0, dp);
        return ans == INF ? -1 : ans;
    }
};