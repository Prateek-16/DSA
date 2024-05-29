#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> countMoreThanNK(const std::vector<int>& arr, int k) {
    int n = arr.size();
    int threshold = n / k;
    std::unordered_map<int, int> freqMap;
    std::vector<int> result;

    // Count the frequency of each element
    for (int num : arr) {
        freqMap[num]++;
    }

    // Find elements with frequency greater than n/k
    for (const auto& pair : freqMap) {
        if (pair.second > threshold) {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main() {
    std::vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    std::vector<int> result = countMoreThanNK(arr, k);

    std::cout << "Elements that appear more than n/k times are: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
