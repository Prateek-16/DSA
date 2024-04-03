//https://leetcode.com/problems/maximum-subarray/description/


/*
Given an integer array nums, find the 
subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
*/


/*
Approach : This is a famous algorithm called Kadane's algorithm to solve this in O(n) time complexity

The algorithm says we need to focus on the prefix sum it the prefix sum is -ve then we must discard it from the sub array

so what we will do :
set the first element of the array as result and curr_sum

then loop from index 1 or index N:
    let curr_sum = max(curr_sum + nums[i], nums[i])

        Explaination : so curr_sum is the sum of the previous elements of the subarray 
            in the above code if at any time curr_sum is -ve then it will be replaced by nums[i]
            because curr_sum + nums[i] < nums[i] when curr_sum is -ve.
        
    then we will also mentain a result variable
        result will simply store the max of all the current sums
    so result = max (result,curr_sum)

return result ;


THe question seems simple but the application of curr_sum is important to understand

Again what are doing is :

    1. curr_sum is storing the sum of all elements in our current subarray
    2. result is storing the max of all the current sums.

    3. curr_sum updation :
        at each itration we check previous curr_sum + nums[i] or nums[i] which is greater.

        whenever our previous curr_sum is -ve, then only curr_sum + nums[i] < nums[i]
        and in that case we discard the previous subarray and set curr_sum as nums[i],
        and we have already saved the maximum of among all the subarrays in result.


Approach 2 : 
    we also know the divide and concour approach to this algorithm
        1. we will set start and end points

        2. find the mid point then :
            left_max = call for left 0 to mid-1
            right_max = call for right mid+1 to end
        
        3. ab cross max find karo 

        toh teeno ka jo maximum hoga woh answer return karna hai

        Cross Max find kaise kare ?

            mid se left jao and jo maximum continuous sum ban pa raha hai use store kar lena
            mid se right jao and jo maximum continuous sum ban pa raha hai use store kar lena

            dono sums ko add kar do to cross max mil jaega

        aur ( left_max , right_max , cross_max ) in teeno ka maximum is the answer to return
        

*/