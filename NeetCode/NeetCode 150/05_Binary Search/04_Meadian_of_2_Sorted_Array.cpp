//https://leetcode.com/problems/median-of-two-sorted-arrays/description/


/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/


/*
Approach - Basically hume 2 sorted arrays diye hai and hume dono ka same rakhke unka median ( middle element ) find karna hai
    main challenge jo hai woh hai ki 2 seperate array hai middle kare milega

    TLDR : 2 arrays hai and unka middle return karna hai, 2 pointers se karenge

    Simple rakhte hai solution :
        1. sabse pehele dono ki size nikal lo and add them
        2. get mid index ie sum / 2 and also get mid index -1 ( in case of even number )
        3. Now humare pas woh indexes hai jaha hume median milega when we merge there 2 sorted arrays, but we dont need to actually merge them
            we can use 2 pointer to traverse through both the arrays in a sorted manner
        4. so mentain a count variable which we will need to see if we have reached the mid index or not,
            then initialize a i and j pointer at 0 on array 1 and array 2
        5. Loop while i < size of array 1 && j < size of array 2
            we will process the smaller index value at each step since it the combined array is supposed to be sorted
            1. if nums1[i] < nums2[j], then :
                check if count is equal to mid index or mid index - 1,
                    if true then assign the value of nums1[i] to mid or mid index - 1 respectively.
                increment count and i
            2. if nums1[i] > nums2[j], then :
                check if count is equal to mid index or mid index - 1,
                    if true then assign the value of nums2[j] to mid or mid index - 1 respectively.
                increment count and j

        6. After the loop, check individually :
        while ( i < nums1.size() )
            check if count is equal to mid index or mid index - 1,
                if true then assign the value of nums1[i] to mid or mid index - 1 respectively.
            increment count and i 

        while ( j < nums2.size() )
            check if count is equal to mid index or mid index - 1,
                if true then assign the value of nums2[j] to mid or mid index - 1 respectively.
            increment count and j
        
        After all this you will have the value of index mid and mid - 1
        now if the total size of both array is odd return mid
        if it is even return mean of of the values



*/