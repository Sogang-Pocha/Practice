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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 200050;

int id, d[mxn], sid;
bool finished[mxn];
int sccid[mxn];
int indeg[mxn];
vector<int> a[mxn];
stack<int> s;
int n, m;

int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int result = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (d[y] == 0) result = min(result, dfs(y));
		else if (!finished[y]) result = min(result, d[y]);
	}

	if (result == d[x]) {
		sid++;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			sccid[t] = sid;
			if (t == x) break;
		}
	}

	return result;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		a[from].push_back(to);
	}

	for (int i = 1; i <= n; i++)
		if (d[i] == 0) dfs(i);

	for (int i = 1; i <= n; i++) {
		for (auto next : a[i]) {
			if (sccid[i] == sccid[next]) continue;
			indeg[sccid[next]]++;
		}
	}
	int t, cur;
	int ans = 0;
	cin >> t;

	while (t--) {
		cin >> cur;
		if (indeg[sccid[cur]] == 0) {
			ans++;
			indeg[sccid[cur]] = 1;
		}
	}

	for (int i = 1; i <= sid; i++) {
		if (indeg[i] == 0) {
			cout << -1;
			return 0;
		}
	}
	
	cout << ans;

	return 0;
}