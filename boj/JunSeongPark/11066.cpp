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
int arr[mxn];
int dp[mxn][mxn];
int psum[mxn];

int solve(int idx, int len) {
	if (len == 0) return 0;

	int &ret = dp[idx][len];

	if (ret != -1) return ret;
	if (len == 1) return ret = 0;

	ret = INF;
	for (int i = 1; i <= len; i++) 
		ret = min(ret, psum[idx + len] - psum[idx] + solve(idx, i) + solve(idx + i, len - i));
	

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			psum[i + 1] = arr[i];
			psum[i + 1] += psum[i];
		}

		memset(dp, -1, sizeof(dp));

		cout << solve(0, n) << '\n';
	}


	return 0;
}
