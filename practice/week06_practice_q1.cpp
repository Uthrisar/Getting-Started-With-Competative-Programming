#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// Calculate Manhattan Distance
int manhattanDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> emptySeats;

        // Read the matrix and store positions of empty seats
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int seat;
                cin >> seat;
                if (seat == 0) {
                    emptySeats.push_back({i, j});
                }
            }
        }

        int minDistance = INT_MAX;

        // Find the minimum Manhattan distance between any two empty seats
        for (size_t i = 0; i < emptySeats.size(); ++i) {
            for (size_t j = i + 1; j < emptySeats.size(); ++j) {
                int distance = manhattanDistance(emptySeats[i], emptySeats[j]);
                minDistance = min(minDistance, distance);
            }
        }

        // Output result
        if (minDistance == INT_MAX) {
            cout << -1;
        } else {
            cout << minDistance;
        }
      	if(T != 0) cout << endl;
    }

    return 0;
}
