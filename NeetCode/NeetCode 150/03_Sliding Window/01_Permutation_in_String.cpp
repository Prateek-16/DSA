//https://leetcode.com/problems/permutation-in-string/description/

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
*/

/*
Approach - HashMap + sliding window

    1. Map all characters in s1 to map mp
    2. Initialize left and right pointers to 0
        this is the size of our window
    3. initialize count which is the number of characters we still need to match
        initally count == size of s1

    4.  Dekh Ab hum kya karenge ki jo bhi element humari sliding window mai a raha hoga uske map ki value ko hum minus kar denge
        usse pehele hum ek condition bhi lagaenge ki agar mp mai jo pehele se value padhi hai wph 0 se badhi hai, toh uska mltb hai ki yeh element
        humari string s1 mai bhi hai and s2 mai bhi window ke andar ja raha hai 
        toh count ko kam kar do.
        Now mp ki value ko decrease kar dena and right aghe badha dena, 
        Simple cheez hai window ke andar jab bhi element aega uski map ki vlaue ko decrese karenge and when leave karega uski map ki value ko increase karenge
        Now cheack kar lo kahi count 0 toh nahi ho gya, because if ho gya then return true
        Now check for when window is full ie right - left == s1.size()
            if window is full we need to remove the elements from the left
            remove karene se pehele ek condition dekh lena,jis element ko remove karne wle ho uski map ki value
                agar value negative hai toh uska matlab woh extra element tha so koi issue nahi aega remove karne hai, seedha uski vlaue map mai
                badhake left ko age badha sakte hai
                but agar value 0 ya positve hai, then it means wo ek matching element tha
                toh usko remove karne se pehele count ko increse karna padhega , and then remove kar sakte hai 
        after the loop return false, no substring match found


    4. Now loop until right < s2.size()
        1. if mp.count(s2[right]) > 0,
            then count--

        also mp[right]-- && right ++ (for all cases)

        2. if count == 0 
            then return true (all characters match)
            
        3. if the window size is equal to s1 size we need to move the window
            for that we need to move left
            if left map value is greater than or equal to 0 , then we need to increse the count
            also increase the mp[left]++ && left++ (for all equal size cases).
    5. if outside the loop return false.

            
*/
