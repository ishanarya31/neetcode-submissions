class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // int n = nums.size();
        // vector<int> count(2001,0);
        // vector<int> res(k,0);
        // for(int i =0 ; i< n; i++){
        //     count[nums[i] + 1000]++;
        // }
        // for(int i = 0 ; i< k; i++){
        //     int max_count = INT_MIN;
        //     int max_ind = -1;
        //     for(int j =0; j < 2001; j++){
        //         if(count[j] > max_count){
        //             max_count = count[j];
        //             max_ind = j;
        //         }
        //     }
        //     count[max_ind] = 0;
        //     res[i] = max_ind - 1000;
        // }
        // return res;
        unordered_map<int , int> count;
        for (int n: nums) count[n]++;
        vector<vector<int>> freq(nums.size() + 1);
        for (auto& [e, c]: count) {
            freq[c].push_back(e);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int e: freq[i]) {
                res.push_back(e);
                if (res.size() >= k) {
                    return res;
                }
            }
        } 
        return res;
    }
};
