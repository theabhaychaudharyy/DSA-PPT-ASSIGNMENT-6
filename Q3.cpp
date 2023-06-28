#include <vector>

bool validMountainArray(const std::vector<int>& arr) {
    int n = arr.size();
    
    if (n < 3) {
        return false;
    }
    
    int i = 0;

    // Check for increasing sequence
    while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }
    
    // Peak cannot be at the beginning or end of the array
    if (i == 0 || i == n - 1) {
        return false;
    }
    
    // Check for decreasing sequence
    while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }
    
    return i == n - 1;
}

int main() {
    std::vector<int> arr = {2, 1};
    bool result = validMountainArray(arr);
    
    if (result) {
        std::cout << "The array is a valid mountain array.\n";
    } else {
        std::cout << "The array is not a valid mountain array.\n";
    }
    
    return 0;
}
