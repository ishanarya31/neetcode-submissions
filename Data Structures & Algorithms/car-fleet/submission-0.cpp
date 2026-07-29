class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        int res = 0;
        vector<pair<int, int>> pairs(n);
        for(int i =0 ; i< n; i++){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
        
        double maxTime = 0.0; 
        for (int i = 0; i < n; i++) {
            double currTime = (double)(target - pairs[i].first) / pairs[i].second;
            if (currTime > maxTime) {
                res++;
                maxTime = currTime;
            }
        }
        return res;
    }
};