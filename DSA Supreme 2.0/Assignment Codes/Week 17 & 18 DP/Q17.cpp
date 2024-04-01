// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/


// Minimum Number of Removals to Make Mountain Array


/*
Approach - Toh lets change the question staement a bit to make minimum removals,
we actually need to find the maximum possible mountian array.

then we will subtract the sizes and can get minimum number of removals.

so how to find the maximum possible mountain array
so we know a mountain array will have a peak and on left all numbers will be increasing and on right all numbers will be decreasing

so what we can do is :
1. we can iterate over the given array and consider each element as a peak element 
2. then we need to find the LIS on its left and store it in vector LIS for each element 
3. then LDS(longest decreasing subsequence) on right and store it in vector LDS for each element 
   to find lds we can simple iterate the array in reverse order or even reverse the array for simplicity

so now we have the longest increasing and decreasing sequence for each element as a pivot element 
now we can simply iterate over the array and calculate the maximum length of the mountain array but we need to mind a condition
that will be if and of the lis or lds value is equal to 1 we need to skip that itration 
beacuse in that case there will be no length of lis or lds as the 1 value is of the peak element itself.

then once we get the max size we can subtract it from the array length to find the minimum number of removals

*/


class Solution {
public:
    int solveWithBS(vector<int>& nums, vector<int>& lis) {
        vector<int> ans;
        ans.push_back(nums[0]);
        lis.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
                lis.push_back(ans.size());
            } else {
                int index =
                    lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
                lis.push_back(index + 1);
            }
        }
        return ans.size();
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis, lds;
        solveWithBS(nums, lis);
        reverse(nums.begin(), nums.end());
        solveWithBS(nums, lds);
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = lis[i] + lds[nums.size() - i - 1] - 1;
            if (lis[i] == 1 || lds[nums.size() - i - 1] == 1) {
                continue;
            }
            max_sum = max(sum, max_sum);
        }
        int ans = nums.size() - max_sum;
        return ans;
    }
};