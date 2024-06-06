//https://leetcode.com/problems/reveal-cards-in-increasing-order/description/


// Reveal Cards In Increasing Order



/*
You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].
You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.
You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

Example 1:

Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
*/


/*
Approach - Question is important samajne mai time lag gya tha

So we need to return an ordering such that on doing some operations the cards a in sorted order
toh yaha bottom up sochna , hume esa kuch nahi pata jisse hukm ordering bata sake but we know that final answer needs to be sorted
to sorted array lo and waha se answer ko build karo

for eg : Input - deck = [17,13,11,2,3,5,7]  sorted deck = [2,3,5,7,11,13,17] yeh answer hona chahiye,
toh ek ek karke sorted deck ke [2,3,5,7,11,13,17] har element ke lye sahi position find out karte hai answer array mai.

Toh sahi position kaise find out hogi :
    1. ek queue lo and usme deck size ke indexes dal do,
    2. ab is queue mai wahi operations lagao jo question mai given hai
    3. esa karne par tujhe woh indexes milenge jo serially hum access karne wale hai,
        and we know ki in indexes par hume increasing order mai deck ke elements ko place karna hai
    4. toh jaise jaise indexes mil rahe ho, sorted deck mai ek itrator use karke sorted order mai elements ko place karte jao

Thoda hard to Understand hai question
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size());
        deque<int> dq;
        for (int i = 0; i < deck.size(); i++) {
            dq.push_back(i);
        }
        int it = 0;
        // simulating the indexes
        // step 1 - Reveal
        while (!dq.empty()) {
            int ele = dq.front();
            dq.pop_front();
            ans[ele] = deck[it];
            it++;
            dq.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};