//https://leetcode.com/problems/combination-sum-ii/description/


/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
] 
*/


/*
Approach - Exactly same as subset sum 2,
we need to make unique combinations of candidate's elements that sum up to the target
so we will start at each index and then from that index we will see all possible combinations with the next elements
if any combination is gound equal to the target we will will store that combination into the result
and move on for the next combination

Process : 
1. Sort the candidate's elements
2. start from index = 0 and then loop over all next indexes to find the possible combinations
    find possible combinations using : backtracking
3. save all possible combination into the rtesult 

also make sure that when we loop over all next elements : remember that ith index element should not be equal to i-1th index element



*/


class Solution {
public:
    void solve( vector<int>&candidates , int target , vector<vector<int>>&ans , vector<int>&v , int index){
        //base case
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0){
            return;
        }
        for( int i=index ; i<candidates.size() ; i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            solve(candidates , target-candidates[i] , ans , v , i+1);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve( candidates , target , ans , v , 0);
        return ans;
    }
};