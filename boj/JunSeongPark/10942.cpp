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
const int mxn = 2020;

int tc, cnt;
int n, m;

int arr[mxn];

int dp[mxn][mxn];

int solve(int l, int r) {
	if (l == r) return true;

	if (l == r + 1) return arr[l] == arr[r];

	int &ret = dp[l][r];

	if (ret != -1) return ret;

	ret = 0;

	return ret = (arr[l] == arr[r]) & solve(l + 1, r - 1);
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	arr[0] = INF;
	arr[n + 1] = -1;

	memset(dp, -1, sizeof(dp));

	cin >> m;
	int a, b;
	while (m--) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		cout << solve(a, b) << '\n';
	}
	return 0;
}
