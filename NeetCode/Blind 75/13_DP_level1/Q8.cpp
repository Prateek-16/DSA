//https://leetcode.com/problems/maximum-product-subarray/description/


/*
Given an integer array nums, find a 
subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/


/*
Approach - This approach is difficult to explain,
    Dekho agar sare number positive hote tab toh koi issue hi nahi tha but negative also exist
    so that makes this problem difficult 

    so brute approach will be to find all possible subarrays and the return the length of the maximum

    But this will not be a very optimum solution 

    so if we want to find the maximum product subarray in a optimum  manner 
    what we will do is find the maximum product and the minimum product at each iteration

    Humne 2 extreme point find kar lye hai , ab suppose ek new number ko maximum subarray add karna hai
    toh yeh new number sabse zyada in extreme points ho hi toh affect karega , beech ke points affect honge but utne nahi honge ki extreme se zyada ho gye

    isilye hum kar step kar minimum and maximum calculate karte chalenge, beacuse wohi sabse zyada affect honge
    so starting mai toh :
        minimum and maximum = nums[0] 
        Then loop from i = 1 to i = nums.length
            calculate minimum and maximum for each new added point and mentain a result variable to store the maximum result

        Why we need minimum ?

        suppose, maxi = +ve , mini = -ve and new point is -ve 
            so on multiplying , 
            maxi wll be become minimum
            mini will become maximum

        Now how to calculate the minimum and maximum ?
        temp = maxi
        maxi = max of(max of(maxi * current , mini * current) , current )

            max of(maxi * current , mini * current) , yeh toh samaj a raha hoga ki -ve and +ve mai se jo bhi maximum hai use store kar lo
            but yeh max of current kyu kara iska reason hai 0 wala case ! Khod sochna isko
        
        mini = max of(min of(temp * current , mini * current) , current )

            min of(temp * current , mini * current) , yeh toh samaj gye kyu kara
            but max of current kyu kara iska reason hai 0 wala case ! Khod sochna isko

        result = max of result , maxi 

    after loop return result


    

*/