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
int par[mxn][lmxn];
int visit[mxn], d[mxn];

vector<int> adj[mxn];

void dfs(int cur, int depth) {
	visit[cur] = true;
	d[cur] = depth;

	for (int next : adj[cur]) {
		if (visit[next]) continue;

		par[next][0] = cur;
		dfs(next, depth + 1);
	}
}

void make() {
	for (int j = 1; j < lmxn; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int x, int y) {
	if (d[x] > d[y]) swap(x, y);

	for (int i = 20; i >= 0; i--)
		if (d[y] - d[x] >= (1 << i))
			y = par[y][i];

	if (x == y) return x;

	for (int i = 20; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	return 0;
}
