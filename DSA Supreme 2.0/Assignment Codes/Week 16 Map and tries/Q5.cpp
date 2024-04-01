//https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


//Largest subarray with 0 sum


/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Input: N = 8 A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

previous kafi questions se similar hi hai : 
    priority sum ka vector banane ki need nahi hai csum varible se bhi ho jaega
Step 1 - basically ek csum varible bana lo and sum store karte jana usme :
Step 2 - then ek map banao and usme <csum , index > store karte jana 
Step 3 - IF csum == 0 hota hai, then top max(prev_max, current_index +1 );
Step 4 - IF csum Map mai pehele se present hai then -> max(prev_max,current_index - mp[csum]);
*/


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        vector<int>prior_sum(A.size());
        int Max_diff = 0 ;
        for(int i=0;i<n;i++){
            if(i==0){
                prior_sum[i] = A[i];
            }
            else{
                prior_sum[i] = A[i] + prior_sum[i-1];
            }
            if(prior_sum[i]==0){
                Max_diff = max(Max_diff,i+1);
            }
            if(mp.find(prior_sum[i]) != mp.end()){
                int index = mp[prior_sum[i]];
                Max_diff = max(Max_diff,i-index);
                
            }
            else{
                mp[prior_sum[i]] = i;
            }
        }
        return Max_diff;
        
    }
};