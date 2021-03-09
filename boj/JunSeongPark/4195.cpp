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
#include <unordered_map>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 201010;

int tc, cnt;
int n;
int par[mxn];

int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}

int merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return -par[x];

	int ret = -(par[x] + par[y]);
	par[x] = -ret;
	par[y] = x;

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;
	
	while (tc--) {
		memset(par, -1, sizeof(par));
		string str1, str2;
		int a, b, id = 0;
		unordered_map<string, int> m;
		
		cin >> n;
		while (n--) {
			cin >> str1 >> str2;

			auto t1 = m.find(str1);
			if (t1 != m.end())
				a = t1->second;
			else {
				a = id;
				m.insert({ str1, id++ });
			}

			auto t2 = m.find(str2);
			if (t2 != m.end())
				b = t2->second;
			else {
				b = id;
				m.insert({ str2, id++ });
			}

			cout << merge(a, b) << '\n';
		}
	}



	return 0;
}
