//https://leetcode.com/problems/valid-parentheses/description/

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
*/

/*
Approach - So we need to make sure that when we are entering an element in the stack if its a opening bracket or closing
if its a opening bracket : then we should simply pus it into the stack
if its a closing bracket : then we should check if the stack is empty or not 
    if the stack is empty then we should return false as we will have a unmatched closing bracket
    if the stack is not empty we should check the stack top 
        if stack top is a opening bracket of the same type then we should pop it out
        if its not of the same type then we should push the element in the stack

in the end if the stack is empty then we should return true otherwise false 
*/