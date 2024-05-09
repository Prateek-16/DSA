//https://leetcode.com/problems/subsets-ii/description/


/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/


/*
Approach - SO we could have done this with simple include and exclude approach but in that case we would encounter duplicates and we want unique subsets only
we can use a set DS for that but lets solve with another method

lets understadn with an example : 
    [1,2,3] - so we can have no element as a subset
        then we can have only [1] as a element
        then we can pair up [1,2] as an element
        then we can paor uo [1,3] as an element

        then we will move on to [2] as a element
        then we will not pair [2,1] as it is same as [1,2]
        then we will pair [2,3] as a element

        then we will move on to [3] as a element

        also we when we pair up [1,2] [1,3] we will call for next index also to pair up for [1,2,3] as a element

        So what we can see here is : 
            that we are taking a index at a time , and then finding all possible pairs it can have with the elements next to it

            how can we find all possible pairs ? we will do this with a for loop
                the for loop will run from index to end()
                    inside the loop we will add the current element in the curr vector as a pair
                    then we will do the recursive call for the next index
                    for example : i am at index = 0 and have the loop pair up [1,2] then i will do the recursive call for the next itration index ie 2
                    at index = 2 the for loop will start from index to end() , and we will add the element at index = 2 in the pair ie [1,2,3]

                    This is how we will form all the sets for a given vector

        So the basic idea is : 
            go to each index and find all possible combitions with that index and the numbers ahead it
            and to find that combition we need a for loop from index to end(), a recursive call for next itrative index, and a backtracking removal
                for eg if we pair up [1,2] then in the next loop we need to pair up [1,3] so we need to pop() also

            Another thing to note is how we will avoid the duplicates ? The reason for duplicates are reapeated numbers like [1,2,2]
            so pair of [1,2a] and [1,2b] will be the same and we will avoid this byt a simple condition ie :
                if in the loop from index to end() with itrator "i" :
                    if nums[i] == nums[i-1], then continue that case

        So this is th efinal approach for this question :
            1. start from index = 0 mentain 2 vectors , 1 for result and 2 for storing the current set of combination
            2. find all possible pair for each index
                to do so :
                    loop from index to the end()
                    pair up with the current index element
                    do recursive call for next itrative index for further combinations
                    backtrack and pop the answer for new pair
                also check before if ith element is same as i-1th element
            3. return answer
*/