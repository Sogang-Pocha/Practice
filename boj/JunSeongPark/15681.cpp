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

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 101010;

int tc, cnt;
int n, r, q;
int ans[mxn];
vector<int> adj[mxn];

int dfs(int here, int par) {
	ans[here] = 1;

	for (auto there : adj[here]) {
		if (there == par) continue;

		ans[here] += dfs(there, here);
	}

	return ans[here];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> r >> q;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(r, 0);

	while (q--) {
		cin >> a;
		cout << ans[a] << '\n';
	}

	return 0;
}
