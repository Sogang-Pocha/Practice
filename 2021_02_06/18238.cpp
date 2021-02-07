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
int n;
string str;
char ch;

int solve(char x) {
	if (abs(x - ch) <= 26 - abs(x - ch))
		return abs(x - ch);
	return 26 - abs(x - ch);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> str;

	int ans = 0;
	ch = 'A';
	for (auto s : str) {
		ans += solve(s);
		ch = s;
	}

	cout << ans;
	return 0;
}
