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

const int MOD = 1e9 + 3, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int tc, cnt;
int N, K;

int dp[1001][1001];

int solve(int n, int k) {
	if (k < 0 || n < 0)
		return 0;

	int& ret = dp[n][k];

	if (ret != -1)
		return ret;

	if (k == 1)
		return ret = n;
	if (k == 0)
		return ret = 1;
	if ((n + 1) / 2 < k)
		return ret = 0;

	return ret = (solve(n - 1, k) + solve(n - 2, k - 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	memset(dp, -1, sizeof(dp));

	cout << (solve(N - 1, K) + solve(N - 3, K - 1)) % MOD;

	return 0;
}