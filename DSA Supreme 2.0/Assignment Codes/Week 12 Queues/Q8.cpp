//https://leetcode.com/problems/number-of-people-aware-of-a-secret/


//Number of people aware of a secret


/*
Approach -  So is question mai 2 variable leke chalenge

curr - This will be the number of active spreaders
people - Number of people who know the secret ( curr + people in their delay period)

Now 2 queue Mentain Karenge delayQ and forgetQ

delayQ - This will tell ki kitne people current day mai delay period end kar rahe hai
forgetQ - This will tell ki kitne people current day mai secert forget kar chuke hai

so enter the values for day 1 in forget and delay queue: <1,1> 1st day and 1 person

So Now loop from 1 to N :
    1. check if people are forgeting today
        a. forgetQ ke top element ki first value ( the day ) + forget time period = Woh din jab top element wale log secret bhul jaenge
        b. if current day i us din ke equal ya zyada ho jae, then pop() the front after storing in temp variable
        c. temp.second is the number for people who will forget so remove themfrom answer and current
        d. also possible hai hi number of people bahut zyada ho jae islye jaha bhi subtract hora ho + M kar dena , mod mai koi affect nahi padhta
    2. check number of people who end delay period
        a. delayQ ke top element ki first value ie delayQ.front().first + delay = woh din jab top element wale logo ka delay period end hoga
        b. if current day i us din ke equal ya zyada ho jae, then pop() the front after storing in temp variable
        c. temp.second is the number for people who will end delay period so add them in current (active spreader)
    3. check how many spread happened that day
        a. every day current amount of people are active spreader
        b. so add current in answer, as each curr will tell the secret to another person
        c. also add day(i) and current in both deqeue.
*/


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;
        int curr = 0;
        int ans = 1;
        queue<pair<int, int>> delayQ, forgetQ;
        forgetQ.push({1, 1});
        delayQ.push({1, 1});
        for (int i = 1; i <= n; i++) {
            // step1
            if (!forgetQ.empty() && forgetQ.front().first + forget <= i) {
                auto it = forgetQ.front();
                forgetQ.pop();
                int pep = it.second;
                ans = (ans - pep + M) % M;
                curr = (curr - pep + M) % M;
            }
            // step 2
            if (!delayQ.empty() && delayQ.front().first + delay <= i) {
                auto it = delayQ.front();
                delayQ.pop();
                int pep = it.second;
                curr = (curr + pep) % M;
            }
            // step 3
            if (curr) {
                ans = (ans + curr) % M;
                delayQ.push({i, curr});
                forgetQ.push({i, curr});
            }
        }
        return ans;
    }
};