//https://leetcode.com/problems/word-ladder/description/


/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
    ~ Every adjacent pair of words differs by a single letter.
    ~ Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    ~ sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 
*/

/*
Approach - So we are given a wordList and we have to go from Begin Word to End Word using words in the word list following some ristrictions.
Ristictions are : 
    ~ Every adjacent pair of words differs by a single letter.
    ~ Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    ~ sk == endWord

We Know that is a BFS traversal if unweighted graph, the node we reach first is the shortest distance, we will use that concept here.
we need to find the shortest distance to reach from begin word to end word.

1. Create a unorderedSert of the wordList, for easy searching in the set.
2. Create a Queue for BFS traversal with structure pair<string,int> where string = word & int = level/Distance.
3. Push {beginWord,1} in the queue and erase beginWord from the set.

while(queue is not empty)
    So what we will do is :
        1. Get to word and the Level at queue top.
        2. Check if this word is the endWord, if true : return the level.
        3. Loop on every Character in the word, and store the original character
        4. Then set every character from 'a' to 'z' and see if this newword exist in the set or not : 

            If it Exists: we will erase it from the set so that we can't reach this word from any other word because
                in BFS the first time we reach a node it is at the shortest distance so any other time we reach the same node, its distance will be
                more Hence No use to us as we want the shortest distance from begin word to end word.

                also push {newword,level+1} in the queue.

            If Not Exists: No need to do anything as we want the words from word list only.

        5. after the inner loop of 'a' to 'z' ends, restore the original character.
    6. If we reach out of the while Loop, Means out Traversal is completed and the queue is empty
        means the endWord is Not reachable hence return -1.
*/