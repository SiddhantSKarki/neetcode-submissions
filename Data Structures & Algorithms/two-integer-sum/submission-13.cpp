class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        // number -> index 
        // [1, 2, 3, 4], target = 5
        int temp;
        for (int i = 0; i < nums.size(); i++) {
            temp = target - nums.at(i);
            if (umap.contains(temp)) {
                return vector<int>({umap.at(temp), i});
            }
            umap[nums.at(i)] = i;
        }
        return {};
    }
};
