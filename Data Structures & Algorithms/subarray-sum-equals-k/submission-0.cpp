class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force
        int counts = 0;
        for (size_t idx = 0; idx < nums.size(); idx++) {
            int sums = 0;
            for (size_t jdx = idx; jdx < nums.size(); jdx++) {
                sums += nums[jdx];

                if (sums == k) {
                    counts++;
                }
            }
        }

        return counts;
    }
};