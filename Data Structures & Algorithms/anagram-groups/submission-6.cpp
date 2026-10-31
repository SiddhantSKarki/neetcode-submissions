class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 1) {
            return vector<vector<string>>{strs};
        }

        string temp;
        unordered_map<string, vector<string>> umap;
        for (string str: strs) {
            temp = str;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }

        vector<vector<string>> output;
        for (auto keyVal: umap) {
            output.push_back(keyVal.second);
        }

        return output;
    }
};
