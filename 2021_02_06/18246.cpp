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

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 1515;
int tc, cnt;
int n, m;

const int leaf = 1 << 11;
int _map[mxn][mxn];
int fw[leaf * 2][leaf * 2];

void make() {
	for (int y = 0; y <= 1500; y++)
		for (int x = 0; x <= 1500; x++)
			fw[leaf | y][leaf | x] = _map[y][x];

	for (int y = 0; y <= 1500; y++) {
		for (int x = leaf - 1; x; x--) {
			fw[leaf | y][x] = max(fw[leaf | y][x << 1], fw[leaf | y][x << 1 | 1]);
		}
	}

	for (int y = leaf - 1; y; y--) {
		for (int x = leaf * 2 - 1; x; x--) {
			fw[y][x] = max(fw[y << 1][x], fw[y << 1 | 1][x]);
		}
	}
}

int query1(int idx, int l, int r) {
	int res = 0;
	for (l |= leaf, r |= leaf; l <= r; l /= 2, r /= 2) {
		if (l & 1)res = max(res, fw[idx][l++]);
		if (!(r & 1))res = max(res, fw[idx][r--]);
	}
	return res;
}

int query2(int x1, int x2, int y1, int y2) {
	int res = 0;
	for (x1 |= leaf, x2 |= leaf; x1 <= x2; x1 /= 2, x2 /= 2) {
		if (x1 & 1)res = max(res, query1(x1++, y1, y2));
		if (!(x2 & 1))res = max(res, query1(x2--, y1, y2));
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;

		_map[a][b]++;
		_map[c][d]++;
		_map[a][d]--;
		_map[c][b]--;
	}

	for (int y = 0; y <= 1500; y++) {
		for (int x = 0; x <= 1500; x++) {
			if (y != 0) _map[y][x] += _map[y - 1][x];
			if (x != 0) _map[y][x] += _map[y][x - 1];

			if ((y != 0) && (x != 0)) _map[y][x] -= _map[y - 1][x - 1];
		}
	}

	make();

	while (m--) {
		cin >> a >> b >> c >> d;

		cout << query2(a, c - 1, b, d -1) << '\n';
	}
	


	return 0;
}