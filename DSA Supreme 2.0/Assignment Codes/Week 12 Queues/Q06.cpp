//https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/


//Find the winner of the circular game


/*
Approach - So simple hai ek circle mai 'n'  bachhe baithe hai and har round mai kth bache will be out.
so what we do is implement a queue and enter the 'n' integers in the queue
then frm front pop K integers and push then back to the queue
then the last element of the queue will be the kth element so pop it.
repeat until only one elemnt is left
*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> dq;
        for (int i = 1; i <= n; i++) {
            dq.push_back(i);
        }
        while (dq.size() != 1) {
            int temp = k;
            while (temp) {
                int ele = dq.front();
                dq.push_back(ele);
                dq.pop_front();
                temp--;
            }
            dq.pop_back(); // deleting the kth element
        }
        return dq.front();
    }
};