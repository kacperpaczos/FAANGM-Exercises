// Example program
#include <iostream>
#include <array>
#include <unordered_set>
#include <cmath>

template <size_t N>
int firstDuplicateV1(const std::array<int, N>& arr) {
    std::unordered_set<int> seen;
    
    for (int num : arr) {
        if (seen.contains(num)) {
            return num;
        }
        seen.insert(num);
    }
    
    return -1;
}

template <size_t N>
int firstDuplicateV2(std::array<int, N>& arr) {
    for (int num : arr) {
        if(arr[std::abs(num)-1] < 0){
            return std::abs(num);
        }
        arr[std::abs(num)-1] = -arr[std::abs(num)-1];
    }
    
    return -1;
}

int main()
{
    std::array<int, 10> arr = {1, 5, 7, 3, 8, 9, 2, 5, 1, 6};
    
    std::cout << "First duplicate: " << firstDuplicateV1(arr) << std::endl;
    std::cout << "First duplicate: " << firstDuplicateV2(arr) << std::endl;
    return 0;
}