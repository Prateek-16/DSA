//https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1


//Merge two binary max heap


/*
Simple solution would be to make a new answer vector and copy both vector in it
and then calling the build heap method to build max heap of answer vector.

Build Heap - start from 1st Non leaf Node and heapify each node upto 0 index.
Heapify - check the correct position of current node and heapify each node.
*/


class Solution {
public:
    void heapify(vector<int>& ans, int n, int index) {
        int largest_index = index;
        int left_index = index * 2 + 1;
        int right_index = (index * 2) + 2;
        if (left_index < n && ans[left_index] > ans[largest_index]) {
            largest_index = left_index;
        }
        if (right_index < n && ans[right_index] > ans[largest_index]) {
            largest_index = right_index;
        }
        if (index != largest_index) {
            swap(ans[index], ans[largest_index]);
            index = largest_index;
            heapify(ans, n, index);
        }
    }
    void buildHeap(vector<int>& ans) {
        int n = ans.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(ans, n, i);
        }
    }
    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
        vector<int> ans;
        for (auto it : a) {
            ans.push_back(it);
        }
        for (auto it : b) {
            ans.push_back(it);
        }
        buildHeap(ans);
        return ans;
    }
};