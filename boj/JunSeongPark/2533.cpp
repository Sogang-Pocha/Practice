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
const int mxn = 1010101;

int tc, cnt;
int n;

bool visit[mxn];
vector<int> tmp[mxn];
vector<int> adj[mxn];
int dp[mxn][2];

void dfs(int here) {
	visit[here] = true;

	for (auto there : tmp[here]) {
		if (visit[there]) continue;

		adj[here].push_back(there);
		dfs(there);
	}
}

int solve(int here, int flag) {
	int &ret = dp[here][flag];

	if (ret != -1) return ret;

	if (flag) {
		ret = 1;
		for (auto there : adj[here]) {
			ret += min(solve(there, 0), solve(there, 1));
		}
	}
	else {
		ret = 0;
		for (auto there : adj[here]) {
			ret += solve(there, 1);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tmp[a].push_back(b);
		tmp[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));
	dfs(1);

	cout << min(solve(1,0), solve(1,1));

	return 0;
}
