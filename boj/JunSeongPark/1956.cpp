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
const int mxn = 404;

int tc, cnt;
int n;
int v, e;

vector<int> adj[mxn];

lint dist[mxn][mxn];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> v >> e;

	fill(dist[0], dist[0] + mxn * mxn, LINF);

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;

		dist[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int here = 1; here <= v; here++) {
			for (int there = 1; there <= v; there++) {
				dist[here][there] = min(dist[here][there], dist[here][k] + dist[k][there]);
			}
		}
	}

	lint ans = LINF;
	for (int i = 1; i <= v; i++)
		ans = min(ans, dist[i][i]);

	if (ans == LINF) cout << -1;
	else cout << ans;

	return 0;
}
