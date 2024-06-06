//https://leetcode.com/problems/camelcase-matching/description/


//Camelcase Matching


class Solution {
public:
    bool ismatch(string& ele, string& pattern) {
        int j = 0;
        bool matched = true;
        for (char& c : ele) {
            if (j < pattern.length() && c == pattern[j]) {
                j++;
            } else if (isupper(c)) {
                matched = false;
                break;
            }
        }
        if (matched && j == pattern.length()) {
            return true;
        } else {
            return false;
        }
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            string ele = queries[i];
            if (ismatch(ele, pattern)) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }
        return ans;
    }
};