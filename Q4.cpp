#include <vector>
#include <unordered_map>

int findMaxLength(const std::vector<int>& nums) {
    std::unordered_map<int, int> sumMap;
    int maxLength = 0;
    int runningSum = 0;
    
    sumMap[0] = -1;
    
    for (int i = 0; i < nums.size(); i++) {
        runningSum += nums[i] == 0 ? -1 : 1;
        
        if (sumMap.find(runningSum) != sumMap.end()) {
            int length = i - sumMap[runningSum];
            maxLength = std::max(maxLength, length);
        } else {
            sumMap[runningSum] = i;
        }
    }
    
    return maxLength;
}

int main() {
    std::vector<int> nums = {0, 1};
    int maxLength = findMaxLength(nums);
    
    std::cout << "Maximum length of a contiguous subarray with equal number of 0s and 1s: " << maxLength << std::endl;
    
    return 0;
}
