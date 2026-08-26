class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int currMax = 0;
        vector<int> tails;
        for(int i =0; i< n; i++){
            auto itr = lower_bound(tails.begin(), tails.end(), nums[i]);
            if(itr == tails.end()) tails.push_back(nums[i]);
            else *itr = nums[i];
        }
        return tails.size();
    }
};
