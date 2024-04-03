//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/


/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.


Example 1:

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/

/*

Approach - Toh Binary tree ka maximum Path Sum batana hai so isme max length toh nahi nikalenge
but kaise hoga :
toh ek observation hai :
    ki hum kisi node par hai toh waha do option hai :
        1. ki left ya right mai se jo bhi max answer de usme current ko add karle return kar do
        2. ek option hai ki left ya right wala split karo hi mat left + right + node esa kar lo but yeh cheez keval ek node ke lye ho sakti hai

Toh main Logic hai split ya No split (only for one node)
toh logic yeh hai :
1. har node par jaenge and usko No split karenge means (leftans + rightans + node_val) par ise return nahi karna bacause jo left_ans and right_ans use kara hai voh split wala hona chahiye.
    toh return hum is node ka split karenge max(left_ans + right_ans) + root_val.
2. Beacuse hum return nahi kar rahe iske ek maxi variable mai max store kar lenge.

**One Important Point Missing**
Thoda Confusing hai but again karte hai 

Hume maximum path sum nikalna hai, and woh is prakar ban raha hai ki kisi ek node ke lye hum uska left and right add kar sakte hai
but baki sari node fir ya toh left ya right sum lengi.
so either split or noSplit.

1. So lets go to every node and do Nosplit
    means get ( left_sum + right_sum + root->val ) and if greater than maxi then store in maxi.
    but return jo karenge woh split value hogi means max(left_ans + right_ans) + root_val.

2. Now the important point is jab hume yeh kara ( left_sum + right_sum + root->val ) toh yeh possibility hai ki left ya right answer -ve ho
    ho sakta hai agar left Total ya right total negative a jae toh.
    toh is case mai toh ( left_sum + right_sum + root->val ) yeh value root se bhi choti ho jaegi and ise handle karna padhega

3. toh simply check dal dena that (left_ans and right_ans >= 0)
    else left_ans or right_ans = 0, agar negative hai toh consider hi mat karo and 0 kar dp value ko.


Thoda difficult hai question:
4 points hai mainly
1. Return hum Split wali value karenge
2. HarNode par check karenge us node ki no split value ko
3. Ek alag se variable pass ho jo maximum store karega
4. No split nikalte time dhyan rakhna ki left and right answers -ve na ho else consider mat karna and 0 kardena.


*/