class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2) {
            return vector<int> {0, 1};
        }

        size_t idx_l = 0;
        size_t idx_u = nums.size() - 1;

        vector<std::pair<int,int>> maps;
        for (size_t idx = 0; idx < nums.size(); idx++) {
            maps.push_back({nums[idx], idx});
        }
        std::sort(maps.begin(), maps.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        });

        vector<int> idxs_out(2);
        int temp = 0;
        while (true) {
            temp = maps[idx_l].first + maps[idx_u].first;
            if (temp < target) {
                idx_l++;
            } else if (temp > target) {
                idx_u--;
            } else {
                break;
            }
        }
        vector<int> output {maps[idx_l].second, maps[idx_u].second};
        std::sort(output.begin(), output.end());
        return output;
    }
};
