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
const int mxn = 101;

int tc, cnt;
int n, m;
string str[mxn];
bool flag1, flag2;

bool solve(int idx) {

	for (int i = 1; i < m - 1; i++) {
		if (str[idx][i] == '#') flag1 = true;
		if (str[idx][i] == '.') {
			if (str[idx][i - 1] == '#' && str[idx][i + 1] == '#') {
				flag1 = true;
				return true;
			}
		}
	}
	return false;
}

bool solve2(int idx) {

	for (int i = 1; i < n - 1; i++) {
		if (str[i][idx] == '#') flag2 = true;
		if (str[i][idx] == '.') {
			if (str[i - 1][idx] == '#' && str[i + 1][idx] == '#') {
				flag2 = true;
				return true;
			}
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	
	for (int i = 0; i < n; i++) {
		if (solve(i)) {
			if (cnt > 0) cout << "DOWN";
			else cout << "UP";
			return 0;
		}
		if (flag1) cnt++;
	}
	cnt = 0;
	for (int i = 0; i < m; i++) {
		if (solve2(i)) {
			if (cnt > 0) cout << "RIGHT";
			else cout << "LEFT";
		}
		if (flag2) cnt++;
	}



	return 0;
}
