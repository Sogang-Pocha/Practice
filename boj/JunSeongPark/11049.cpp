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
const int mxn = 505;

int tc, cnt;
int n;

lint r[mxn], c[mxn];
lint dp[mxn][mxn];

lint solve(int left, int right) {
	lint &ret = dp[left][right];

	if (ret != -1) return ret;
	if (left == right) return ret = 0;

	ret = INF;
	for (int mid = left; mid < right; mid++) 
		ret = min(ret, solve(left, mid) + solve(mid + 1, right) + r[left] * c[mid] * c[right]);
	

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> r[i] >> c[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, n - 1);

	return 0;
}
