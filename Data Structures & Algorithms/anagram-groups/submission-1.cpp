class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for(string s: strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i =0; i < 26; i++){
                key += ',' + to_string(count[i]) ;
            }
            map[key].push_back(s);
        }
        for (auto& [key, val] : map) {
            res.push_back(val);
        }
        return res;
    }
};
