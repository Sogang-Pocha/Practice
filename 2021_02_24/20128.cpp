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

int N, M;
vector<pair<int, lint>> adj[100002];
lint dist[2][100002];
priority_queue<pair<lint, int>> pq; // distance, node

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int a, b, d;
    for(int i=0; i<M; i++){
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }

    fill(dist[0], dist[0] + 2*100002, LINF);
    pq.push({0, 1});
    dist[0][1] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();

        for(auto &n : adj[cur]){
            int next = n.first;
            lint cost = n.second;

            for(int i=0; i<=1; i++){
                if(dist[i][cur] >= LINF) continue;

                lint newcost = dist[i][cur] + cost;

                if(dist[newcost % 2][next] > newcost){
                    dist[newcost % 2][next] = newcost;
                    pq.push({-newcost, next});
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        lint dist1 = dist[1][i];
        lint dist2 = dist[0][i];
        if(dist1 >= LINF) dist1 = -1;
        if(dist2 >= LINF) dist2 = -1;

        cout << dist1 << ' ' << dist2 << '\n';
    }


    return 0;
}
