#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m, n, p;
    if (!(cin >> m >> n >> p))
        return 0;

    vector<vector<int>> sim(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> sim[i][j];
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        dp[i][0] = -i * p;
    }
    for (int j = 1; j <= n; ++j)
    {
        dp[0][j] = -j * p;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int match = dp[i - 1][j - 1] + sim[i - 1][j - 1];
            int skipA = dp[i - 1][j] - p;
            int skipB = dp[i][j - 1] - p;

            dp[i][j] = max({match, skipA, skipB});
        }
    }

    cout << dp[m][n] << "\n";

    return 0;
}