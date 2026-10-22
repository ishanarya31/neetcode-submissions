class Solution {
public:
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(amt + 1,0));

        for(int i =0; i< n;i++)dp[i][0] = 1;

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= amt; j++){
                int take = 0;
                if(coins[i] <= j){
                    take = dp[i][j-coins[i]];
                }
                int nottake = dp[i+1][j];

                dp[i][j] = 0LL + take + nottake;
            }    
        }

        return dp[0][amt];
    }
};
