//https://leetcode.com/problems/insert-interval/description/


/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/


/*
Approach - So we already have sorted and disjoint intervals unlike merge interval question, so we just need to insert one interval in it.

2 Possible cases when looping over intervals: 
    1. current interval [i] is not overlapping with new interval 
    2. current interval [i] is overlapping with new interval

Case 1 : If no overlapping is there :
    2 cases :
        current interval [i][1] < new interval [0] ie current interval is completely less than new interval.
        
        current interval [i][0] > new interval [1]  ie current interval is completely greater than new interval.

Case 2 : If overlapping is there :
    means we need to update the new interval [0] and new interval [1].

For eg : intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]] newInterval = [4,8]

    i = 0 :
        [1,2]  &  [4,8] Case1 : No overlapping so simply push in ans.

    i = 1 :
        [3,5] & [4,8] Case2 : overlapping so update new interval [0] and new interval [1]
        newinterval = [3,8]

    i = 2 :
        [6,7] & [3,8] Case2 : overlapping so update new interval [0] and new interval [1]

    i = 3: 
        [8,10] & [3,8] Case2 : overlapping so update new interval [0] and new interval [1]
        newinterval = [3,10]
    i = 4:
        [12,16] & [3,10] Case1: No overlapping so push the new Interval and then copy whole vector afterward

SO this was the dry run.

Flow : 
    1. get n = size of interval
    2. make a vector of vector int as ans
    3. loop from i = 0 to i = n
        1. case 1 : No overlapping ( if and else if case )

            1. case1(a) : Interval[i] completely smaller than new interval (compare interval[i][1] < newInterval[0])
                if true : Simply pushback in ans beacuse there is no updation

            2. Case1(b) : Interval[i] completely greater than new interval (compare interval[i][0] > newInterval[1])
                if true :   1. push the newInterval
                            2. copy whole interval afterwards to ans
                            3. return ans

        2. Case 2 : Overlapping ( else case )
            update NewInterval
                1. newInterval[0] = min(newInterval[0],interval[i][0])
                2. newInterval[1] = max(newInterval[1],interter[i][1])
    
    4. if exiting from loop means size of interval was 0 
        so push newInterval in ans and return ans;

*/