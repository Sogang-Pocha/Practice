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
const int mxn = 505050;

int tc, cnt[mxn];
int n;
int arr[mxn];
priority_queue<int> pq;
vector<pii> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) pq.push(i);
	}

	int a, b;
	for (int i = 0; i < n - 2; i++) {
		a = arr[i]; cnt[a]--;
		b = pq.top(); pq.pop();
		if (cnt[a] == 0) pq.push(a);

		if (a > b) swap(a, b);
		ans.push_back({ a,b });
	}
	b = pq.top(); pq.pop();
	a = pq.top();
	ans.push_back({ a,b });
	sort(all(ans));

	for (auto x : ans)
		cout << x.first << ' ' << x.second << '\n';

	return 0;
}
