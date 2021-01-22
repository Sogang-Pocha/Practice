#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using ll = long long;
const int mxn = 200002;
vector<ll> adj[mxn], par(mxn), child(mxn);
int n, root;

const int MOD = 1e9 + 7, INF = 987654321;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

ll odd, even;
vector<pii> ans;
int dfs(int cur) {
    int ret = 1;
    for (int next : adj[cur]) {
        ret += dfs(next);
    }
    child[cur] = ret;
    return ret;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    f(i, n) {
        int x; cin >> x;
        if (!x) root = i+1;
        else {
            adj[x].push_back(i + 1);
        }
        par[i + 1] = x;
    }
    
    child[root] = dfs(root);
    for (int i = 1; i <= n; i++) child[i] *= child[i];
    vector<ll> num(child);
    for (int i = 1; i <= n; i++) {
        num[par[i]] -= child[i];
    }
    int now = 1;
    for (int i = 1; i <= n; i++) {
        ll c = num[i];
        odd += (c / 2) * i;
        even += (c / 2) * i;
        if (now) {
            if (c) {
                odd += i;
                now = 0;
            }
        }
        else {
            if (c) {
                even += i;
                now = 1;
            }
        }
    }
    cout << even << ' ' << odd;
    return 0;
}