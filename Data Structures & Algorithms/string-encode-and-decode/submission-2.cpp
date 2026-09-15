#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        // ["hello", "my", "name", "is", "sid", "bye!"]
        // "5hello2my4name2is3sid4bye!"
        string output = "";
        string size = "";
        for(size_t idx = 0; idx < strs.size(); idx++) {
            if (strs[idx].size() < 10) {
                size = '1';
            } else if (strs[idx].size() < 100) {
                size = '2';
            } else {
                size = '3';
            }
            output += size + std::to_string(strs[idx].size()) + strs[idx];
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int len = 0;
        int num_len = 0;
        for(size_t idx = 0; idx < s.size();) {
            // take the number index
            // 15hello15world
            num_len = s[idx] - '0'; // 1, 2, or 3
            len = stoi(s.substr(idx + 1, num_len)); // Get the length of the
            output.push_back(s.substr(idx + num_len + 1, len));


            // the next len is end of the string
            idx += 1 + num_len + len;
        }

        return output;
    }
};
