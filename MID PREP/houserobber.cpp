#include <iostream>
#include <vector>
using namespace std;

int findMaxSum(vector<int>& arr) {
    int n = arr.size();
  
    // Create a dp array to store the maximum loot at each house
    vector<int> dp(n+1, 0);

    // Base cases
    dp[0] = 0;
    dp[1] = arr[0];

    // Fill the dp array using the bottom-up approach
    for (int i = 2; i <= n; i++) 
        dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);

    return dp[n];
}

int main() {
    vector<int>arr = {6, 7, 1, 3, 8, 2, 4};
    cout << findMaxSum(arr) << endl;
    return 0;
}