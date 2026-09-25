class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        for (int idx = 1; idx < nums.size(); idx++) {
            if (idx > 0 && nums.at(idx - 1) == nums.at(idx)) {
                return true;
            }
        }
        return false;
    }
};