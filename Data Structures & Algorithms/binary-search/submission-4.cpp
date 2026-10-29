class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums.at(0) == target ? 0 : -1;
        }

        int lower = 0;
        int upper = nums.size() - 1;
        int mid = 0;
        int temp = 0;
        while (lower <= upper) {
            mid = (lower + upper) / 2;
            temp = nums.at(mid);
            if (temp == target) {
                return mid;
            } else if (temp < target) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return -1;
    }
};
