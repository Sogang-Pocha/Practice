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
int n, k;
int w[mxn], v[mxn];
int dp[111][mxn];

int solve(int idx, int weight) {
	if (idx == n) return 0;

	int &ret = dp[idx][weight];
	if (ret != -1) return ret;

	ret = solve(idx + 1, weight);
	if (w[idx] <= weight) ret = max(ret, solve(idx + 1, weight - w[idx]) + v[idx]);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> w[i] >> v[i];
	
	memset(dp, -1, sizeof(dp));

	cout << solve(0, k);

	return 0;
}
