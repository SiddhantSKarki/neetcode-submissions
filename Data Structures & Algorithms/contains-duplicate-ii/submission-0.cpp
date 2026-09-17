class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // brute force
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i!=j && nums[i] == nums[j] && abs(i-j)<=k) {
                    return true;
                }
            }
        }
        return false;
        
    }
};