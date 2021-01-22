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

const int MOD = 998244353, INF = 987654321;
const lint LMOD = 998244353;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

int tc, cnt;
string str;
int n;

lint mod_pow(lint x, lint n) {
	lint ret = 1;
	while (n > 0) {
		if (n & 1) ret = (ret * x) % LMOD;
		x = (x * x) % LMOD;
		n >>= 1;
	}
	return ret;
}

int solve(int i) {
	lint ret = str[i] - '0';

	ret = (ret * mod_pow(2, i)) % LMOD;
	ret = (ret * mod_pow(11, n - i - 1)) % LMOD;

	return (int)ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> str;
	n = str.size();

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + solve(i)) % MOD;

	cout << ans;

	return 0;
}