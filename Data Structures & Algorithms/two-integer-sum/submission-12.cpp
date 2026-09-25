class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sorting solution
        // O(nlogn) -- time
        // O(1) -- space

        // using a map, time -- O(n), space-- O(n)
        // [number] -> [index]
        std::unordered_map<int, int> seen;
        for (int idx = 0; idx < nums.size(); idx++) {
            int to_search = target - nums.at(idx);
            if (seen.contains(to_search)) {
                return std::vector<int>({seen[to_search], idx});
            } else {
                seen.emplace(nums[idx], idx);
            }
        }
        return {};
    }
};
