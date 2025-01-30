#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int, int>& p, pair<int, int>& q) {
    return p.second < q.second;
}

ll calEuclideanDist(pair<int, int>& p, pair<int, int>& q) {
    ll dx = (ll)p.first-q.first;
    ll dy = (ll)p.second-q.second;
    return dx*dx+dy*dy;
}

ll minEuclideanDist(int lo, int hi, vector<pair<int, int>>& points) {
    if(hi - lo + 1 <= 3) {
        ll minDistSQ = LLONG_MAX;
        for(int i = lo; i <= hi; i++) {
            for(int j = i+1; j <= hi; j++) {
                minDistSQ = min(minDistSQ, calEuclideanDist(points[i], points[j]));
            }
        }
        return minDistSQ;
    }

    int mid = lo+(hi-lo)/2;
    ll ansL = minEuclideanDist(lo, mid, points);
    ll ansR = minEuclideanDist(mid+1, hi, points);
    ll minDistSQ = min(ansL, ansR);

    vector<pair<int, int>> strip;
    for(int i = lo; i <= hi; i++) {
        if((ll)(points[i].first-points[mid].first) * (points[i].first - points[mid].first) < minDistSQ) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), cmp); // Sort by y-coordinates
    for (int i = 0; i < int(strip.size()); i++) {
        for (int j = i + 1; j < int(strip.size()) && (ll)(strip[j].second - strip[i].second) * (strip[j].second - strip[i].second) < minDistSQ; j++) {
            minDistSQ = min(minDistSQ, calEuclideanDist(strip[i], strip[j]));
        }
    }
    return minDistSQ;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end()); // Sort by x-coordinate
    ll ans = minEuclideanDist(0, n-1, points);
    cout << ans << "\n";
    return 0;
}
