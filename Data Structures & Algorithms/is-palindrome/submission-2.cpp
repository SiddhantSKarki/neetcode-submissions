class Solution {
public:
    bool isPalindrome(string s) {
        int id_l = 0;
        int id_r = s.size() - 1;
        char l;
        char r;
        while (id_l <= id_r) {
            l = tolower(s[id_l]);
            r = tolower(s[id_r]);

            if (!isalnum(l) || !isalnum(r)) {
                if (!isalnum(l)) {
                    id_l++;
                }
                if (!isalnum(r)) {
                    id_r--;
                }
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
