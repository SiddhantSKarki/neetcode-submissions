class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // [2,3,4,5,0,0,0] [-1, 1, 1] --> [-1, 1, 1, 2, 3, 4, 5]

        int l1 = 0;
        int l2 = 0;

        vector<int> output;
        while (l1 < m && l2 < n) {
            if (nums1[l1] <= nums2[l2]) {
                output.push_back(nums1[l1]);
                l1++;
            } else {
                output.push_back(nums2[l2]);
                l2++;
            }
        }
        while (l1 < m) {
            output.push_back(nums1[l1]);
            l1++;
        }
        while (l2 < n) {
            output.push_back(nums2[l2]);
            l2++;
        }
        nums1 = output;
    }
};