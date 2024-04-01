// https://leetcode.com/problems/sliding-window-maximum/description/

// Siding window maximum

/*
Approach -  Make a max Heap and store value and index in the heap {val,index}.
Now whenever poping the top of the max heap (for finding the max of current window)
check if the index belongs in the current window otherwise pop the element.
*/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        // consider first window
        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }
        // store max of first wndow
        ans.push_back({pq.top().first});

        // consider the rest of the window
        for (int i = k; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
            while (pq.top().second <= i - k)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};