//https://leetcode.com/problems/non-overlapping-intervals/description/


/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
*/


/*
Appraoch - Main task is to find out of the 2 overlapping intervals which one to delete

    So MAIN LINE for this code : Delete that overlapping interval which ends later.
    Because The interval which ends later is more likely to overlap with more intervals also
    and even if it doesn't overlap with any other interval then cant we say with gaurantee that the interval which ends before will also not
    overlap with any other interval.

    This is the main understanding of this question and try to draw these intervals for better understanding

Flow :
    1. Find n the number of intervals
    2. Edge case : if n is 1 or 0 return 0 removals possibles
    3. Now sort the intervals based on starting points
    4. (IMP) Now initialize a variable "prev_end" which will store the end point of previous interval.
        NOTE : previous interval doesn't necessarily means (i-1)th interval, 
        it can possibly be (i - k)th interval because all the middle intervals could have been removed.

        initialize "prev_end" with intervals[0][1] initially.

    5. Initialise a varible to count removed intervals

    6. Loop for i = 1 to i < n
        check if curr interval overlaps prev interval
        cond : intervals[i][0] < prev_end
        if true :
            removed++ (since one interval must to removed)
            
            Now find which interval is to be removed 
            compare intervals[i][1] < prev_end
            if true :
                means prev is ending later so prev need to be removed hence update prev
                prev_end = intervals[i][1]
            if false : 
                means prev is not ending later so intervals[i][1] need to be removed , so no updation needed
        if false :
            means the intervals do not overlap Hence update prev_end
            prev_end = intervals[i][1].

    7. return removed.
*/