//https://leetcode.com/problems/longest-repeating-character-replacement/description/

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice
*/

/*

Approach - The Question is asking for the longest substring containing the Same letter after K updations.

So lets say we keep on mentaining a sliding window which stores the count of characters in the window.
Then from this sliding window we will find the character with the most count, and subtract this count from the length of the window.
on doing this we will get the amount of operations we need to perform to get all the characters in the window of same type,
and this should be less than K.

1. So we will take a sliding window here and will mentain the count of each character in the window.
2. We will mentain a max_count variable which will check the max(max_count , new_entered_char_count).
3. then if ( r - l + 1 - max_count > k ) This means the number of operations are more than K so we need to shorten the window
4. so  we will decrement the count of character at l and move l++, since we cant decrement the count directly on a map,
we will use a vector for mapping the characters
5. once this is done we will store the max size ( r - l + 1) in a variable.
*/ 