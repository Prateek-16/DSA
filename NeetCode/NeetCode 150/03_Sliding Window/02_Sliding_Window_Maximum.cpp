//https://leetcode.com/problems/sliding-window-maximum/description/


/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/


/*
Approach - So we need to return the max in the sliding window for each time the window moves
Steps:
    1. Make a deque
    2. Enter the first k elements indexes such that whenever you enter a element there is no element smaller than that in front of it.
    (there is a reason why we will insert the indexes and not the element itself)
    3. Now the very front element of the queue will be the largest of the first K elements
    4. Now process the rest of the array
        1. Removal of out of index elements
        2. insertion of new element
    5. Process the last window
*/