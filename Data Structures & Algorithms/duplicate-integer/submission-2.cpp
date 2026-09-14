class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        for (size_t idx = 0; idx < nums.size() - 1; idx++) {
            if (nums[idx] == nums[idx + 1]) {
                return true;
            }
        }         
        return false;
    }
};