class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last_idx = m + n - 1;

        int idxl = m - 1;
        int idxr = n - 1;

        while (idxl >= 0 && idxr >= 0) {
            if (nums1[idxl] < nums2[idxr]) {
                nums1[last_idx] = nums2[idxr];
                idxr--;
            } else {
                nums1[last_idx] = nums1[idxl];
                idxl--;
            }
            last_idx--;
        }

        while (idxr >= 0) {
            nums1[last_idx] = nums2[idxr];
            idxr--;
            last_idx--;
        }
    }
};