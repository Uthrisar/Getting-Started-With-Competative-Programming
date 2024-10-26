#include<bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    vector<int> row;
    map<int, int> colorMap;

    for(int i = 0; i < Q; i++) {
        int type, X, Y;
        cin >> type >> X;

        if(type == 1) {
            row.push_back(X);
            colorMap[X]++;
        } else {
            cin >> Y;
            for(int &val : row) {
                if(val == X) {
                    val = Y;
                }
            }
            colorMap[Y] += colorMap[X];
            colorMap[X] = 0;
        }
    }

    int sz = row.size();
    for(int i=0; i<sz; i++){
        cout<<row[i];
        if(i != sz-1) cout<<" ";
    }
}
