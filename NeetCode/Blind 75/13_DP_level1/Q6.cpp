//https://leetcode.com/problems/decode-ways/description/


/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
*/


/*
Approach - So ek decision tree assume karo :
    Har step par humare pass possibly 2 choices hongi :
        1. Jo current index par number hai bas ise hi include karo, yeh choice har time valid ho sakti hai so no conditions on this.

        2. if this condition (current index has 1 || current index has 2 && index + 1 <= 6) :
            is true : then we can include a double digit number.
    
    there are some edge cases also :
        if you encounter a 0 we will return 0

    Base case : 
        if index > size return 1 // 1 possible way found.

    Flow :  1. function solve with parameters (string s , int size , int index)
            2. Base case : 
                if index >= size return 1 (1 possible way found).
            
            3. if s[index] == 0 then return 0 (Not possible Edge case).

            4. intialize a variable result 

            5. 1st choice which is valid for every character : 
                result = solve(index + 1) [basically considering only the current character]
            
            6. 2nd choice for some characters :
                if (index + 1 < size ){
                    if (current index has 1 || current index has 2 && index + 1 <= 6) :
                    result += solve(index + 2) [basically taking a double digit and moving index 2 digits ahead].
                }

            Also try to understand why we need index + 1 < n check for both curr num == 1 or 2

            7. result result.

*/