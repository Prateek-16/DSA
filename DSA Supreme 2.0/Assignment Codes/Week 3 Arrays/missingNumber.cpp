//using binary search


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         int s=0;
//         int e=n-1;
//         int mid = s+(e-s)/2;
//         int ans=-1;
//         while(s<=e){
//             if (nums[mid]==mid){
//                 s=mid+1;
//             }
//             else if(nums[mid]==mid+1){
//                 ans=mid;
//                 e=mid-1;
//             }
//             mid = s+(e-s)/2;

//         }
//         if(ans==-1){
//             return n;
//         }
//         else{
//         return nums[ans]-1;
//         }
//     }
// };

//using xor
//ans=0;
//for(int i=0;i<n;i++){
//    ans=ans^nums[i];
//}
//for(int i=0;i<n;i++){
//    ans=ans^i;
//}
//return ans;
 