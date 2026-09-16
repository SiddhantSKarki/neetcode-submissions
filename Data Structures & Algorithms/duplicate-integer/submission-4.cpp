class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // if size <= 1 return true
        if (nums.size() <= 1) {
            return false;
        }
        // sort them in asc order
        // time: O(nlogn)
        // space: O(1)
        std::sort(nums.begin(), nums.end());
        for (size_t idx = 1; idx < nums.size(); idx++) {
            if (idx > 0 && nums[idx] == nums[idx - 1]) {
                return true;
            }
        }
        return false;
    }
};