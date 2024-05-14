//https://leetcode.com/problems/gas-station/description/


/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/


/*
Approach - Tho hum ek circular path mai move kar kare hai and hume return karna hai woh index jaha se start karke hum ek circle comple kar sakte hai

So suppose gas = [1,2,3,4,5], cost = [3,4,5,1,2] this is given 
toh if we start from index 0 :
    gas - cost will be negative means we cant reach next station from 0
if we start from index 1 :
    again gas - cost will be negative means we cant reach next station from 1
    So this is how we need to find the station from which we can start to complete the cycle

Brute approach - Har station par start karke dekh lo.
    ek function bana dena jisme ap ek starting point doge and loop lagake har point ke lye woh fucntion call kar dena
    SO this will be a n^2 approach.

    We can have a n approach 

Better approach - So baar baar har point ke lye loop karne se acha, ap ek baar loop karo and ek balance and deficit mentain karke chalo
balance means how much gas we have currently available
deficit means if we have less than 0 balance then how negative it is will be deficit

Approach kya hai ki har point par jaenge and balance calcualte karenge
balance += gas[i] - cost[i]

If at any point balance gets negative, what will that mean ?
    it will mean ki hum jis bhi point se start kare hai usse toh next station that ab nahi pahuch sakte
    toh ab humare new starting point kya hoga ?
        either it can be start + 1 or i + 1
        SO suppose maine 0th se start kare and mai 1st par chale gya 2nd par chale gya but 3rd par nahi ja pa raha
        ie 0 -> 1 -> 2 X 3
        agar mai 0 se 1 gya hu uska matlab hai ki 0 par balance will be positive
        so agar mai 0 + 1 se start kare toh balance aur bhi zyada negative mai nahi jaega kya kyuki 0 wala positive balance toh hum include hi nahi kar rahe
        isilye start + 1 karne ka koi point nahi hai
        therefore New Start will be i + 1.

    so humara balance jab negative hua then hume new point se start kara, therefore start = i + 1.
    ab beacuse we are starting from new point we need to set balance to zero
    but usse pehele balance ki current value kya hogi, it will be a negative number uska matlba hai kitna gas kam hai toh uski
    absolute value ko ek deficit nam ke variable mai add kar lo

    Now after n itrations apke pass ek balance hoga and ek deficit hoga and ek start index mai value hogi
    ab ap yeh check kar lo ki kya humara balce deficit se zyada hai
    if balance is greater than or equal to zero then the cycle is possible hence return start
    otherwise return -1.

*/