class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort method
        // build a [number] -> count map

        unordered_map<int,int> counts;
        vector<vector<int>> buckets (nums.size() + 1);
        for(int num: nums) {
            counts[num] = 1 + counts[num];
        }
        for (const auto& item: counts) {
            buckets[item.second].push_back(item.first);
        }

        vector<int> res;
        for (size_t idx = buckets.size() - 1; idx >= 1; idx--) {
            for (int n: buckets[idx]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;

    }
};
