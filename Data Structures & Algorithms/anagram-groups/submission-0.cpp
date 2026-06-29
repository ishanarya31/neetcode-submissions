class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for(string s: strs){
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        for (auto& [key, val] : map) {
            res.push_back(val);
        }
        return res;
    }
};
