#include<bits/stdc++.h>
using namespace std;
 
int up[200001][20];
 
int depth[200001];
 
vector<int> g[200001];
 
void dfs(int v, int p=-1){
    up[v][0]=p;
    for(int i=1; i<20; i++){
        if(up[v][i-1] != -1){
            up[v][i]=up[up[v][i-1]][i-1];
        }
    }
    for(int c : g[v]){
        if(c != p){
            depth[c]=1+depth[v];
            dfs(c,v);
        }
    }
}
 
int lift_node(int node, int jump_req){
    for(int jump=19; jump>=0; jump--){
        if(node == -1 || jump_req == 0)
            break;
        if(jump_req >= (1<<jump)){
            node = up[node][jump];
            jump_req -= (1<<jump);
        }
    }
    return node;
}
 
int lca(int a, int b){
    if(depth[a] < depth[b])
        swap(a,b);
    a = lift_node(a,depth[a]-depth[b]);
    if(a==b) return a;
    for(int jump=19; jump>=0; jump--){
        if(up[a][jump] != up[b][jump]){
            a=up[a][jump];
            b=up[b][jump];
        }
    }
    return up[a][0];
}
 
int main(){
    memset(up,-1,sizeof(up));
    int n,q;
    cin>>n>>q;
    for(int e=2; e<=n; e++){
        int x;
        cin >> x;
        g[e].push_back(x);
        g[x].push_back(e);
    }
    dfs(1);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}