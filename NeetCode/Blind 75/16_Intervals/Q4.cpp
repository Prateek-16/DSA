//https://neetcode.io/problems/meeting-schedule


/*
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), 
determine if a person could add all meetings to their schedule without any conflicts.

Example 1:

Input: intervals = [(0,30),(5,10),(15,20)]

Output: false

Explanation:
(0,30),(5,10) and (0,30),(15,20) will conflict
*/


/*
Approach - Simply we need to check if there will be a conflit in the intervals

1. Sort the intervals
2. Loop from 1 to n
3. if intervals[i][0] < intervals[i-1][1]
    this means conflict , hence return false
4. After loop ends , return true
*/