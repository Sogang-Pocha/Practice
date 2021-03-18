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
int n, m;
int par[mxn];
double ans;
priority_queue<pair<double, pii>> pq;
pii arr[mxn];

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

double dist(pii a, pii b) {
	return sqrt((lint)(a.first - b.first) * (a.first - b.first) + (lint)(a.second - b.second) * (a.second - b.second));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	int a, b;
	memset(par, -1, sizeof(par));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			pq.push({ -dist(arr[i], arr[j]), {i + 1, j + 1} });
		}
	}

	while (!pq.empty()) {
		if (merge(pq.top().second.first, pq.top().second.second)) {
			ans -= pq.top().first;
		}
		pq.pop();
	}

	cout.precision(2);
	cout << fixed;
	cout << ans;


	return 0;
}
