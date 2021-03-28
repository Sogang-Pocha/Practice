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
int n, m, k;

struct node {
	int to, cost, time;

	bool operator<(const node& rhs) const {
		return time > rhs.time;
	}
};

vector<vector<node>> adj;

int dist[mxn][mxn*mxn];

int solve() {
	fill(dist[0], dist[0] + mxn * mxn*mxn, INF);
	priority_queue<node> pq;
	pq.push({ 1,0,0 });
	dist[1][0] = 0;

	while (!pq.empty()) {
		int here = pq.top().to;
		int here_cost = pq.top().cost;
		int here_time = pq.top().time;
		pq.pop();

		if (dist[here][here_cost] != here_time) continue;

		if (here == n) return here_time;

		for (auto next : adj[here]) {
			int there = next.to;
			int there_cost = here_cost + next.cost;
			int there_time = here_time + next.time;

			if (there_cost > m || dist[there][there_cost] <= there_time)
				continue;
			dist[there][there_cost] = there_time;
			pq.push({ there, there_cost, there_time });
		}
	}

	return INF;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;

		adj.clear();
		adj.resize(n + 1);

		int a, b, c, d;
		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c >> d;
			adj[a].push_back({ b,c,d });
		}

		int ans = solve();

		if (ans == INF) cout << "Poor KCM\n";
		else cout << ans << '\n';
	}



	return 0;
}
