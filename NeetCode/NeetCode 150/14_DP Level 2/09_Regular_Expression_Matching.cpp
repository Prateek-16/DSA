//https://leetcode.com/problems/regular-expression-matching/description/


/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/


/*
Approach -
So the "." will be any one of the characters so there is no choice in case of "."
the main complexity here is becuase of "*"
suppose we have "a*" then this means "a" can be repeated any number of times and even 0
therefore s = "aa", p = "c*a*"  this will be true because "c*" will become 0 ie " " and "a*" will become "aa".

So the main complexity here is because of the "*"

Lets solve this step by step :
    suppose we have 2 pointers i at s[0] and j at p[0] 
    s string needs to be compeletey matched with p 
    there are 3 cases : both i and j are out of index : then its a successful match.
    if i is out of index and j not out of index : then we still cant say anything becuase we might have a "*" in j which will become 0.
    if i is in index and j is out of index : then we can for sure say that it is NOT possible to match.

    so // Base Case :
        if ( i and j both out of bound ) return true
        if( j out of bound ) return false

    // Do a DP check ( make a 2D dp ) 

    // Main case :
        we want to see if there is a match between current i and j index character or if j index character is a "."
        so ifmatch = ( i < s.size() && s[i] == p[j] || p[j] == '.' )

        Now we have check if next index of j is a "*"
        so check if j + 1 is in bound and if p[j+1] is a "*":
            then , now we have 2 case either take "*" as nothing or repeat the character so we will do this with pointer only 
            case 1 = recursive cal ( i , j + 2 )    //taking the "*" as nothing
            case 2 = recursive cal ( i + 1, j )     // Repeating the "*"
            also remember that we can only do case 2 if the match is true so 
            case 2 = ismatch && recursivee call ( i + 1 , j + 1 )
            return the case1 || case 2
        so now if this not a "*" case , then simply check if match is true :
            if true : then its a simple string match so do  recursive calls for next indexes
            recursive call ( i + 1 , j + 1 )

        // If we reach here that means neither the current indexes matches not it a start case where can can neglegt it so 
        simple return false

Add a simple 2 dp in this solution. 


*/