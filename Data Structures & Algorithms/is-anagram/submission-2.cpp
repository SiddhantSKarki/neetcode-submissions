class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        if (s.size() == 0) {
            return true;
        }
        if (s.size() == 1) {
            return s.at(0) == t.at(0);
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
