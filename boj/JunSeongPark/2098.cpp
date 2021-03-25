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
const int mxn = 10000;

int n;
int cost[22][22];
int dp[22][1 << 17];

int solve(int here, int visit) {
	int &ret = dp[here][visit];

	if (ret != -1) return ret;
	if (visit == (1 << n) - 1) return ret = ((cost[here][0] == 0) ? INF : cost[here][0]);

	ret = INF;
	for (int there = 1; there < n; there++) {
		if ((visit & (1 << there)) || cost[here][there] == 0) continue;

		ret = min(ret, solve(there, visit | (1 << there)) + cost[here][there]);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> cost[y][x];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 1);

	return 0;
}
