class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        vector<vector<int>> dp(n+1, vector<int>(2 * sum +1, 0));

        dp[n][sum] = 1;

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2 * sum + 1; j++){
                int plus = 0, minus = 0;
                if (j - nums[i] >= 0) plus = dp[i + 1][j - nums[i]];
                if (j + nums[i] < 2*sum +1) minus = dp[i + 1][j + nums[i]];
                dp[i][j] = plus + minus;
            }
        }
        return dp[0][target+sum];
        // return f(0, target, nums);
    }
};
