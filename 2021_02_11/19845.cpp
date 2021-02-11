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

int tc, cnt;
int n, q;
vector<int> arr;


int solve(int y, int x) {
	int ret = arr[y] - x + 1;

	int l = y, r = n - 1;
	int up = y;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (arr[mid] >= x) {
			up = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return ret += up - y;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	arr.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int a, b;
	while (q--) {
		cin >> a >> b;
		b--;
		if (arr[b] - a < 0) {
			cout << "0\n";
			continue;
		}

		cout << solve(b, a) << '\n';
	}


	return 0;
}
