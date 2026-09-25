class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return nums;
        }
        vector<int> output;

        // get freq of numbers
        unordered_map<int, int> num_freq;
        for (int& num: nums) {
            num_freq[num]++;
        }

        // get reverse mapping
        // [frequency] -> [what elements in this frequency]
        unordered_map<int, vector<int>> freq_num;
        for (auto& pr: num_freq) {
            freq_num[pr.second].push_back(pr.first);
        }

        // iterate through max possible size of freq
        for (int idx = nums.size(); idx > 0; idx--) {
            for (int num: freq_num[idx]) {
                output.push_back(num);
                if (output.size() == k) {
                    return output;
                }
            }
        }

        return output;

    }
};
