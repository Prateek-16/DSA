// class Solution {
// public:
//     int sortt(vector<int>&nums){
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]==nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
//     int replacement(vector<int>&nums){
//         int i=0;
//         while(nums[i]!=nums[nums[i]]){
//             swap(nums[i],nums[nums[i]]);
//         }
//         return nums[i];
//     }
//     int marking(vector<int>&nums){
//         int n=nums.size();
//         for (int i=0;i<n;i++){
//             int index=abs(nums[i]);
//             if (nums[index]<0){
//                 return abs(nums[i]);
//             }
//             nums[index]*=-1;
//         }
//         return -1;
//     }


//     int findDuplicate(vector<int>& nums) {
//         return sortt(nums);
//         return replacement(nums);
//         return marking(nums);
//     }
// };