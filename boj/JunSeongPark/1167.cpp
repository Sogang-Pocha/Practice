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

int tc, cnt;
int n;
vector<pii> adj[mxn];
bool visit[mxn];
int ans, nxt;

void dfs(int here, int par, int sum) {
	visit[here] = true;

	if (sum > ans) {
		ans = sum;
		nxt = here;
	}

	for (auto there : adj[here]) {
		if (visit[there.first]) continue;
		dfs(there.first, here, sum + there.second);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	int from, to, d;

	for (int i = 0; i < n; i++) {
		cin >> from;

		while (true) {
			cin >> to;
			if (to == -1) break;
			cin >> d;
			adj[from].push_back({ to, d });
		}
	}

	dfs(1, 0, 0);
	fill(visit, visit + mxn, false);
	dfs(nxt, 0, 0);

	cout << ans;


	return 0;
}
