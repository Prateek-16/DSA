//https://leetcode.com/problems/palindrome-pairs/

//Palindrome pairs

class trieNode {
public:
    char val;
    trieNode* children[26];
    int stringNumber;
    trieNode(char val) {
        this->val = val;
        this->stringNumber = -1;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    void insertIntoTrie(trieNode* root, string s, int& stringNum) {
        for (int i = 0; i < s.size(); i++) {
            char it = s[i];
            int index = it - 'a';
            if (root->children[index] != NULL) {
                root = root->children[index];
            } else {
                trieNode* child = new trieNode(it);
                root->children[index] = child;
                root = root->children[index];
            }
        }
        root->stringNumber = stringNum;
    }
    void search(trieNode* root, string& word, vector<int>& ans) {
        trieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int inde = ch - 'a';
            if (curr->stringNumber != -1) {
                if (ispalindrome(word, i, word.size() - 1)) {
                    ans.push_back(curr->stringNumber);
                }
            }
            if (curr->children[inde]) {
                curr = curr->children[inde];
            } else {
                return;
            }
        }
        // if we reach here then over word is over but trie Word is still not
        // over so we will check if remaining characters are palindromic
        string newstr = "";
        search2(curr, ans, newstr);
    }
    void search2(trieNode* curr, vector<int>& ans, string& newstr) {
        if (curr->stringNumber != -1) {
            if (ispalindrome(newstr, 0, newstr.size() - 1)) {
                ans.push_back(curr->stringNumber);
            }
        }

        for (int i = 0; i < 26; i++) {
            if (curr->children[i]) {
                newstr.push_back(i + 'a');
                search2(curr->children[i], ans, newstr);
                newstr.pop_back();
            }
        }
    }
    bool ispalindrome(string& word, int low, int high) {
        while (low < high) {
            if (word[low] != word[high]) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        trieNode* root = new trieNode('-');
        for (int i = 0; i < words.size(); i++) {
            string it = words[i];
            reverse(it.begin(), it.end());
            root->insertIntoTrie(root, it, i);
        }
        for (int i = 0; i < words.size(); i++) {
            vector<int> ans_curr; // this will store all the possible
                                  // palindromic pairs for i ;
            root->search(root, words[i], ans_curr);
            for (auto& it : ans_curr) {
                if (it != i) {
                    ans.push_back({i, it});
                }
            }
        }
        return ans;
    }
};