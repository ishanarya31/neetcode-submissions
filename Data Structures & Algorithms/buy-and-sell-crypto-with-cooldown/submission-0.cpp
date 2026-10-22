class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        vector<vector<int>> dp(n, vector<int>(2,0));

        dp[n-1][1] = prices[n-1];

        dp[n-2][1] = max(prices[n-2], dp[n-1][1]);
        dp[n-2][0] = max(dp[n-1][1] - prices[n-2], dp[n-1][0]);


        for(int i = n-3; i >= 0; i--){
            dp[i][1] = max(prices[i] + dp[i+2][0], dp[i+1][1]);
            dp[i][0] = max(dp[i+1][1] - prices[i], dp[i+1][0]); 
        }
        return dp[0][0];
    }
};
