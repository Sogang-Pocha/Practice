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
using pdd = pair<double, double>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 101;

int tc, cnt;
int n;
pdd arr[mxn];
priority_queue<pair<double, pii>> pq;
int par[mxn];

int find(int x) {
	if (par[x] == -1) return x;
	return par[x] = find(par[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return false;

	par[x] = y;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first)
				+ (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
			dist = sqrt(dist);
			pq.push({ -dist, {i,j} });
		}
	}
	double ans = 0.;
	memset(par, -1, sizeof(par));
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		double dist = -pq.top().first;
		pq.pop();

		if (merge(x, y))
			ans += dist;
	}

	cout.precision(8);
	cout << fixed;
	cout << ans;

	return 0;
}
