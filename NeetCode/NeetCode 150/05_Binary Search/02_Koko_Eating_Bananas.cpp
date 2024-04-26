//https://leetcode.com/problems/koko-eating-bananas/description/


/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/


/*
Approach - Entirely though by myself dont know if optimum

This line of this question is very important :
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Is line ke wajas se mai sach paya ki agar mai K ko piles ki maximum value le lu toh mai humesha hi sare bananas kha paunga
but ab mujhe is value ko minimize karna hai
so we have :
    start = 1 and end = maxi of piles
    find mid and check if this value of mid as k is possible or not :
        if possible :
            then store it in some variable 
            and set end = mid - 1 and again check. 
        if Not :
            then set start = mid + 1 and again check.
        
        Keep checking until start <= end 
    
    How to check : 
        you have piles , total hours , and K ( bananas eaten per hr )
        can you write a function to tell if you will be able to eat all bananas in given time H, provided you can eat only from one Pile at a time and K max bananas in 1 hr

        HINT :  loop on piles , get ceil of ( piles[i] / float(K) )
                Subract this value from total hours and check if at any point total hours becomes negative
                if it does return false
                and if outside the loop return true
            
*/