class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx_l = 0;
        int idx_r = numbers.size() - 1;
        int temp = 0;
        while (true) {
            temp = numbers[idx_l] + numbers[idx_r];
            if (temp > target) {
                idx_r--;
            } else if (temp < target) {
                idx_l++;
            } else {
                return vector<int>({idx_l+1, idx_r+1});
            }
        }
    }
};
