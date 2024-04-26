//https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


/*
Approach - Simple hai, jab bhi operator mile koi then stack ke top 2 elements ko pop karna
        2. un elements par woh operation lagana, and then result ko wapas push kar dena

Flow : 
    1. Create a int stack
    2. Loop over given vector of string intergers with it
    3. if ( it.size() > 1 || isdigit(it[0]) )
        then push into the stack using stoi()
        and continue;
    4. Now if you reach this line of code then it must be a operator
    so get top 2 elements of the stack and apply conditions on the top 2 elements
    and push the result back into the stack
    5. After the loop st.top() will have the final answer

    One thing to know is why we need this condition (it.size() > 1 || isdigit(it[0])) : in short it is for -ve cases

    isdigit() se hume pata lagte hai ki current character ek digit hai ya nahi
        so agar positive case ho toh koi issue nahi hona chahiye 
        but agar -ve case hai toh isdigit(it[0]) will be the -ve sign of the number
        and this function will return false but in reality -ve numbers as also valid
        
        tho isi case ko handle karne ke lye it.size() > 1 this condition was applied, because agar negative number hoga the always size will be more than 1
        also size > 1 means it cannot be a operator also

        this is hoe this condition is helpful
    
*/