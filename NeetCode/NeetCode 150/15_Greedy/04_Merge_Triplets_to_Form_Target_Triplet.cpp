//https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/


/*
A triplet is an array of three integers. You are given a 2D integer array triplets, where triplets[i] = [ai, bi, ci] describes the ith triplet. You are also given an integer array target = [x, y, z] that describes the triplet you want to obtain.

To obtain target, you may apply the following operation on triplets any number of times (possibly zero):

Choose two indices (0-indexed) i and j (i != j) and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], triplets[j] will be updated to [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5].
Return true if it is possible to obtain the target triplet [x, y, z] as an element of triplets, or false otherwise.

 

Example 1:

Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. triplets = [[2,5,3],[1,8,4],[2,7,5]]
The target triplet [2,7,5] is now an element of triplets.
Example 2:

Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
Output: false
Explanation: It is impossible to have [3,2,5] as an element because there is no 2 in any of the triplets.
Example 3:

Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and third triplets [[2,5,3],[2,3,4],[1,2,5],[5,2,3]]. Update the third triplet to be [max(2,1), max(5,2), max(3,5)] = [2,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]].
- Choose the third and fourth triplets [[2,5,3],[2,3,4],[2,5,5],[5,2,3]]. Update the fourth triplet to be [max(2,5), max(5,2), max(5,3)] = [5,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]].
The target triplet [5,5,5] is now an element of triplets.
*/


/*
Approach - So basically hume batana hai ki hum target form kar sakte hai ya nahi

Target form karne ki 2 conditions honi chahiye :
    1. ki target ke ith index par jo element ho, woh kisi na kisi triplet ke ith index par bhi hona chahiye
    2. triplet vector mai agar koi bhi esa triplet hai jiska ith index element bada ho target se toh hum us triplet ko kabhi compare / use hi nahi kar sakte,
    because agar hum use use karenge toh woh humare target se badi value hi return karega.

Inhi donon Points ko use karete hue appproach will be :
    1. make a new vector of vector lets say usable
    2. insert only those triplets into usable whose each element is either equal or less than the target vector's elements.
    3. Toh ab humare pas usable vector mai woh sare vectors honge jo hum triplet banane use kar sakte hai, not neccessary though.

    4. Another condition hogi ki ab jo usable vector hai isme kisi bhi ek vector ka ith index target ke ith index se match karna chahiye, 
    tabhi toh hum us triplet ko use kar paenge target form karne ke lye.
    5. so make 3 flags initially set at 0, and we will flip them where there is a match.
    6. Now Itrate on usable vector:
        now for every ith triplet check all 3 of its indexes ie [i][0] , [i][1] , [i][2] if it matches with target[0] or [1] or [2]
        if there is a match then flip there flags
    7. After the loop check if all 3 flags are flipped or set to 1, if true then return 1
        else return 0.

*/