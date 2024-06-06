//https://leetcode.com/problems/k-closest-points-to-origin/description/

//K closest point to origin

/*
Solution without heap : 
Step 1 : calculating the distance between point and origin for each point
Step 2 : storing the distance and the index in a hold vector and then sorting the vector based on the distance
Step 3 : accessing the hold vector's top K point's indexes and the storing then in ans vector

*/

class Solution {
public:
    static bool mycomp(const pair<long long, int>& a,
                       const pair<long long, int>& b) {
        return a.first < b.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<long long, int>> hold;
        for (int i = 0; i < n; i++) {
            vector<int> it = points[i];
            long long dis = pow(it[0], 2) + pow(it[1], 2);
            hold.push_back({dis, i});
        }
        sort(hold.begin(), hold.end(), mycomp);

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            auto it = hold[i];
            int index = it.second;
            ans.push_back(points[index]);
        }
        return ans;
    }
};

//************************************************************************************************
/*
Since this is heap week there Must be a Heap solution

so Heap Solution is Not that intutive 
Basically we are Making a Min heap and comapring the points based in the distances
and  then we will pop out top k elements

*/