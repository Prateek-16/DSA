//https://www.geeksforgeeks.org/problems/sum-equals-to-sum4006/1


//Sum Equals to Sum


/*
Given an array A of N integers. The task is to find if there are two pairs (a, b) and (c, d) such that a+b = c+d.

so ek approach ho sakti hai 4 pointers laga le karlo but not good approach

or what we we can do is i = 0 to n (pointer1) then j = i+1 to n (pointer2) and store their sum in a map 
if the sum is repeated then return true else return false;

*/
class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        unordered_map<int,bool>mp;
        //pairs
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int sum = a[i] + a[j];
                if(mp.find(sum) != mp.end()){
                    return true;
                }
                else{
                    mp[sum] = true;
                }
            }
        }
        return false;
    }
};
