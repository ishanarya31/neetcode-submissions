class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string result;

    string foreignDictionary(vector<string>& words) {
        for (const auto& word : words) {
            for (char ch : word) {
                adj[ch];
            }
        }

        for (size_t i = 0; i < words.size() - 1; ++i) {
            const string& w1 = words[i], & w2 = words[i + 1];
            size_t minLen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() &&
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        topoSort();
        return result;
    }

    void topoSort(){
        int k = adj.size();
        vector<int> indegree(26,0);
        for(auto& [k, v] : adj){
            for(auto& ch: v){
                indegree[ch-'a']++;
            }
        }

        queue<char> q;
        for(int i = 0; i< 26; i++){
            if(indegree[i]==0 && adj.count(i+97)){
                q.push(i+97);
            }
        }

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            result.push_back(cur);

            for(auto& neig: adj[cur]){
                indegree[neig-'a']--;
                if(indegree[neig-'a']==0) q.push(neig);
            }
        }
        if(result.size() != k){
            result.clear();
        }
        return;
    }
};
