class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> memo(amount, 0);  
        return helper(coins, amount, memo);
    }

private:
    int helper(vector<int>& coins, int rem, vector<int>& memo) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (memo[rem - 1] != 0) return memo[rem - 1];

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = helper(coins, rem - coin, memo);
            if (res >= 0 && res < minCoins) {
                minCoins = 1 + res;
            }
        }

        memo[rem - 1] = (minCoins == INT_MAX) ? -1 : minCoins;
        return memo[rem - 1];
    }
};
