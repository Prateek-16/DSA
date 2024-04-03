// https://leetcode.com/problems/implement-trie-prefix-tree/description/

/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

/*
So we need to inplement a trie class with insert , serach and startWith Functions

Step 1 : creater a class for TrieNode
    2 variables : isTerminal & children[26] all children[i] to NULL

Step 2 : In your class trie :
        Constructor :
            initialize a root pointer, pointing to a new object of trieNode

        insert(string word) :
            initialize a temp pointer, pointing to at Root

            loop on the word :
                convert the character to its index
                check if a trieNode exist at the index in the temp->children[index] array
                    if not then create one
                move temp to temo->children[index]
        
        search(string word) :
            initialize a temp pointer, pointing to root

            for over the word :
                convert the character to its index
                check if temp->children[index] is NULL
                    if true that means the word does not exist so return false
            out of loop:
            return temp->isTerminal 
        
        Startwith (prefix) :
            similar to search except outside of the loop return true.
            
*/