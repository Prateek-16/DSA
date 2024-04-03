//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

/*
Approach - So basically we are going to implement a sliding window solution
our sliding window should be such that it only have distinct continous elements
SO HOW TO IMPLEMENT :
1. set left and right to 0 and then itrate until right is out of bounds
2. mentain a unordered set of characters (set automatically maps the input with its index)
3. for each itration check if the current character is already in the  set.
    if it is present then erase from left until the character is not present in the set
    if not present then calculate the size of the window ( right - left + 1) and add the character in the set
4. now mentain a max size variable which will store the maximum size of the window.


So another way to do this and save a few itration will be :
    1.instead of erasing one character at a time from left we can directly jump the left to the next index of the matched character
      but for that we need to store the index of each travelled character.
    2.Also we need to make sure since we are not clearing the map, so it is possible that some character which is at the left side of left
      is still in the map and is matched, to to avoid this we take the max of current left or the next index of matched character
    3.by doing so we will save a while loop in step 3 if condition.

2nd method is bit comfusing so apply method 1 which is a direct sliding window method using a set.
*/