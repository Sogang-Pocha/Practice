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
using pll = pair<lint, lint>;

const lint MOD = 1e9 + 9, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 101010;

int n, m, s, e;
lint dist[mxn];
lint cnt[mxn];

vector<pll> adj[mxn];

lint solve() {
	fill(dist, dist + mxn, LINF);

	priority_queue<pll> pq;

	pq.push({ 0,s });
	dist[s] = 0;
	cnt[s] = 1;

	while (!pq.empty()) {
		lint cur_node = pq.top().second;
		lint cur_dist = -pq.top().first;
		pq.pop();

		if (dist[cur_node] < cur_dist) continue;

		for (auto next : adj[cur_node]) {
			lint next_node = next.first;
			lint next_cost = next.second;

			if (dist[cur_node] + next_cost < dist[next_node]) {
				dist[next_node] = dist[cur_node] + next_cost;
				cnt[next_node] = cnt[cur_node];
				pq.push({ -dist[next_node], next_node });
				continue;
			}

			if (dist[next_node] == dist[cur_node] + next_cost) {
				cnt[next_node] += cnt[cur_node];
				cnt[next_node] %= MOD;
			}
		}
	}
	return cnt[e];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> s >> e;

	lint a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	cout << solve();


	return 0;
}
