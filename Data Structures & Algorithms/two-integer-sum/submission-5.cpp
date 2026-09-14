class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // maps goes from [number] -> [index]
        std::unordered_map<int,int> u_map;
        int lookup = 0;
        for (int idx = 0; idx < nums.size(); idx++) {
            lookup = target - nums[idx];
            if (u_map.contains(lookup)) {
                return {u_map[lookup], idx};
            }
            u_map[nums[idx]] = idx;
        }
        return {};
        
    }
};
