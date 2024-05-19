//https://leetcode.com/problems/valid-parenthesis-string/description/


/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
*/


/*
Approach - okay so there is a DP solution for this problem where we consider the '*' as a left bracket , 
a right bracket and a empty string and then we build a decison tree, which returns us if any of the 3 decisions are possible.

but this is O(3^n) approach, and we can optimize it to O(n^3) by using memoization instead but there is a linear solution for this problem

okay so the linear solution is a range based solution
what we will do is :
    we itrate from left to right of the input string s
    and lets say we are mentaining the count of unmatched left bracket
    so whenever we find a left bracket be add to that count
    whenever we find a right bracket we decrease that count, conditionally that count is not zero already
    but what if we find a "*"
        there can be 3 possible cases:
            either the "*" can be a left bracket
            or it can be a right bracket
            or it can be a empty string

        so to consider all 3 of these cases we will make a range based solution, meaning instead of just one left varible we will 
        set min_left and max_left 
        min_left means the minimum left bracket we will have, considering all the "*" as a right bracket
        max_left means the maximum left bracket we will have, considering all the "*" as a left bracket
        and since "*" can also be a empty string we will take the range from min_left to max_left

        meaning the number of unmatched left brackets can range from min_left to max_left, and if 0 falls in this range we will say that 
        unmatched left brackets can be equal to 0 hence true 
        else false

    So lets understand how will we implement this :
    1. initally min_left and max_left are 0
    2. Now loop from 0 to size of the string
        1. if current character is "(" :
            then increment both min_left and max_left
        2. if current character is ")" :
            then decrement both min_left and max_left
            but we need to make sure that min_left cant be negative, why ?
                so basically min_left means that the "*"s in between are taken as right brackets ")" thus decreasing the left brackets
                but if we know that there is no more left brackets then why will we take a "*" as a right brackets purposely
                therefore min_left = max(0, min_left -1)
            but that does'nt means that max_left can't be negative
            max_left means : that all the "*" as considered as a left paranthesis, and even after that if the naturally occuring right paranthesis ")"
            is more than the [ left_para + "*" ], then the string would not be valid
            hence if max_left is negative, return false

            so in step 2 :
                if current character is ")"
                    then decrement min_left and max_left
                    but min_left cant be negative
                    and if max_left is negative then return false
        3. if current character is "*" :
            min_left is decremented as we will consider it as right paranthesis, but again it cant be negative
            max_left is incremented as we will consider it as left paranthesis

    3. after the loop we will have a min_left and max_left
        now if 0 lies within the range of min_left and max_left
        we will return true
        else return false

    min_left is actually minimum unmatched paranthesis sort of
    max_left is actually maximum unmatched paranthesis sort of


*/