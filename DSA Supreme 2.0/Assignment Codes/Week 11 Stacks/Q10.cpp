//https://leetcode.com/problems/car-fleet/description/

//car fleet

class Solution {
    static bool mycomp(pair<int,int>&a,pair<int,int>&b){
        return a.first > b.first ;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>comb;
        int n=position.size();
        for(int i=0;i<n;i++){
            pair<int,int>p={position[i],speed[i]};
            comb.push_back(p);
        }
        sort(comb.begin(),comb.end(),mycomp);
        for(int i=0;i<n;i++){
            cout<<comb[i].first<<" "<<comb[i].second<<endl;

        }
        stack<float> st;
        for(int i=0;i<comb.size();i++){
            float time= (target - comb[i].first)/ ((float)comb[i].second);
            cout<<time;
            while(!st.empty() && time>=st.top()){
                st.pop();
            }
            st.push(time);  
        }
        
        return st.size();
    }
};