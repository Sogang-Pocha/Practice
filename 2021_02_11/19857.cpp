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
const int mxn = 201010;

lint tc, cnt;
int n;

lint arr[mxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	lint ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt += arr[i];
	}

	if (cnt == 1) {
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i]) {
				if (i == 0) cout << 1;
				else cout << i;
				return 0;
			}
		}
	}

	int l = 0, r = mxn - 1;
	while (l <= r) {
		int mid = (l + r) / 2;

		lint need = 1;
		lint zero = arr[0];

		for (int i = n - 1; i >= mid; i--) 
				zero += arr[i];
		

		for (int i = mid - 1; i > 0; i--) {
			if (need < arr[i])
				zero += (arr[i] - need);
			else if (need > arr[i])
				need += (need - arr[i]);
			need = min(LINF, need);
		}

		if (zero >= need) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
		
	}

	cout << ans;

	return 0;
}
