//https://leetcode.com/problems/word-break-ii/


//Word Break


/*

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

*/


/*
Approach - so we will iterate over string s and match the word at each itration is if the word is matched then
we will we will get the right answer with recursion which will be strings of all possible matches on the right,
then we will one by one iterate over the vector and attach it to the current matched word with a space in between 
*/


class Solution {
public:
    vector<string> solveWithRec(string s, int index,
                                unordered_map<string, bool>& dict) {
        vector<string> ans;
        if (index == s.size()) {
            return {""};
        }
        string word = "";
        // bool flag = false;
        for (int i = index; i < s.size(); i++) {
            word += s[i];
            if (dict.find(word)==dict.end()) { //means word nahi mila
                continue;
            }
            //word mil gya
            auto right_ans = solveWithRec(s,i+1,dict);
            for(auto each_right_ans: right_ans){
                string end_part;
                if(each_right_ans != ""){
                    end_part = " " + each_right_ans;
                }
                else{
                    end_part = each_right_ans;
                }
                ans.push_back(word+end_part);
            }

        }
        return ans;
    }
    unordered_map<int,vector<string>>dp;
    vector<string> solveWithMem(string s, int index,
                                unordered_map<string, bool>& dict) {
        vector<string> ans;
        if (index == s.size()) {
            return {""};
        }
        if(dp.find(index) != dp.end()){
            return dp[index];
        }
        string word = "";
        for (int i = index; i < s.size(); i++) {
            word += s[i];
            if (dict.find(word)==dict.end()) { //means word nahi mila
                continue;
            }
            //word mil gya
            auto right_ans = solveWithMem(s,i+1,dict);
            for(auto each_right_ans: right_ans){
                string end_part;
                if(each_right_ans != ""){
                    end_part = " " + each_right_ans;
                }
                else{
                    end_part = each_right_ans;
                }
                ans.push_back(word+end_part);
            }

        }
        dp[index] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for (auto it : wordDict) {
            dict[it] = 1;
        }
        int index = 0;
        return solveWithMem(s,index, dict);
    }
};