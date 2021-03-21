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
const int mxn = 505;

int tc, cnt;
int n, m;

int adj[mxn][mxn];
int deg[mxn], a[mxn], ans[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		memset(a, 0, sizeof(a));
		memset(ans, 0, sizeof(ans));
		memset(deg, 0, sizeof(deg));
		memset(adj, 0, sizeof(adj));

		cin >> n;

		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				adj[a[j]][a[i]] = 1;
				deg[a[i]]++;
			}
		}

		cin >> m;
		int x, y;
		while (m--) {
			cin >> x >> y;
			if (adj[x][y]) {
				deg[x]++;
				deg[y]--;
			}
			else {
				deg[x]--;
				deg[y]++;
			}
			swap(adj[y][x], adj[x][y]);
		}

		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) q.push(i);
		}

		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (q.empty()) {
				flag = 1;
				break;
			}
	
			int here = q.front();
			q.pop();
			ans[i] = here;

			for (int there = 1; there <= n; there++) {
				if (adj[here][there]) {
					deg[there]--;
					if (deg[there] == 0)
						q.push(there);
				}
			}
		}

		if (flag == 1)
			cout << "IMPOSSIBLE\n";
		else {
			for (int i = 0; i < n; i++) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
	}


	return 0;
}
