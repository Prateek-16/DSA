//https://leetcode.com/problems/edit-distance/description/


/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/


/*
Approach - Simple Pointers use karne hai suppose :
    i is for s1 and j is for s2 both at index 0

    //Base Case (important):
        if i is out of s1.size():
            check the distance between j and s2.size() and return this distance, because if there is string left in s2 we can use insertion in s1 to make them equal which is 1 operation per character

        if j is out of s2.size();
            check the distance between i and s1.size and return this distance, because is s2 is complete all the remaining characters in s1 will be removed only which is 1 operation per character

    //Main Case :
    
    Check if s1[i] == s2[j] then it is a match so increase both pointers ( i + 1 , j + 1 ) for recursive call, and return the recursive answer.

    else {
        Now we have 3 options :
        1. Insert :
            let s1 = horse and s2 = ros at i = 0 and j = 0 both are not equal, lets say we try to do insertion,
            s1 = rhorse and s2 = ros , now i will be point at "h" becaus insertion is done before the current index point and j will be at "r"

            so we need to increment j for next recurive call

            thus for insertion ie op1 = 1 + recurive call for ( i , j + 1 )   // + 1 is for current operation of insertion

        2. Remove :
            now lets say s1[i] != s2[j] , so we conpletely remove s1[i] from the string

            thus for removal ie op2 = 1 + recursive call for( i + 1 , j )   // + 1 is for current operation of removal

        3. Replace :
            suppose s1[i] != s2[j] , so another option is to replace s1[i] wirh s2[j]
            so this will make both of them equal,

            this for replace it op3 = 1 + recursive call for ( i + 1 , j + 1 )  // + 1 is for replacing operation

        ans finally since we want the minimum number of operations return the minimum of the 3 options.

    }
*/