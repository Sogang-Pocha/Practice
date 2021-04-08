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
const int mxn = 10101;

int tc, cnt;
int N, M;
int m[mxn], c[mxn];
int dp[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> m[i];
	for (int i = 0; i < N; i++)
		cin >> c[i];

	for (int i = 0; i < N; i++) {
		for (int j = mxn - 1; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
		}
	}

	for (int i = 0; i < mxn; i++) {
		if (dp[i] >= M) {
			cout << i;
			break;
		}
	}



	return 0;
}
