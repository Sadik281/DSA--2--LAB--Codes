#include <iostream>
#include <vector>
using namespace std;

int countWaysRec(int n, vector<int>& dp) {
  
  	// Base cases
    if (n == 0 || n == 1)
        return 1;

  	// if the result for this subproblem is 
  	// already computed then return it
    if (dp[n] != -1) 
        return dp[n];
    
    return dp[n] = countWaysRec(n - 1, dp) +
      				 	countWaysRec(n - 2, dp);
}

int countWays(int n) {
  
  	// dp array to store the results
  	vector<int> dp(n + 1, -1);
  	return countWaysRec(n, dp);
}

int main() {
    int n = 4;
    cout << countWays(n);
    return 0;
}