//https://leetcode.com/problems/hand-of-straights/description/


/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
*/


/*
Approach - So we are given an array and we need to return id we can divide that array into groups of 'n' size (given) with each number in a group being consecutive

SO one simple check will be if the array size is divisible by the given 'n' if its not then we can not divide the array into groups of "n" size.

Now we need to make sure each group has consecutive number only.

So lets say we have a number = 3, so now 3 can have 3 possible groups ie [1,2,3] or [2,3,4] or [3,4,5] for n = 3
one thing we can say for sure is whatever the value of "n" is the number "1" (possible minimum number of array) will always have only 1 possible group.
ie [1,2,....n]

So now we know that minimum number of the array will always have only 1 possible group

so enter all the numbers in the array into a MAP.
then the first value of the map will be the smallest number (because its sorted)
pick that 1st value as current value
then find if "n" consecutives of this current value are in the map
to do that we use a for loop and loop "n" times from i = 0 to n
    inside this loop :
    if(map[current + i] == 0), return false
    map[current + i]--
So this is done once only and we need to continuously do this until the map is empty
so we will put all this inside another while loop which runs until map is empty
and when we are decrementing the values, if any map[current + i] becomes 0 we will erase it

FLow :
    1. check for size % n 
    2. create the map
    3. while loop until map is empty
    4. get the current value from the map ( is the first value )
    5. loop from i = 0 to n
    6. inside this loop check if map[current + i] exists or not, if not the return false
    7. decrement map[current + i] if it exist. this means we have used it in one group
    8. check if any map[current + i] becomes 0 , then erase it from the map
    9. if out the while loop return true

*/