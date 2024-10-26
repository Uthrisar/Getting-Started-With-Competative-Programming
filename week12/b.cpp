#include<bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
        return 0;

    if (memo[row][col] > 0)
        return memo[row][col];

    int longest = 1;

    // Move down
    if (row + 1 < grid.size() && grid[row + 1][col] > grid[row][col]) {
        longest = max(longest, 1 + findPath(grid, row + 1, col, memo));
    }

    // Move right
    if (col + 1 < grid[0].size() && grid[row][col + 1] > grid[row][col]) {
        longest = max(longest, 1 + findPath(grid, row, col + 1, memo));
    }

    // Move left
    if (col - 1 >= 0 && grid[row][col - 1] > grid[row][col]) {
        longest = max(longest, 1 + findPath(grid, row, col - 1, memo));
    }

    // Move up
    if (row - 1 >= 0 && grid[row - 1][col] > grid[row][col]) {
        longest = max(longest, 1 + findPath(grid, row - 1, col, memo));
    }

    memo[row][col] = longest;

    return longest;
}

int findLongestPath(vector<vector<int>>& grid) {
    vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 0));

    int maxLength = 0;
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            maxLength = max(maxLength, findPath(grid, row, col, memo));
        }
    }
    return maxLength;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int rows, cols;
        cin >> rows >> cols;

        vector<vector<int>> grid1(rows, vector<int>(cols));
        vector<vector<int>> grid2(rows, vector<int>(cols));

        // Input for grid1
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                cin >> grid1[row][col];
            }
        }

        // Input for grid2
        for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows; row++) {
                cin >> grid2[row][col];
            }
        }

        int path1 = findLongestPath(grid1);
        int path2 = findLongestPath(grid2);

        if(path1 > path2) {
            if(t != 0) cout << 1 << endl;
            else cout << 1;
        } else if (path2 > path1) {
            if(t != 0) cout << -1 << endl;
            else cout << -1;
        } else {
            if(t != 0) cout << 0 << endl;
            else cout << 0;
        }
    }
}