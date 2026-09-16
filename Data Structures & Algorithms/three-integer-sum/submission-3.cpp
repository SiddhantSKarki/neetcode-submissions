class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] > 0) break;
            if (idx > 0 && nums[idx] == nums[idx - 1]) continue;
            int num = nums[idx];
            int idx_l = idx + 1;
            int idx_r = nums.size() - 1;
            while (idx_l < idx_r) {
                int temp = nums[idx_l] + nums[idx_r];
                if (temp > -num) {
                    idx_r--;
                } else if (temp < -num) {
                    idx_l++;
                } else {
                    output.push_back(vector<int>({num,nums[idx_l], nums[idx_r]}));
                    idx_l++;
                    idx_r--;
                    while (idx_l < idx_r && nums[idx_l] == nums[idx_l - 1]) {
                        idx_l++;
                    }
                } 
            }
        }

        return output;
    }
};
