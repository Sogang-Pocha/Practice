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
int n, m, s;
vector<pii> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> s;

	int a, b;
	v.push_back({ 0,0 });
	v.push_back({ s,s });
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, a + b });
	}

	sort(all(v));

	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1].first - v[i].second >= m) {
			cout << v[i].second;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
