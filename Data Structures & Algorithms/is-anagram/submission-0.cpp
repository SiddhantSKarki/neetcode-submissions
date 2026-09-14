class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        size_t common_size = s.size();
        if (common_size <= 1) {
            if (common_size == 0) {
                return true;
            } else {
                return s[0] == t[0];
            }
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        for (size_t idx = 0; idx < common_size; idx++) {
            if (s[idx] != t[idx]) {
                return false;
            }
        }
        return true;
    }
};
