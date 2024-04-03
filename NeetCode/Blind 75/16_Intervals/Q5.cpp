//https://neetcode.io/problems/meeting-schedule-ii


/*
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), 
find the minimum number of Rooms required to schedule all meetings without any conflicts.

Example 1:
Input: intervals = [(0,40),(5,10),(15,20)]
Output: 2
Explanation:
day1: (0,40)
day2: (5,10),(15,20)

Example 2:
Input: intervals = [(4,9)]
Output: 1
*/


/*
Approach - To find the minimum number of Rooms required to schedule all meetings,
    we need to find the maximum number of meetings happening at the same time.

    1. To do so, we will store the start and end points of the meeting in two vector.
    2. sort both vectors.
    3. Initalize a count variable to count number of simultaneous meeting and a result variable to store the maximum number of simultaneous meeting.
    4. Now place a pointer at start and end vectors [0] element
    5. Now loop until any one of the pointer reaches the end
        1. If start[s_ptr] < end[e_ptr] :
            Means : a meeting is starting before another meeting is ending
            so count++
            result = max (result , count)
        2. If start[s_ptr] > end[e_ptr] :
            Means : a meeting is ending before another meeting is starting
            so count--;
        3. Else :
            Means start[s_ptr] = end[e_ptr]
            This case is not considered as overlapping and we are told that in such case the ending meeting will end first
            so count--;
    6. Once out of the loop :
        return result;
*/