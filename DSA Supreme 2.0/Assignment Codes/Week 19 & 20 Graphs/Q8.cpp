//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


/*

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

Example 2:

Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.

*/


/*
Approach - So we are Given a list of cities and we need to return ,
the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold.

So kahi na kahi shortest path nikalna hai and make sure karna hai ki us path ka distance maximum distanceThreshold ke jitna ho.

Basic Approach :
1. so dijistra ko loop mai lagange har node ke lye and minute updation karenge dijistra mai
2. Disjistra return karega woh Number of Nodes jo mai source node se reach kar sakta hu within distanceThreshold.
3. if this Ans is less than minimum answer then :
    store this as minimum answer
    and store its index
4. A end of loop return index of minimum answer

Upadations in Dijistra are :
Dijistra - everything will be same we dont want to change disjistra algorithm, we will just add a if statement
    1. Make a variable for reachable cities.
    2. When we take the top Node from the queue The distance of the top Node is final and only its neighbors distances are updated
        so here we will check if this Node distance is <= to distanceThreshold and the Node is Not Src Node (Beacuse its distance will be 0)
        if true : do reachable Nodes ++
    3. At end return reachable nodes

*/