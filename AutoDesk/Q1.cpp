#include <iostream>
#include <vector>
#include <algorithm>

// Function to count the number of triangles
int countTriangles(std::vector<int> &arr) {
    // Sort the array
    std::sort(arr.begin(), arr.end());
    int n = arr.size();
    int count = 0;

    // Fix the third element one by one and find the other two elements
    for (int i = n - 1; i >= 2; --i) {
        // Initialize two pointers
        int left = 0;
        int right = i - 1;

        while (left < right) {
            // Check if the triplet (arr[left], arr[right], arr[i]) forms a triangle
            if (arr[left] + arr[right] > arr[i]) {
                // If it does, then all elements between left and right also form a triangle
                count += (right - left);
                // Decrement right to check for other pairs
                --right;
            } else {
                // Increment left to check for the next possible pair
                ++left;
            }
        }
    }

    return count;
}

int main() {
    std::vector<int> arr = {10, 21, 22, 100, 101, 200, 300};
    std::cout << "Number of triangles: " << countTriangles(arr) << std::endl;
    return 0;
}
