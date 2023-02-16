#include <iostream>
#include <vector>

using namespace std;

template<typename ForwardIt, typename T>
void insertionSort(ForwardIt begin, ForwardIt end) {
    for (auto i = begin; i != end; ++i) {
        T key = *i;
        auto j = i;
        while (j != begin && *(j - 1) > key) {
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}

template<typename ForwardIt, typename T>
ForwardIt binarySearch(ForwardIt begin, ForwardIt end, const T& target) {
    auto left = begin;
    auto right = end;
    while (left < right) {
        auto mid = left + (right - left) / 2;
        if (*mid < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return (left != end && *left == target) ? left : end;
}

int main() {
    vector<int> arr = {5,4,3,2,1};
    insertionSort<vector<int>::iterator, int>(arr.begin(), arr.end());
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    int target = 1;
    auto val = binarySearch<vector<int>::iterator, int>(arr.begin(), arr.end(), target);
    if (val == arr.end()) {
        cout << "Target not found in array" << endl;
    } else {
        cout << "Target found at index " << val - arr.begin() << endl;
    }
    
    return 0;
}
