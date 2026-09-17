class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int longest_seq = 0;
        unordered_set<int> unums(nums.begin(), nums.end());

        for (int num: unums) {
            if (!unums.contains(num - 1)) {
                int length = 1;
                while (unums.contains(num + length)) {
                    length++;
                }
                longest_seq = max(length, longest_seq);
            }
        }

        return longest_seq;
    }
};
