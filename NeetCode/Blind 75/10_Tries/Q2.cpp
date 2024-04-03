//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
*/

/*
Approach - So the Insert Function is simlar to prev one

the search functions need updation

if there is a '.' then this should be considered as any character in the search function

Step 1: so when we encounter a '.' we will go in a loop and check for all possible children Nodes if the word forms or not

    thats it !! We need to write a recursive function passing a root node

Step 2 : Then check if word[0] == '.'
        if true : 
        loop from 0 to 25, and if for any case Temp->children[i] is Not null :
        do a recursive call for temp->children[i].
        Now if there is a single true fro, 0 to 25 we need to return true.
        so use a flag and || operator to check if any is true.

        if false : 
        then its the same 
        get the index of the character, and see if the children exist at that index
*/