// ✅Inversion count in Array using Merge Sort

Problem Statement:
If the array is already sorted, then the inversion count is 0, 
but if the array is sorted in reverse order, the inversion count is the maximum. 

Given an array arr[]. The task is to find the inversion count of arr[]. 
Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.


Example 1:
Input: arr[] = {8, 4, 2, 1}
Output: 6
Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

Example 2:
Input: arr[] = {1, 20, 6, 4, 5}
Output: 5
Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 

Example 3:
Input: arr[] = {1, 2, 3, 4}
Output: 0
Explanation: Given array has 0 inversions because array sorted in ascending order.


#include <bits/stdc++.h>
using namespace std;

// This function merges two sorted subarrays
// arr[l...m] and arr[m+1 .. r] and also counts
// inversions in the whole subarray arr[l..r]
int countAndMerge(int arr[], int l, int m, int r)
{
    // Counts in two subarrays 
    int n1 = m - l + 1, n2 = r - m;
  
    // Set up two arrays for left and
    // right halves
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
  
    // Initialize inversion count (or result)
    // and merge two halves
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
      
        // No increment in inversion count
        // if left[] has a smaller or equal
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
      
        // If right is smaller, then it 
        // is smaller then n1-i elements
        // because left[] is sorted
        else {
            arr[k++] = right[j++];
            res = res + (n1 - i);
        }
    }
  
    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
  
    return res;
}

int countInv(int arr[], int l, int r)
{
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;
      
        // Recursively count inversions
        // in the left and righ halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
      
        // Count inversions such that greater
        // element is in left half and 
        // smaller in right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

// Driver code
int main()
{
    int arr[] = { 2, 4, 1, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countInv(arr, 0, n - 1);
    return 0;
}
