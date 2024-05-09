//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/


/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/


/*
Approach - So question is similar to the previous ones 
hume digits di hai and jaise ek phone ke keypad mai unse alag alag combinations ban sakte hai waise hume batana hai kitne combination hum bana sakte hai

So our steps will be : 
    1. ek map / vector bana lo mapping ke lye so that hum digits ke words ko access ka sake 
    string mapping[] = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};

    Toh esa kuch bana lenge
    2.Now main function mai chalte hai : inputs index , output vector , string current , digits , mapping

    toh kaise yeh function work karega :
        hum digits par itrate karenge and har ek digit ke lye mapping se words nikal ke le aenge,
        uske baad hume un words ko match apni already bani hui string mai add karna hai and sare words ko alag alg comboination mai add karn ahai

        So basically :
            hum index wali digit access karenge, use integer mai convert karenge
            then mapping mai uske corresponding words list find karenge
            then us word list mai itrate karenge and ek ek character ko apni current string mai add karenge 
            then recursive call kardenge next index ke lye
            then backtrack karenke and purane character ko hata denge, so that next loop mai new character insert kar sakte hai
            
*/