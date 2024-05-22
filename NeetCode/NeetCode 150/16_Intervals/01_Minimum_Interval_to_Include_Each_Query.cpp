//https://leetcode.com/problems/minimum-interval-to-include-each-query/description/


/*
You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
Return an array containing the answers to the queries.

Example 1:

Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
Output: [3,3,1,4]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
Example 2:

Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
Output: [2,-1,4,6]
Explanation: The queries are processed as follows:
- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
- Query = 19: None of the intervals contain 19. The answer is -1.
- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
*/


/*
Approach - Simple approach will be a O(n * m) approach and its intuitive think about it yourself.

Lets Look up at the Better Approach :
    1. Try to Visualize the intervals and the queries in a number line in sorted order
    2. what if we somehow find all the intervals which belong to one query then we can easily find the smallest size in the using a min heap
    3. But how to do that, also if we find all possible intervals for each querry it will be again a O(n*m) approach, is there something that can be done linearly
    4. Yes, the Answer is in sorting the quries and the intervals based on 1st value

    Lets See :
        1. Suppose i have a pointer "i" which will be used for intervals
        2. then with itrator "j" we loop over sortedQueries :
            1. let curr_query be sortedQueries[j]
            2. Now until the starting point of the "i"th interval is less than or equal to curr_query we will store the interval in a heap
                but dont you think we should also compare the ending point of an interval before storing it in the heap , what if the interval starts and end before the query point
                so yes dont worry we will compare that later
            3. so now we will enter a pair in the heap but not of intervals but of {size of interval , right point of the interval}
                so when you find the starting point of the "i"th interval is less than or equal to curr_query :
                insert the size and the right point of that interval into the min heap
            4. you will know why ?
            5. Now we will have the interval with shortest size on the top of the heap

            6. but it will not be true always that the query will belong to the interval
            suppose my previous query made this heap, now i am on next query so some intervals will not cover this new query
                so one think we know that all the intervals in the heap have there starting point before the prev query
                so simply compare the ending point of the top element of the heap with is the second of the pair { size , right interval }
            7. So basically until the right interval is less than the current query remove it from the heap

        4. Now lets see the flow of the code :
        5. Another thing is we will have to need a map because we are changing the queries psitions by sorting then, so we need to map
            queries[j] to the size of the interval and later form the answer index wise

    
    Flow : ( i will skip the map concept here ) 
    1. sort intervals and query
    2. Make a min heap for pairs { size , right interval }
    3. initialize i = 0 for intervals
    4. loop with "j" on query array
        1. get current query
        2. while interval[i][0] is less than current query :
            insert into the heap { interval[i][1] - interval[i][1] + 1 , interval[i][1] }   // {size, right interval}
        3. while heap is empty or its top.second is less than current query :
            pop the heap
        4. Now either the heap is empty or there is some size of interval on top
        5. check if empty , return -1
        6. otherwise return top.first ie size


    Now this is the flow, inplement the logic of map here :
        basically map [current query with size]
        then loop on original query access there interval size using map ans form the final answer.
*/