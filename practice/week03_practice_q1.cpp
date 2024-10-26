#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main()
{
    int tt;
    cin >> tt;

    while (tt--)
    {
        int n, q;
        cin >> n >> q;

        vi s(n);
        unordered_map<int, int> startIndex;
        unordered_map<int, int> endIndex;

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            endIndex[s[i]] = i;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            startIndex[s[i]] = i;
        }

        int st, ed, count = 0;
        for (int i = 0; i < q; i++)
        {
            cin >> st >> ed;

            if (startIndex.find(st) != startIndex.end() && endIndex.find(ed) != endIndex.end())
            {
                if (startIndex[st] <= endIndex[ed])
                    count++;
            }
        }

        cout << count;
        if (tt >= 1)
            cout << endl;
    }

    return 0;
}