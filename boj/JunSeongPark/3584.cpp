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
const int mxn = 10101;
const int lmxn = 20;

int tc, n;
int par[mxn][lmxn], depth[mxn];
int cnt[mxn];
vector<vector<int>> adj;

void dfs(int cur, int d) {
	depth[cur] = d;
	for (auto next : adj[cur]) {
		par[next][0] = cur;
		dfs(next, d + 1);
	}
}

void make() {
	for (int j = 1; j < lmxn; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int x, int y) {
	if (depth[x] > depth[y]) swap(x, y);

	for (int i = lmxn - 1; i >= 0; i--) 
		if (depth[y] - depth[x] >= (1 << i))
			y = par[y][i];
	
	if (x == y) return x;

	for (int i = lmxn - 1; i >= 0; i--)
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}

	return par[x][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		adj.clear();
		memset(par, 0, sizeof(par));
		memset(depth, 0, sizeof(depth));
		memset(cnt, 0, sizeof(cnt));
		adj.resize(n + 1);
		
		int a, b, root;
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			cnt[b]++;
		}

		for (int i = 1; i <= n; i++)
			if (cnt[i] == 0) {
				root = i;
				break;
			}
		
		dfs(root, 1);
		make();

		cin >> a >> b;

		cout << lca(a, b) << '\n';
		
	}


	return 0;
}
