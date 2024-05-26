// https://leetcode.com/problems/target-sum/description/

/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
*/

/*
Approach - so we have 2 approachs here :
    1. one will be a simple O(n^2) appraoch were we will use a index and a curr_sum variable
    2. at each index we will consider both possible options which is to add it to curr_sum variable or to subtract it from curr_sum variable
    3. lastly we will return the sum of both to find the total possible solutions
    4. base case for this approach will be :
        1. that firstly index much cover all the elements in the array 
            and if it does then the curr_sum should be equal to target, if true then return 1 else 0
    
    THIS IS NOT THE BEST SOLUTION BUT MOST INTIUTIVE :
        1. Add Memoisation to it using a map<pair<int,int>,int> dp where 
            pair = {index,curr_sum} = number of possible subsets.
        2. Change this to a Tabulation solution :
           Things to keep in mind :
            1.  base case will be derived from above cases conbined ie is {nums.size(),0} then set it to 1
            2.  Loop 1 will be for index that is from n-1 to 0
            3.  Loop 2 will be for curr_sum that is from -Total to +Total
                see total means sum off all the elements in the array given , at most we can add them all or subtract them all
                therefore curr_sum range from -Total to +Total
            
            4. Inside Both Loops since we have using map we will use find function to see it exist in dp or not 
            if it does we save it in the varible if not we save 0
                but what is it ? 
                    it will be the index variable and the curr_sum which are changing and we will get them using recursive solutions
            5. save the sum of both the options ie add sign and subtract sign
            6. Lastly return the answer at {0,target}

    THIS WAS THE DP APPROACH 
    Another O(n*m) solution for this problem is (recommended) :
        Basically see the add sign and subtract sign as a subset
        let s1 = all the elements in the array with add sign
        let s2 = all the elements in the array with subtract sign

        so what we can say is :
            s1 + s2 = total_sum of the array
            s1 - s2 = Target value

            add both equations and you will get s1 = (total_sum + target) / 2

            basically s1 humare sare positive numbers ka subset hai and hume us subset ki value mil gyi hai ie s1 = (total_sum + target) / 2

            so kya yeh question ab different nahi ho gya ? means agar hum s1 ko new target lekar yeh find karle ki kitne baar hum given array ke elements re s1 target sum bana sakte hai
            woh hi humara answer hoga !!!

            also a few edge cases we need to consider :
                1. total_sum + target can never be less than 0  ( lets say target is -ve so at most it can be negative upto total_sum not more)
                2. total_sum + target can not be odd ( tabhi toh divide by 2 kar paoge )

            so now the question is : 
            we are given a target ( s1 ) and a input array and we need to tell how many times we can make target using the elements in the input array

            isko solve karne ke lye :
            ek curr_sum lelo , ek target lelo , ek index lelo, and ek input array le lo

                iska base case important hai :
                    mostly harkoi check lagega ki if target == curr_sum return 1, but imaging karo agar target == curr_sum and current index element was 0
                    toh yar 0 ko toh include bhi karo ya exclude dono cases mai target will be == curr_sum toh return 1 nhi 2 karna chahiye tha.

                    toh is 0 wale case ko handle karne ke lye iska base case is different, but simple :)
                    BASE CASE :
                        1. pehele index ko complete karne do end tak array ke (by doing so we will not miss any 0's)
                        2. the check kar lo if target == curr_sum return 1 else 0. ( That it !! )

                    MAIN CASE :
                        1. Include : even though hum har case mai include kar sakte hai but ek condition se faltu ke recurive call kaam kar sakte hai
                        so condition is to only include agar current index element + curr_sum will be equal to or less than the target. because ek baar target ko sum ne cross kar liya then toh return mai 0 hi ana hai
                        so this will be the condition 
                        also the function call will be like index + 1 and curr_sum + nums[index]

                        2. Exclude : no special condition here simply do :
                        the function call like index + 1 and curr_sum

                        3. Now since we want to total ways we can achieve the target sum, therefore return the sum of include and exclude

*/