class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        sort(nums.begin(), nums.end());
        for (int idx = 0; idx < nums.size() - 1; idx++) {
            if (nums.at(idx) == nums.at(idx + 1)) {
                return true;
            }
        }
        return false;
    }
};