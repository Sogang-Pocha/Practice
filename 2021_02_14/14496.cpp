#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;

int a, b, N, M;
vector<int> adj[1002];
int visit[1002];
queue<pii> qu;

void dfs(int x, int dist){
    visit[x] = dist;

    for(auto &a : adj[x]){
        if(visit[a] !=0) continue;
        dfs(a, dist+1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> a >> b >> N >> M;

    int t1, t2;
    for(int i=0; i<M; i++){
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }

    qu.push({a, 0});
    while(!qu.empty()){
        pii cur = qu.front();
        qu.pop();
        if(cur.first == b) break;

        for(auto  &t : adj[cur.first]){
            if(visit[t] != 0) continue;

            visit[t] = cur.second + 1;
            qu.push({t, cur.second + 1});
        }
    }

    if(a == b) cout << 0;
    else{
        if(visit[b] == 0) cout << -1;
        else cout << visit[b];
    }


    return 0;
}
