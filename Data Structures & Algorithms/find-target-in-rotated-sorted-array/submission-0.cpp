class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        // [1,2,3,4,5,6]
        // [2, 3, 4, 5, 6, 1] <-- 1
        // [3, 4, 5, 6, 1, 2] <-- 2 // **
        // [4, 5, 6, 1, 2, 3] <-- 3
        // terget to find: 4 output --> 1
        // bruteforce
        for (size_t idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] == target) {
                return idx;
            }
        }

        return -1;
    }
};
