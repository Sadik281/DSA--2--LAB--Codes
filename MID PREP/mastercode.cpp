#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int activitySelection(vector<int> &start, vector<int> &finish) {
    vector<vector<int>> arr;
 
    for (int i = 0; i < start.size(); i++) {
        arr.push_back({start[i], finish[i]});
    }

    // Sort activities by finish time
    sort(arr.begin(), arr.end(), compare);
    
    // At least one activity can be performed
    int count = 1;  
    
    // Index of last selected activity
    int j = 0;      

    for (int i = 1; i < arr.size(); i++) {
       
        // Check if current activity starts
        // after last selected activity finishes
        if (arr[i][0] > arr[j][1]) {
            count++;
            
            // Update last selected activity
            j = i;  
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, finish);
    return 0;
}
// COIN CHANGE PROBLEM
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
//fractional knapsack problem
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Comparison function to sort items based on value/weight ratio
bool compare(vector<int>& a, vector<int>& b) {
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    
    // Create 2D vector to store value and weight
    // items[i][0] = value, items[i][1] = weight
    vector<vector<int>> items(n, vector<int>(2));
    
    for (int i = 0; i < n; i++) {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }
    
    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);
    
    double res = 0.0;
    int currentCapacity = capacity;
    
    // Process items in sorted order
    for (int i = 0; i < n; i++) {
        
        // If we can take the entire item
        if (items[i][1] <= currentCapacity) {
            res += items[i][0];
            currentCapacity -= items[i][1];
        }
        
        // Otherwise take a fraction of the item
        else {
            res += (1.0 * items[i][0] / items[i][1]) * currentCapacity;
            
            // Knapsack is full
            break; 
        }
    }
    
    return res;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    
    cout << fractionalKnapsack(val, wt, capacity) << endl;
    
    return 0;
}
//house robber problem
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
