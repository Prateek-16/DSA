//https://leetcode.com/problems/min-stack/description/


/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/


/*
Approach - There can be many ways to implement a min stack :
    1. Recursive + BackTracking
    2. Store min at each step using pair

    i Like the 2nd Approach More :
        1. Make a stack which stores a pair of int to int
            1st int is the value
            2nd int is the minimum value until that point
        2. At any point we can thus find the minimum value by top second
    
Flow : 
    1. initally if stack is empty push <given element , given element>
    2. if not empty : push <given element , min(given element,st.top().second)>
    3. thats it
    
*/