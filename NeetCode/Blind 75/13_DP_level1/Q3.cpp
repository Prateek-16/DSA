//https://leetcode.com/problems/house-robber-ii/description/


/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
*/


/*
Approach - Question is simialr its just a circle now , Only 12 condition to take care of :

    1 . so if we rob 1st house we cant rob the last house
    2 . and if we rob the last house we cant rob the first house


    To Handle these conditions we will change the way we will pass the parameter to our function which is similar to previous function :
        1. so if we rob 1st house 
            we will pass : index = 0 , size = n - 2 
                so that we dont consider the last house, and whenever index is > size we return 0 

        2. so if we rob the last house
            we will pass : index = 1 , size = n - 1
                so that we  dont consider the first house.

        then we return the max of botht these results.
*/