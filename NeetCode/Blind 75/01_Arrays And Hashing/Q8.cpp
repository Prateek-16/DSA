//https://leetcode.com/problems/longest-consecutive-sequence/description/


/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

/*
Approach - So one solution can be to sort the array then use pointers to mentsin the longest consecutive elements sequence
but this will be a nlogn approach

Another solution : Step 1 - Enter all the elements in a unordered set where we can search them in o(1) time complexity

Logic - 100,4,200,1,3,2 -> | 1 2 3 4 |  | 100 |  | 200 | we can divide the elements in 3 such sets and we can see that the leftmost element
in each set doesnt have a left-1 elemnt in the array.
ie  4-1 = 3 exist 
    3-1 = 2 exist
    2-1 = 1 exist
    1-1 = 0 dont exist and thus we know 1 is the leftmost element 

    so the algo is to basically find all possible leftmost element (by searching if their left element exist in the array or not)
    if there is no left element then we loop from that element how long the sequence is starting from that element
*/