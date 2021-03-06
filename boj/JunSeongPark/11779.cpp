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
const int mxn = 1010;

int tc, cnt;
int n, m;
vector<pii> adj[mxn];
int dist[mxn];
bool visit[mxn];
int pre[mxn];
vector<int> path;

void solve(int start, int finish) {
	fill(dist, dist + mxn, 2 * INF);
	dist[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int here = pq.top().second;
		int here_cost = pq.top().first;
		pq.pop();
		if (dist[here] != here_cost) continue;

		visit[here] = true;

		for (auto next : adj[here]) {
			int there = next.first;
			int cost = next.second;

			if (dist[here] + cost < dist[there]) {
				dist[there] = dist[here] + cost;
				pq.push({ dist[there], there });
				pre[there] = here;
			}
		}
	}
}

void trace(int start, int finish) {
	for (int i = finish; i != start; i = pre[i]) {
		path.push_back(i);
	}

	path.push_back(start);

	reverse(all(path));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	int s, t;
	cin >> s >> t;

	solve(s, t);
	trace(s, t);
	cout << dist[t] << '\n';
	cout << path.size() << '\n';
	
	for (auto x : path)
		cout << x << ' ';



	return 0;
}
