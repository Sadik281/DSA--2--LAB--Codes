#include <bits/stdc++.h>
using namespace std;

/*int count(vector<int>& coins, int sum) {
    int n = coins.size();

    vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {

            // Add the number of ways to make change without
            // using the current coin,
            dp[i][j] += dp[i - 1][j];

            if ((j - coins[i - 1]) >= 0) {

                // Add the number of ways to make change
                // using the current coin
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[n][sum];
} */
//Driver Code Starts
int count(vector<int> &coins, int sum) {
    int n = coins.size();
    
    // dp[i] will be storing the number of solutions for
    // value i.
    vector<int> dp(sum + 1);

    dp[0] = 1;

    // Pick all coins one by one and update the table[]
    // values after the index greater than or equal to the
    // value of the picked coin
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];
    return dp[sum];
}
int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << count(coins, sum);
    return 0;
}
