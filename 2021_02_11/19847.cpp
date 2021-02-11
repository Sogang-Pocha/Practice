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

lint dp[mxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int _mxn = -1;

	int cur;
	double N = 0.0;
	while (n--) {
		cin >> cur;
		if (_mxn == -1) {
			_mxn = cur;
			N = cur;
			for (int i = 0; i < _mxn; i++)
				dp[i] = 1;
		}
		else {
			if (cur >= _mxn) continue;

			for (int i = cur; i < _mxn; i++)
				dp[i % cur] += dp[i];
			_mxn = cur;
		}
	}

	double ans = 0.;
	for (int i = 0; i < _mxn; i++) {
		ans += i * dp[i];
	}

	cout << fixed;
	cout.precision(10);

	cout << ans / N;



	return 0;
}
