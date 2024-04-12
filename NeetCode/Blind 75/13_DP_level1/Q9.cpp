//https://leetcode.com/problems/word-break/description/


/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/


/*
Approach - Step 1: We need to use Recursion + DP 
Step 2: Create a new function with inputs : wordDict , string s , 1 D  DP , string index 
Step 3: FLow of the program : 

    1. BASE CASE - index > string s size 
        return true

    2. DP CHECK - if DP of Index is not -1 return DP of index

    3. NORMAL EXECUTION -   

        1. Ek empty string banao temp
        2. Ab mujhe all possible matches dekhne hai, esa nahi ki ek baar match ho gya toh ushi word ko consider karenge
        islye FOR loop ka use karenge start se end tak 
        3. For Eg - s = "catsandog", wordDict = ["cats","dog","sand","cat","an"]
            Normal hum if statement ka use karte ki agar current index match kar rha ho to next index pe new strign deke waha se ansswer nikal lao
            but above case mai hum hanesha "cat" string ko match karke agar badh jaenge and answer false aega
            but if hum "cats" ko consider kare toh answer true aega
        So this is why we will use a FOR loop and loop from the start to the end of the string

        4. Inside the loop :
            1. get current index character, add this character to the empty string temp
            2. Create a boolean flag initially false
            3. if this string temp is matching a word from the wordDict :
                flag = flag || answer from next indexes
            4. if the string does not match, the do nothing move to the next index and check again
        5. Outside the loop we will have the answer in the flag variable so return flag                

*/