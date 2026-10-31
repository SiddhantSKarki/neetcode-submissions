class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        if (s.size() <= 1) {
            return s == t;
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        
        for (int idx = 0; idx < s.size(); idx++) {
            if (s.at(idx) != t.at(idx)) {
                return false;
            }
        }
        return true;
    }
};
