#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<int>> prefix;

int getSum(int r1, int c1, int r2, int c2) {
    return prefix[r2 + 1][c2 + 1]
         - prefix[r1][c2 + 1]
         - prefix[r2 + 1][c1]
         + prefix[r1][c1];
}

bool zeroSq(int r, int c, int len) {
    return getSum(r, c, r + len - 1, c + len - 1) == 0;
}

int solve(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2)
        return 0;

    if (r1 == r2 && c1 == c2)
        return grid[r1][c1] == 0 ? 1 : 0;

    int midRow = (r1 + r2) / 2;
    int midCol = (c1 + c2) / 2;

    int topLeft = solve(r1, c1, midRow, midCol);
    int topRight = solve(r1, midCol + 1, midRow, c2);
    int bottomLeft = solve(midRow + 1, c1, r2, midCol);
    int bottomRight = solve(midRow + 1, midCol + 1, r2, c2);

    int ans = max({topLeft, topRight, bottomLeft, bottomRight});

    int height = r2 - r1 + 1;
    int width = c2 - c1 + 1;
    int maxLen = min(height, width);

    for (int len = 1; len <= maxLen; len++) {
        for (int i = r1; i + len - 1 <= r2; i++) {
            for (int j = c1; j + len - 1 <= c2; j++) {

                bool crossHorizontal = (i <= midRow && i + len - 1 > midRow);
                bool crossVertical = (j <= midCol && j + len - 1 > midCol);

                if (crossHorizontal || crossVertical) {
                    if (zeroSq(i, j, len))
                        ans = max(ans, len);
                }
            }
        }
    }

    return ans;
}

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));
    prefix.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i + 1][j + 1] =
                grid[i][j]
                + prefix[i][j + 1]
                + prefix[i + 1][j]
                - prefix[i][j];
        }
    }

    cout << solve(0, 0, n - 1, n - 1) << endl;

    return 0;
}