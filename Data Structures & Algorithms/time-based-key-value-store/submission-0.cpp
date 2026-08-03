class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!timeMap.count(key)) return "";
        auto& curr = timeMap[key];
        int n = curr.size();
        int l = 0 ; int r = n-1;
        while(l <= r){
            int mid = (r-l)/2 + l;
            if(curr[mid].second > timestamp){
                r = mid - 1;
            }
            else if(curr[mid].second < timestamp){
                l = mid +1;
            }
            else return curr[mid].first;
        }
        return (r >= 0) ? curr[r].first : "";
    }
};