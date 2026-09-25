class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) {
            return vector<vector<string>>({strs});
        }

        // bruteforce
        // For each str, sort,
        // Chcek if exists in map (sorted str -> []),
        // if doesnot, add that in a vector
        // if does, append to the list.

        // iterate through all values in map and apped to a vector
        // time -- O(n * mlogm), space -- O(n)
        unordered_map<string, vector<string>> umap;
        for (const string& s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(s);
        }
        vector<vector<string>> output;
        for (auto& elm: umap) {
            output.push_back(elm.second);
        }

        return output;


    }
};
