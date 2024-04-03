//https://leetcode.com/problems/minimum-window-substring/description/

/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" include  'A', 'B', and 'C' from string t.
*/

/*
Approach - Toh year question ka code bahut pyara hai isme counter naam ke variable kom bahut ache se use kiya hai

SO lets build a solution by BRUTE FORCE:
    1. Map all characters in string t
    2. Take 2 variables l and r and make a window using them 
    3. Then map all the characters in string window using another map
    4. Then check if freq of each element in t is also present in window map
        if true then store the size and try to compress the string by moving l and remove old entery from map
        if false then move r and enter new entery in window map
    
rather simple to understand by the problem with this solution is again and again we will check for the size of t,
basically we will need to itrate on characters in string t again and again whenever a new entry needs to be checked and this is given TLE.

so BETTER SOLUTIOn

then main implementation will be similar we just need to find some way to not check again and again for whole string t.
so how we can do this is :
    1. We will loop from r = 0 to r < s.size() :
    2. we can mentain a counter variable, which denotes the number of characters in string t and must be in s also
    3. while looping if mp[s[r]] > 0 then we will decrease the counter Beacuse this condition means that s[r] is present in t,
       hence we have matched a character so we will decrease the counter.
    4. then for every mp[s[r]] we will do -- : because suppose if we have already matched once then we need to decrement the frequency,
       or for those characters whose frequency are already 0 they will be negative but it doesn't matter.
    5. also do r++
    6. then if counter == 0 ( this will mean that all characters in t are matched and are present in current substring ). 
       so now we need to reduce the size of substring, so when the characters where geting added into the substring the map was decremented 
       therefore now when we are removing them, they should be incremented in the map.
       mp[s[i]]++ & i++ 
    7.The for any mp[s[i]] if it becomes greater than 0 then it means some character which was a match with string t is removed,
      Hence Counter will be incremented.

    So this was the main beautiful approach and along with this loop just save a min start and a min length continously.
    so that at the end we can give the substring
*/