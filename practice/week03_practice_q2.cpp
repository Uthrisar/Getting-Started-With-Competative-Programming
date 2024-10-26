#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main()
{
    int tt;
    cin >> tt;

    while (tt--)
    {
        int n, m, inp;
        cin >> n;

        map<int, int> ankita;
        map<int, int> biswas;

        for (int i = 0; i < n; i++)
        {
            cin >> inp;
            ankita[-inp] = 1;
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> inp;
            biswas[-inp] = 1;
        }

        int a, b, fa, fb, w1 = 1, w2 = 2, isEmpty = 0, flag = 0;

        while (!ankita.empty() && !biswas.empty())
        {

            a = -(*ankita.begin()).first;
            fa = (*ankita.begin()).second;
            b = -(*biswas.begin()).first;
            fb = (*biswas.begin()).second;

            if (a > b)
            {
                w1 = 1;
                w2 = 1;
                flag = 1;
            }
            else if (a < b)
            {
                w1 = 2;
                w2 = 2;
                flag = 1;
            }
            else if (a == b)
            {
                w1 = 1;
                w2 = 2;
                flag = 1;
            }

            if (flag)
            {
                // cout<<"(a:"<<a<<",b:"<<b<<")";
                break;
            }

            a = -a;
            b = -b;
            ankita.erase(a);

            if (ankita.empty())
            {
                isEmpty = 1;
            }

            biswas.erase(b);
            if (biswas.empty())
            {
                if (isEmpty)
                {
                    w1 = 2;
                    w2 = 1;
                }
                else
                {
                    w1 = 1;
                    w2 = 1;
                }
            }
            else if (isEmpty) // !Biswas.empty()
            {
                w1 = 2;
                w2 = 2;
            }
        }

        if (w1 == 1)
            cout << "Ankita";
        else if (w1 == 2)
            cout << "Biswas";
        cout << endl;
        if (w2 == 1)
            cout << "Ankita";
        else if (w2 == 2)
            cout << "Biswas";

        if (tt >= 1)
            cout << endl;
    }

    return 0;
}