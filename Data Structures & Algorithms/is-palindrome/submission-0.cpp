class Solution {
public:
    bool isPalindrome(string s) {
        int id_l = 0;
        int id_r = s.size() - 1;

        while (id_l <= id_r) {
            char l = tolower(s[id_l]);
            char r = tolower(s[id_r]);

            if (!isalnum(l) || !isalnum(r)) {
                if (!isalnum(l)) {
                    id_l++;
                }
                if (!isalnum(r)) {
                    id_r--;
                }
                continue;
            } else if (l == r) {
                id_l++;
                id_r--;
            } else {
                return false;
            }
        }
        return true;
    }
};
