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
int n, d;
int sa[mxn], pos[mxn], lcp[mxn];
int tmp[mxn];
string str;

bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];

	i += d;
	j += d;
	return (i < n && j < n) ? (pos[i] < pos[j]) : (i > j);
}

void make_sa() {
	n = str.size();

	for (int i = 0; i < n; i++) {
		sa[i] = i;
		pos[i] = str[i];
	}

	for (d = 1;; d <<= 1) {
		sort(sa, sa + n, cmp);

		fill(tmp, tmp + mxn, 0);

		for (int i = 0; i < n - 1; i++)
			tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);

		for (int i = 0; i < n; i++)
			pos[sa[i]] = tmp[i];

		if (tmp[n - 1] == n - 1) return;
	}
}

void make_lcp() {
	for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
		if (pos[i] == n - 1) continue;

		for (int j = sa[pos[i] + 1]; str[i + k] == str[j + k]; k++);
		lcp[pos[i]] = k;
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> str;

	make_sa();
	make_lcp();


	return 0;
}
