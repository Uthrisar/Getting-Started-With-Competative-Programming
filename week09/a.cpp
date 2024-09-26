/*
Author : Uthrisar Kh. Boro
Date : 26-09-2024
*/

#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

const ll INF = 1e16;

vector<int> par(402);
vector<ll> path_flow(402);
vector<int> graph[402];
ll flow_passed[402][402];
ll capacity[402][402];

bool find_path(int s, int t){
    fill(par.begin(), par.end(),-1);
    fill(path_flow.begin(), path_flow.end(),0);
    queue<int> q;
    par[s] = -2;
    q.push(s);
    path_flow[s] = INF;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : graph[u]) {
            if(par[v] == -1 && capacity[u][v] > flow_passed[u][v]) {
                par[v] = u;
                path_flow[v] = min(path_flow[u],capacity[u][v]-flow_passed[u][v]);
                if(v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int max_flow(int src, int sink){
    int maxFlow = 0;
    while(find_path(src,sink)) {
        int flow = path_flow[sink];
        maxFlow += flow;
        int u = sink;
        while(u != src) {
            int v = par[u];
            flow_passed[u][v] -= flow;
            flow_passed[v][u] += flow;
            u = v;
        }
    }
    return maxFlow;
}

void reset(){
    memset(flow_passed,0,sizeof(flow_passed));
    memset(capacity,0,sizeof(capacity));
    for(int i = 0; i < 402; i++){
        graph[i].clear();
    }
}


bool canPossible(int N, int M, int K, vector<pair<ll,ll>>& ships, vector<pair<ll,ll>>& planets, vector<ll>& speed, ll time) {
    reset();
    int src = 0, sink = N+M+1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            double tim = (ships[i].ff-planets[j].ff)*(ships[i].ff-planets[j].ff);
            tim += (ships[i].ss-planets[j].ss)*(ships[i].ss-planets[j].ss);
            ll cost = ceil(tim/speed[i]);
            if(cost*60 <= time) {
                graph[i].push_back(j+N);
                graph[j+N].push_back(i);
                capacity[i][j+N] = 1;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        graph[src].push_back(i);
        capacity[src][i] = 1;
    }

    for(int j = 1; j <= M; j++) {
        graph[j+N].push_back(sink);
        capacity[j+N][sink] = 1;
    }
    return max_flow(src,sink) >= K;
}

int main(){
    int tc;
    cin >> tc;
    while (tc--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<pair<ll,ll>> ships(N+1);
        vector<pair<ll,ll>> planets(M+1);
        for(int i = 1; i <= N; i++){
            cin >> ships[i].ff >> ships[i].ss;
        }
        for(int i = 1; i <= M; i++){
            cin >> planets[i].ff >> planets[i].ss;
        }
        vector<ll> speed(N+1);
        for(int i = 1; i <= N; i++) {
            cin >> speed[i];
            speed[i] *= speed[i];
        }

        ll lo = 0, hi = INF, result = -1;
        while(lo <= hi){
            ll mid = (lo+hi)/2;
            if(canPossible(N,M,K,ships,planets,speed,mid)) {
                result = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        cout<<(result == -1 ? -1 : result);
        if(tc != 0) cout << endl;
    }
}
