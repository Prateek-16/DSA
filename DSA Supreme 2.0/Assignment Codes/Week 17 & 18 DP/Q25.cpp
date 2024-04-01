//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/


//Minimum Swaps To Make Sequences Increasing


/*
You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. 
The test cases are generated so that the given input always makes it possible.
An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].


Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
*/

/*
Approach - So since it it given that that test cases are generated so that the given input always makes it possible.
So we can say one thing nums1[i] and nums2[i] are strictly increasing only if nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i].
so we will simply check this condition for each itration. 
and if nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i] we will not swap
and if nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i] then we can swap 

so we will find the answers with both conditions and return the minimum of the 2.

So its Mem and Tab approach are a bit different also 
Basically we will make a 2d vector with a swapped 1 or 0 value which will tell if swap is done or not.
i suggest to watch it from youtube Love Babbar


*/

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2) {
        if (i == nums1.size()) {
            return 0;
        }
        int swap = INT_MAX;
        int noswap = INT_MAX;

        if (p1 < nums2[i] && p2 < nums1[i]) {
            swap = 1 + solve(nums1, nums2, i + 1, nums2[i], nums1[i]);
        }
        if (p1 < nums1[i] && p2 < nums2[i]) {
            noswap = solve(nums1, nums2, i + 1, nums1[i], nums2[i]);
        }
        return min(swap, noswap);
    }
    int solvewithMem(vector<int>& nums1, vector<int>& nums2, int i, int p1,
                     int p2, int swapped, vector<vector<int>>& dp) {
        if (i == nums1.size()) {
            return 0;
        }
        if (dp[i][swapped] != -1) {
            return dp[i][swapped];
        }
        int swap = INT_MAX;
        int noswap = INT_MAX;

        if (p1 < nums2[i] && p2 < nums1[i]) {
            swap = 1 +
                   solvewithMem(nums1, nums2, i + 1, nums2[i], nums1[i], 1, dp);
        }
        if (p1 < nums1[i] && p2 < nums2[i]) {
            noswap =
                solvewithMem(nums1, nums2, i + 1, nums1[i], nums2[i], 0, dp);
        }
        return dp[i][swapped] = min(swap, noswap);
    }
    int solvewithTab(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));
        for (int i = nums1.size() - 1; i >= 1; i--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int p1 = nums1[i-1];
                int p2 = nums2[i-1];
                if(swapped){
                    swap(p1,p2);
                }
                int swap = INT_MAX;
                int noswap = INT_MAX;

                if (p1 < nums2[i] && p2 < nums1[i]) {
                    swap = 1 + dp[i+1][1];
                }
                if (p1 < nums1[i] && p2 < nums2[i]) {
                    noswap = dp[i+1][0];
                }
                dp[i][swapped] = min(swap, noswap);
            }
        }
        return dp[1][0];
        }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        // return solvewithMem(nums1, nums2, 0, -1, -1, 0, dp);
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solvewithTab(nums1,nums2);
    }
};