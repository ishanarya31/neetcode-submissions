class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        return f(0, coins, amount, dp) == INT_MAX ? -1 : f(0,coins, amount , dp);
    }
    int f(int ind, vector<int>& coins, int amt, vector<vector<int>> &dp){
        int n = coins.size();
        if(amt == 0) return 0;
        if(ind == n) return INT_MAX;

        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        int take = INT_MAX;
        if(coins[ind] <= amt && f(ind, coins, amt-coins[ind], dp) != INT_MAX){
            take = 1 + f(ind, coins, amt - coins[ind], dp);
        }
        int notTake = f(ind + 1, coins, amt, dp);

        return dp[ind][amt] = min(take , notTake);
    }
};