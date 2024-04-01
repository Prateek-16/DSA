#include <iostream>
using namespace std;

//brute force solution 
//time complexity is o(n2)
// bool hasArrayTwoCandidates(int arr[], int n, int x) {
// 	    // code here
// 	    for(int i=0;i<n;i++){
// 	        for(int j=0;j<n;j++)
// {
//     if(arr[i]+arr[j]==x && i!=j){
//         return true;
//     }
// }	   

//Two pointer approach
// Implemetation
// left pointer
// right pointer 
// cursum=arr[left]+arr[right] 
// while loop left<right
// if cursum>target
//   then right --;
// else cursum<taget
//   then left pointer ++;
// if cursum=target then
// return 



// class Solution{
// public:	
// 	// Function to check if array has 2 elements
// 	// whose sum is equal to the given value
	
// 	bool Twopointer(int arr[],int n,int target){
//     int left=0;
//     int right=n-1;
//     while (left<right){
//         if(arr[left]+arr[right]==target){
//             return true;
//         }
//         else if (arr[left]+arr[right]>target){
//             right--;
//         }
//         else {
//             left++;
//         }
    
//     }
//     return false;
// };
    
// 	bool hasArrayTwoCandidates(int arr[], int n, int x) {
// 	    sort(arr,arr+n);
// 	    return Twopointer(arr,n,x);
	    
// 	};
	
// };
// // 	    }
// // 	 return false;   
// // 	}



int main()
{
    
    return 0;
}