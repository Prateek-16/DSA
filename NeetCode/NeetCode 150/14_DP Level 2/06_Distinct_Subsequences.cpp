//https://leetcode.com/problems/distinct-subsequences/description/


/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
*/


/*
Approach - so in this question we can see that we will have a include exclude approach. the main think here is" :
    suppose i and j are 2 pointers on s and t 
    and s[i] == t[j] right so we can include this condition and increase both i and j by 1 for next recursive call
    but what we can also do is not inlcude this condition because its possible that i+1 will also match with j

    so what i want to say is that the exclude case is permanent even if it matches or not match and if it does match we add the recursive answer for that to.

    what are the base cases :
        if j is over means greater than size of the string t : then it must mean that all the characters of t are matched in s hence return 1
        after the first base case if we reach here it means j is not over , so if i is over the return 0 since now the subsequence is not possible


Simple Flow :
    //Inputs : int solve ( s , t , i , j , dp )

        //BASE CASE :
        1. if j is == t.size() ,return 1
        2. if i is == s.size() ,return 0

        //DP CHECK :
        if dp[i][j] != -1 , return dp[i][j]

        //MAIN CASE :
        1. Initialise ans for storing the answer
        2. if(s[i] == t[j]), then ans = recursive call ( i + 1 , j + 1 )
        3. exclude case : ans += recursive call ( i + 1 , j )
        4. return ans and save in the dp
*/