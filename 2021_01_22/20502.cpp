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
int n, m;

typedef struct {
	int r, i;
	bool check[101];
} node;

node arr[101];

bool cmp(node a, node b) {
	return a.r < b.r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i].r;
		arr[i].i = i + 1;
	}

	int mi, cur;
	for (int i = 0; i < n; i++) {
		cin >> mi;
		while (mi--) {
			cin >> cur;
			arr[i].check[cur] = true;
		}
	}

	sort(arr, arr + n, cmp);

	int q, k;
	bool flag;
	cin >> q;
	while (q--) {
		cin >> k;
		flag = true;
		for (int i = 0; i < n; i++) {
			if (arr[i].check[k]) {
				flag = false;
				cout << arr[i].i << ' ';
			}
		}
		if (flag) cout << "-1\n";
		else cout << '\n';
	}


	return 0;
}