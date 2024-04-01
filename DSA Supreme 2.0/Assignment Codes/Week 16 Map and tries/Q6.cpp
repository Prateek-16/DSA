//https://leetcode.com/problems/replace-words/


/*Replace words
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. 
For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. 
If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
Return the sentence after the replacement.


Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

*/


/*

Approach - Simple Question hai :
Step 1. Simply har dictionary ke word par traverse karke ek Trie create kar do 
Step 2. trie mai ek check nam ka function hoga
        yeh check hume prefix return karega
        means hume ek word milega input mai and woh word hum check karete jaenge Trie Mai aur kisi bhi node par agar endNode Mil gyi toh newWord return kardenge
        otherwise same word return kardenge

Yeh check function main hai ! 

Step 3. then each word sectence mai se nikalke Trie Node ke Check mai de denge
        agar prefix hoga toh NewWord return hoga
        otherwise same word return hoga

*/


class trieNode {
public:
    char val;
    trieNode* children[26];
    bool isterminal;
    trieNode(char val) {
        this->val = val;
        this->isterminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    void insertIntoTrie(trieNode* root, string s) {
        if (s.length() == 0) {
            root->isterminal = true;
            return;
        }
        char it = s[0];
        int index = it - 'a';
        trieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trieNode(it);
            root->children[index] = child;
        }
        insertIntoTrie(child, s.substr(1));
    }
    string check(trieNode* root, string word, int& index, string& newWord) {
        if (index >= word.size()) {
            return word;
        }
        if (root->isterminal) {
            return newWord;
        }
        char ch = word[index];
        int i = ch - 'a';
        trieNode* child;
        if (root->children[i]) {
            index++;
            newWord += ch;
            child = root->children[i];
            return check(child, word, index, newWord);
        } else {
            return word;
        }
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trieNode* root = new trieNode('-');
        for (auto it : dictionary) {
            root->insertIntoTrie(root, it);
        }
        string word = "";
        vector<string> st;
        sentence += " ";

        for (char it : sentence) {
            if (it != ' ') {
                word += it;
            } else {
                st.push_back(word);
                word = "";
            }
        }
        for (int i = 0; i < st.size(); i++) {
            string newWord = "";
            int inde = 0;
            st[i] = root->check(root, st[i], inde, newWord);
        }
        string NewSentence = "";
        for (int i = 0; i < st.size() - 1; i++) {
            NewSentence += st[i];
            NewSentence += " ";
        }
        NewSentence += st[st.size() - 1];
        return NewSentence;
    }
};