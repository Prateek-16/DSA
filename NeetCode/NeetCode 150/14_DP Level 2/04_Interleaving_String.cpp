//https://leetcode.com/problems/interleaving-string/description/]


/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
*/


/*
Approach ( Love Babbar ) - Bhaiya ne yeh question 3D DP se karawaya tha where :
index 1 on s1 was 1st dimension
index 2 on s2 was 2nd dimension
index 3 on s3 was 3rd dimension

Lets revise this method :
    1. simply theeno string par pointers rakho at index 0 
    2. then call solve function

    solve :
        BASE CASE :
            1. if all three pointers are at the end of there respective string the return true

        MAIN CASE :
        suppose i is pointer for s1 , j for s2 and k for s3

        0. initialize a flag variable as false

        1. check if i is inrange of s1 and s1[i] == s3[k] , if true we can consider i 
        and then call for indexes i + 1 , j , k + 1 this call will return a boolean OR this boolean with the flag variable.

        2. check if j is in range of s2 and s2[j] == s3[k] , if true we can consider j
        and then call for indexes i , j + 1 , k + 1 this call will return a boolean OR this boolean with the flag variable.

        3. Finally return flag

Simplly apply Memoization and Tabulation in this approach also 

Better approach will be to solve this using 2 variables only, so we only require i on s1 and j on s2 
    with i and j we can find the k varible on this own and ie k will be at i + j

    so if for s1 we have pointer at i and s2 we have pointer at j then for s3 it will be at i + j


Now Lets write using this approach :
    1. get the length of s1 and s2 as len1 and len2 
    2. check if len1 and len2 do not add upto length of s3, its automatically not possible to interleave the strings so return false
    3. call solve with all strings , ind1 and ind2 initally at 0...

    Solve :
        1. BASE CONDITION :
            if ind1 is at end of s1 and ind2 is at end of s2 then return true

        2. Now initalise a flag as false
        
        3. now check if s1[ind1] is a match with string 3, how to do that ?
            check if ind1 is in range of s1 then check if s1[ind1] == s3 [ind1 + ind2]
            if true then its a match so call the recursive function with ind1 + 1 and ind2 and OR the result with the flag

        4. similarly check for check with s2[ind2] == s3[ind1 + ind2]
            if true then its a match so call the recursive function with ind1 and ind2 + 1 and OR the result with the flag

        5. At last return the result

This is the approach with 2 indexes only and when this code is converted into memoizaiton to tabular approach then there TC will be better.
*/