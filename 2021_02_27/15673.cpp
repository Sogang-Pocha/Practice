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
int n;
lint arr[mxn], lmin[mxn], lmax[mxn], rmin[mxn], rmax[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n == 2) {
		cout << arr[0] * arr[1];
		return 0;
	}

	lint tsum, tmin, tmax;
	tsum = tmin = tmax = 0;

	for (int i = 0; i < n; i++) {
		tsum += arr[i];
		lmin[i] = tsum - tmax;
		lmax[i] = tsum - tmin;

		tmin = min(tsum, tmin);
		tmax = max(tsum, tmax);

		if (i == 0) continue;

		lmin[i] = min(lmin[i], lmin[i - 1]);
		lmax[i] = max(lmax[i], lmax[i - 1]);
	}

	tsum = tmin = tmax = 0;
	for (int i = n - 1; i >= 0; i--) {
		tsum += arr[i];
		rmin[i] = tsum - tmax;
		rmax[i] = tsum - tmin;

		tmin = min(tsum, tmin);
		tmax = max(tsum, tmax);

		if (i == n - 1) continue;

		rmin[i] = min(rmin[i], rmin[i + 1]);
		rmax[i] = max(rmax[i], rmax[i + 1]);
	}

	lint ans = -LINF;
	for (int i = 0; i < n - 1; i++) {
		ans = max(ans, lmax[i] * rmax[i + 1]);
		ans = max(ans, lmin[i] * rmin[i + 1]);
	}

	cout << ans;



	return 0;
}
