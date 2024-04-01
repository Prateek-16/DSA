//https://leetcode.com/problems/russian-doll-envelopes/description/


//Russian doll envelopes


/*

Approach - Question uses the concept of Longest Increasing Subsequence 
So we are given the width and height of the envelopes and we need to calculate the LIS
we will sort the vector based on increasing width and if width are equal then decreaseing height

for ex :(5,5),(6,7),(6,4)  Why is it done like thiss: 
we need the width and height of next > prev envelope so by ensuring sorted width we can only focus on hieght

in case of same width we will choose the maximum height first because only then our condition of :
height [next] > height [prev] whould be most likely true 

only this was the important crux here rest is same are the binary search solution using the lower bound

*/


class Solution {
public:
    static bool mycomp(vector<int>& a , vector<int>&b) {
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int solveWithBS(vector<vector<int>>& envelopes) {
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++) {
            if (envelopes[i][1] > ans.back()) {
                ans.push_back(envelopes[i][1]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) -
                            ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), mycomp);
        for(int i = 0;i<envelopes.size();i++){
            for(int j =0 ; j<2;j++){
                cout<<envelopes[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans = solveWithBS(envelopes);
        return ans;
    }
};
