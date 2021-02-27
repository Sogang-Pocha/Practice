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
const int mxn = 101010;
int N, M;
lint arr[mxn][2];

lint dp[2][mxn];
vector<int> adj[mxn];
int parent[mxn];
int depth[mxn];

void dfs(int cur, int par, int flag) {
	dp[flag][cur] = 1;
	depth[cur] = depth[par] + 1;
	for (auto next : adj[cur]) {
		if (next == par) continue;

		parent[next] = cur;
		dfs(next, cur, 1 - flag);
		dp[0][cur] += dp[0][next];
		dp[1][cur] += dp[1][next];
	}
}

int main() {
#ifndef ONLINE_JUDGE
#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int u, v, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0, 0);

	lint e = dp[0][1];
	lint o = dp[1][1];
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> c;

		if (depth[u] > depth[v]) swap(u, v);

		lint ans = 0;

		if (c == 0) {
			ans += dp[1][v] * (o - dp[1][v]);
			ans += dp[0][v] * (e - dp[0][v]);
		}
		else {
			ans += dp[1][v] * (e - dp[0][v]);
			ans += dp[0][v] * (o - dp[1][v]);
		}
		cout << ans << '\n';
	}


	return 0;
}