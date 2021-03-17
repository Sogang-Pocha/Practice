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

int tc, cnt;
int n, d, c;
int dist[mxn];
vector<vector<pii>> adj;

void solve(int start) {
	dist[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (auto x : adj[here]) {
			int there = x.first;
			int next_cost = x.second + cost;

			if (dist[there] > next_cost) {
				dist[there] = next_cost;
				pq.push({ next_cost, there });
			}
		}
	}
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) continue;

		cnt++;
		ans = max(ans, dist[i]);
	}

	cout << cnt << ' ' << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> d >> c;
		adj.clear();
		adj.resize(n + 1);

		int a, b, s;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			adj[b].push_back({ a,s });
		}

		fill(dist, dist + mxn, INF);
		solve(c);

	}


	return 0;
}
