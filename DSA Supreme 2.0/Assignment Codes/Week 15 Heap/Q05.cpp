//https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/

//Minimum Difference in sums after removal of elements

/*
Approach -  So we need to Minimize the difference of Left and right divided elements
            to Minimize the difference we can Minimize the Left Sum and Maximize the Right Sum
            only then left_sum - right_sum will be Minimized

            To do do we are using 2 priority queue
            1. For MINIMUM LEFT SUM - we are using max Heap;
            2. For MAXIMUM RIGHT SUM - we are using min Heap;

            and the we are storing the answers in 2 vectors and we will itrate the to find the minimum difference

*/


class Solution {
public:
#define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<ll> prefix(nums.size(), -1);
        vector<ll> suffix(nums.size(), -1);

        // for left side finding the minimum using max heap
        priority_queue<ll> pq;
        ll sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pq.push(nums[i]);
            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == n) {
                prefix[i] = sum;
            }
        }

        //For right side finding the maximum using min heap
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        sum = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            pq2.push(nums[i]);
            if (pq2.size() > n) {
                sum -= pq2.top();
                pq2.pop();
            }
            if (pq2.size() == n) {
                suffix[i] = sum;
            }
        }

        //This is the way to itrate over prefix ans suffix to find the minimum sum difference
        ll ans = LONG_LONG_MAX;
        for (int i = n - 1; i < nums.size() - n; i++) {
            ans = min(ans,prefix[i] - suffix[i + 1]);
        }
        return ans;
    }
};