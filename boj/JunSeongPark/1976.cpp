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
const int mxn = 202;

int tc, cnt;
int n, m;
int par[mxn];

int find(int x) {
	if (par[x] == -1) return x;
	return par[x] = find(par[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return false;

	par[y] = x;
	return true;
}

bool isSame(int x, int y) {
	return find(x) == find(y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	memset(par, -1, sizeof(par));
	int a, b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;

			if (a == 1) merge(i, j);
		}
	}

	cin >> a;
	for (int i = 0; i < m - 1; i++) {
		cin >> b;
		if (!isSame(a, b)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}
