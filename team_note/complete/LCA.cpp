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
const int lmxn = 21;
int tc, cnt;
int n, m;
int parent[mxn][lmxn];
int visit[mxn], depth[mxn];

vector<int> adj[mxn];

void dfs(int cur, int par) {
	visit[cur] = true;
	depth[cur] = depth[par] + 1;

	for (auto next : adj[cur]) {
		if (visit[next]) continue;

		parent[next][0] = cur;
		dfs(next, cur);
	}
}

void make() {
	for (int j = 1; j < lmxn; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}	
}

int lca(int x, int y) {
	if (depth[x] > depth[y]) swap(x, y);

	for (int i = lmxn - 1; i >= 0; i--) {
		if (depth[y] - depth[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}

	if (x == y) return x;

	for (int i = lmxn - 1; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;



	return 0;
}