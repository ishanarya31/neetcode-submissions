class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int, int>> stk;
        for(int i = 0; i< n ; i++){
            int curr = temperatures[i];
            while(!stk.empty() && stk.top().first < curr){
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({curr, i});
        }
        return res;
    }
};