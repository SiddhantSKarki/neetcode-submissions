class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            // "a", "" --> s.szie()
            return s.size();
        }

        // {}
        // "zxyzxyz"
        int out = 0;
        unordered_set<char> ch_set;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            while (ch_set.contains(s[right])) {
                ch_set.erase(s[left]);
                left++;
            }
            ch_set.insert(s[right]);
            out = max(out, right - left + 1);
        }

        return out;
        
    }
};
