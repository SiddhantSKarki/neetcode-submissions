class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> out(2*nums.size());
        size_t size = nums.size();
        for (size_t idx = 0; idx < 2*size; idx++) {
            out[idx] = nums[idx % size];
        }
        return out;
    }
};