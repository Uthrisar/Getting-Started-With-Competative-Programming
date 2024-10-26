#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n;

        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }

        cin >> m;

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        int max_sum_r = 0, max_sum_b = 0;
        int current_sum_r = 0, current_sum_b = 0;

        // Calculate max prefix sum for array r
        for (int i = 0; i < n; ++i) {
            current_sum_r += r[i];
            max_sum_r = max(max_sum_r, current_sum_r);
        }

        // Calculate max prefix sum for array b
        for (int i = 0; i < m; ++i) {
            current_sum_b += b[i];
            max_sum_b = max(max_sum_b, current_sum_b);
        }

        int max_sum = max_sum_r + max_sum_b;
        cout << max_sum;
        if(t != 0) cout << endl;
    }

    return 0;
}
