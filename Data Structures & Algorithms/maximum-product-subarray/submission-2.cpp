class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = 1;
        int currMin = 1;
        int res = *max_element(nums.begin(), nums.end());
        for(int i =0; i< n; i++){
            if(nums[i] == 0){
                currMax = 1;
                currMin = 1;
                continue;
            }
            int tmp1 = currMax*nums[i];
            int tmp2 = currMin*nums[i];
            currMax = max({nums[i], tmp1, tmp2});
            currMin = min({nums[i], tmp1, tmp2});
            res = max(currMax,res);
        }
        return res;
    }
};