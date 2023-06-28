#include <vector>
#include <unordered_map>

std::vector<int> findOriginalArray(const std::vector<int>& changed) {
    std::vector<int> original;
    std::unordered_map<int, int> freqMap;
    
    // Count the frequency of each element in changed
    for (int num : changed) {
        freqMap[num]++;
    }
    
    // Iterate through changed to construct the original array
    for (int num : changed) {
        if (freqMap[num] == 0) {
            continue;
        }
        
        if (freqMap[2 * num] == 0) {
            return {}; // Return empty array if 2*num doesn't exist in changed
        }
        
        original.push_back(num);
        freqMap[num]--;
        freqMap[2 * num]--;
    }
    
    // Check if all elements in changed are used to construct original
    for (const auto& pair : freqMap) {
        if (pair.second != 0) {
            return {}; // Return empty array if not all elements are used
        }
    }
    
    return original;
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};
    std::vector<int> original = findOriginalArray(changed);
    
    if (original.empty()) {
        std::cout << "No valid original array exists.\n";
    } else {
        std::cout << "Original array: ";
        for (int num : original) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
