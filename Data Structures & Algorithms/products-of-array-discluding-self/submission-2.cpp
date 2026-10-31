class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t full_size = nums.size();
        vector<int> prefix(full_size);
        prefix.at(0) = 1;  

        vector<int> suffix(full_size);
        suffix.at(full_size - 1) = 1;

        // [1, _ , _ ,_]
        for (int idx = 1; idx < full_size; idx++) {
            prefix.at(idx) = prefix.at(idx - 1) * nums.at(idx - 1);
            // [1,1, _, _]
            // [1, 1,2, 8]
        }

        for (int idx = full_size - 2; idx >= 0; idx--) {
            suffix.at(idx) = suffix.at(idx + 1) * nums.at(idx + 1);
            // [48, 24,6,1]
        }
        vector<int> out(full_size);
        for (int i = 0; i < full_size; i++) {
            out.at(i) = prefix.at(i) * suffix.at(i);
        }

        return out;


    }
};
