class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> out(len);
        vector<int> pref(len);
        vector<int> suff(len);

        pref[0] = 1;
        suff[len - 1] = 1;

        // build pref array
        for (int idx = 1; idx < len; idx++) {
            pref[idx] = pref[idx - 1] * nums[idx - 1];
        }

        for (int idx = len - 2; idx >= 0; idx--) {
            suff[idx] = suff[idx + 1] * nums[idx + 1];
        }

        // build the output array
        for (int idx = 0; idx < len; idx++) {
            out[idx] = suff[idx] * pref[idx];
        }

        return out;

    }
};
