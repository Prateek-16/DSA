//https://leetcode.com/problems/top-k-frequent-words/


//Top K Frequent Words


class mycomp {
public:
    bool operator()(auto a1, auto a2) {
        if (a1.first == a2.first) {
            return a1.second > a2.second;
        } else {
            return a1 < a2;
        }
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        sort(words.begin(), words.end());
        for (auto&word :words) {
            mp[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, mycomp> pq;
        vector<string> ans;

        for (auto &it : mp) {
            pq.push({it.second, it.first});
        }
        while(k) {
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
            k--;
        }
        return ans;
    }
};