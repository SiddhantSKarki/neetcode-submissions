class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());
        // [-1, -1, 0, 1, 2, 4]
        
        for (int i = 0; i < nums.size(); i++) {
            int currNum = nums[i];
            if (currNum > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] + currNum > 0) {
                    right--;
                } else if (nums[left] + nums[right] + currNum < 0) {
                    left++;
                } else {
                    output.push_back({currNum, nums[left], nums[right]});
                    right--;
                    left++;
                    while (left < right && nums[left]==nums[left-1]) {
                        left++;
                    }
                }
            }

        }
        return output;
    }
};
