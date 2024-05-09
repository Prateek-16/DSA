//https://leetcode.com/problems/permutations/description/


/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/


/*
Appraoch - so to solve this we will use the swap approach, we will swap beacuse suppose we combine [1,3] together the we cannot come back to [2]
because it is bhind 3 and generally we move in one direction when using backtrqacking.
that's why we will swap the numbers using indexes

SO how this will work is :
    first we will move to each index ie from 0 to the end() (index will be passed as a input function)
    then we will loop from that current index to the end() index
    and then swap the current index with each itrative index

    simiply saying :
        suppose we have 2 indexes i and j 
        i will one by one move over each index in the array, then we will have another index j which will move from i to end()
        and then we swap ith index with jth index at each looping interval
        we do a recursive call for the next itration
        then we backtrack the swapped i,j


        Lets understand
        [1,2,3] is given starting mai i = 0 
        then we will move inside the solve function
        waha hum loop karenge from i to end() ie j = 0 to j = 2
            then swap(nums[i], nums[j])   [1,2,3] / [2,1,3] / [3,2,1]
            then recursive call for i = i + 1
            then backtrack ans swap (nums[i], nums[j])

            thats it loop , also base case hogi ki jab i is greater than the size of the array we will stop

        So this is how we need to solve this problem

        basically hum loop karenge for i from 0 to end() and for each loop of i hum ek aur loop karenge of j from i to end()
        inside this 2nd loop we will continuously swap ith and jth values
        then do recursive calls for i + 1 index
        then backtrack our previously swapped values
 
    
*/