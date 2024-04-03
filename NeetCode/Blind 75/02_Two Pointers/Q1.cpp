//https://leetcode.com/problems/valid-palindrome/description/

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

/*
Approach - So we have a inbuild function iswalnum We can use this fucntion to check if a character if alpha numeric or not 
to find to palindrome we will use a single approach of start and end pointers and then compare inwards

if str[start] iswalnum and str[end] iswalnum :
    then check if tolower(str[start]) == tolower(str[end]) : if true then its valid do start++ and end--;
else
    if start is not alnum then start++
    if end is not alnum then end--

simplee!!!!!
*/