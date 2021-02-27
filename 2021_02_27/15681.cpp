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

int N, R, Q;
vector<int> adj[100003];
bool visit[100003];
int dp[100003];

int dfs(int n){
    visit[n] = true;

    int sum = 1;
    for(auto &next : adj[n]){
        if(visit[next]) continue;
        sum += dfs(next);
    }

    return dp[n] = sum;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> R >> Q;

    int a, b;
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(R);

    int q;
    for(int i=0; i<Q; i++){
        cin >> q;
        cout << dp[q] << '\n';
    }

    return 0;
}
