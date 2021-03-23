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
#include <unordered_set>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 101010;

int tc, cnt;
int n;
int par[mxn];

struct node {
	int x, y, z, i;
};

bool cmpx(node a, node b) {
	return a.x < b.x;
}

bool cmpy(node a, node b) {
	return a.y < b.y;
}

bool cmpz(node a, node b) {
	return a.z < b.z;
}

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

vector<node> arr;

priority_queue<pair<int, pii>> pq;

int dist(const node& a, const node& b) {
	int ret = abs(a.x - b.x);
	ret = min(ret, abs(a.y - b.y));
	ret = min(ret, abs(a.z - b.z));
	return -ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	memset(par, -1, sizeof(par));
	int x, y, z;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		arr.push_back({ x,y,z,i });
	}

	sort(all(arr), cmpx);

	for (int i = 0; i < n - 1; i++)
		pq.push({ dist(arr[i], arr[i + 1]), {arr[i].i, arr[i + 1].i} });

	sort(all(arr), cmpy);

	for (int i = 0; i < n - 1; i++)
		pq.push({ dist(arr[i], arr[i + 1]), {arr[i].i, arr[i + 1].i} });

	sort(all(arr), cmpz);

	for (int i = 0; i < n - 1; i++)
		pq.push({ dist(arr[i], arr[i + 1]), {arr[i].i, arr[i + 1].i} });

	lint ans = 0;
	while (!pq.empty()) {
		lint d = -pq.top().first;
		int v1 = pq.top().second.first;
		int v2 = pq.top().second.second;
		pq.pop();

		if (merge(v1, v2)) {
			ans += d;
		}
	}

	cout << ans;

	return 0;
}