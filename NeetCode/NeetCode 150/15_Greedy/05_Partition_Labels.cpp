//https://leetcode.com/problems/partition-labels/description/


/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
*/


/*
Approach - We need divide given string into partitions where:

characters at each partition DOES NOT appear in any other partition
and partition is done such that after concatenating all the parts in order, the resultant string should be s.
then return the length of each partition.

Simple approach hai :
    1. Har character jo string mai hai uska ka last index store kar lo ek vector mai
    2. then ek start varible lo and last variable lo and ek answer vector banao
    3. then loop over the string s with "i"
    4. start and last variable length batange partion ki, toh hume ek cheez pata ki agar koi character ek partion mai a gya toh woh kisi aur mai nahi a sakta
    therefore hume uske partition ki length increase karni padegi, kaha tak ? ie us variable ke last index tak
    5. So since we are loop from i = 0 to end(),
        and initially start and last = 0
        find if last is getting extended ie koi character ka last humare current last se greater a gya
        ie last = max(last, last[s[i] - 'a])
    6. inside the loop only, check if i meet last ie i == last
        this case means that one partion is complete so we will store the length of this in the ans vector (last -start + 1)
        and move start to i+1.

*/