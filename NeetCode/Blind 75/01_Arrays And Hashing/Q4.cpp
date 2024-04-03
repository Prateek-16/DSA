//https://leetcode.com/problems/group-anagrams/description/

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/


/*
Approach - Make a map of string , vector<string> [this vector will store anagram string]
So itrate over the strs and store the string in a temp variable
sort the temp variable and then in do 
mp[temp].push_back(org) [orginal is the actual string];
this will create a new entry if not already present in the map
or will append the anagram into the vector

then using a loop itrate over the map and insert all vectors into a answer vector
*/