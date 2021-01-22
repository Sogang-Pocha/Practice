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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

int tc, cnt;
int n;

int num[2020][101];
int a[1 << 21];
string str;

void init() {
	int j;
	for (int i = 0; i <= (1 << 21); i++) {
		j = i;
		while (j) {
			if (j % 2) a[i]++;
			j /= 2;
		}
	}
}

int tob(string s) {
	int sz = s.size();
	int ret = 0;
	int k = 1;
	for (int i = sz - 1; i >= 0; i--) {
		if (s[i] == '1') ret += k;
		k *= 2;
	}
	return ret;
}

void _in(int x) {
	int s_idx = 0;
	int sz = str.size();

	for (int i = 0; i < 101; i++) {
		if (s_idx >= sz) break;
		num[x][i] = tob(str.substr(s_idx, min(20, sz - s_idx)));
		s_idx += 20;
	}
}

int solve(int x, int y) {
	int ret = 0;
	for (int i = 0; i < min(101, n / 20 + 1); i++) {
		ret += a[num[x][i] & num[y][i]];
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		_in(i);
	}

	init();

	int q, x, y;
	cin >> q;
	while (q--) {
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}

	return 0;
}