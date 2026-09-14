class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) {
            return {};
        }
        if (strs.size() == 1) {
            return {strs};
        }
        string temp = "";
        std::unordered_map<string, vector<string>> umap;
        for (const string& str: strs) {
            temp = str;
            std::sort(temp.begin(), temp.end());
            if (umap.contains(temp)) {
                umap[temp].push_back(str);
            } else {
                umap[temp] = vector<string> {str};
            }
        }
        vector<vector<string>> outputs;
        outputs.reserve(umap.size());
        for(pair map_pair: umap) {
            outputs.push_back(map_pair.second);
        }
        return outputs;
        
        
    }
};
