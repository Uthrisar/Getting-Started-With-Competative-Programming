#include <bits/stdc++.h>
using namespace std;

int dp(int n, vector<int> &mem)
{

    if (n == 1)
        return 0;

    if (mem[n] != -1)
        return mem[n];

    int maxi = 0;

    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, i * (n - i) + dp(i, mem) + dp(n - i, mem));
    }

    return mem[n] = maxi;
}

int solve(int n)
{

    vector<int> mem(n + 1, -1);

    return dp(n, mem);
}

int main()
{
    int T, N;

    cin >> T;

    while (T)
    {
        cin >> N;

        if (T > 1)
            cout << solve(N) << endl;
        else
            cout << solve(N);
        T--;
    }
}