//https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1


/*

Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.
Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30

Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175

*/

/*
Approach - So we need to find the minimum and we are given the unweighted Nodes so simply do BFS

1. Initialize the queue
2. Initialize the visited vector of size 100000 and initial values as -1 , Because 100000 are the Possible nodes we can reach
    also we can store the level in visited only
3. set q.push(start) and visited[start] = 0;

Start ko queue mai daleenge and until Queue is empty :
    1. Get Queue top Node
    2. Now Multiply it with each element the array and mod the result
    3. Now find if this new Node is visited or not
    4. if Not visited then 
        set visited to visited[top] + 1
        push newNode into queue
5. Once BFS is complete we will have answer in visited[end] (it will be storing the level of BFS)
    
*/