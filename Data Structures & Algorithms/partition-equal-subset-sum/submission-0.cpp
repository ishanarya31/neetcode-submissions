class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0; int res = 0;
        sort(nums.begin(), nums.end());
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        if(totalSum%2 != 0) return false;
        vector<vector<int>> dp(n+1, vector<int>(totalSum/2 + 1,-1));
        return f(0,totalSum/2, nums, dp);
    }
    bool f(int i, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(i == nums.size()){
            return false;
        }
        if(target == 0){
            return true;
        }
        if(dp[i][target] != -1) return dp[i][target];
        bool take = false;
        if(target >= nums[i]){
            take = f(i+1, target - nums[i], nums, dp);
        }
        bool notTake = f(i+1, target, nums, dp);
        return dp[i][target] = take || notTake;
    }
};