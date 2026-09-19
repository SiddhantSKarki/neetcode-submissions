class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int min_e = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            if (nums[left] < nums[right]) {
               min_e = min(min_e, nums[left]); 
               break;
            }
            mid = (left + right) / 2;
            min_e = std::min(nums[mid], min_e);
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }

        return min_e;
    }
};
