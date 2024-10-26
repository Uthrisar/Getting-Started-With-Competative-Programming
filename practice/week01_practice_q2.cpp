#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> positions(n + 1);

    int pos = 1;
    for (int k = 1; k <= n; k++)
    {
        pos = (pos + (k - 1)) % n;

        if (pos == 0)
            positions[n] = 1;
        else
            positions[pos] = 1;
    }

    pos = 0;
    for (int i = 1; i <= n; i++)
        pos += positions[i];

    if (pos == n)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}