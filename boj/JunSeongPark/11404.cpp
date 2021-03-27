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
const int mxn = 101;

int tc, cnt;
int n, m;
int dist[mxn][mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int here = 1; here <= n; here++) {
			for (int there = 1; there <= n; there++) {
				dist[here][there] = min(dist[here][there], dist[here][k] + dist[k][there]);
			}
		}
	}

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (dist[y][x] == INF) cout << 0 << ' ';
			else cout << dist[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
