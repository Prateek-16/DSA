//https://leetcode.com/problems/implement-queue-using-stacks/description/


//Implement Queue using Stacks


/*
Approach - we will use 2 stacks here
Toh code apni marzi se input optimixzed ya output optimized likh sakte hai

input : stack 1 ke sare elements ko stack 2 mai dal dena...
        then stack 1 mai input lena.
        then stack 2 ke sare elements stack 1 mai dal dena.
        essa karne se new element stack 1 mai sabse neeche hoga.
        
output : Direct stack 1 ke top element ko pop kar do.
 
*/
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop() {
        if (s1.empty()) {
            return 0;
        }
        int n = s1.top();
        s1.pop();
        return n;
    }

    int peek() {
        if (s1.empty()) {
            return 0;
        }
        return s1.top();
    }

    bool empty() {
        if (s1.empty()) {
            return true;
        } else {
            return false;
        }
    }
};