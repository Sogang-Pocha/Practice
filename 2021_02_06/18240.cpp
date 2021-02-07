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
const int mxn = 303030;

int tc, cnt[mxn];
int n;
int arr[mxn];
queue<int> q[mxn];
int id;

void inorder(int lv, int idx) {
	if (idx * 2 < cnt[lv + 1])
		inorder(lv + 1, idx * 2);
	
	q[lv].push(++id);

	if (idx * 2 + 1 < cnt[lv + 1])
		inorder(lv + 1, idx * 2 + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	cnt[0] = 1;
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;

		if (2 * cnt[arr[i] - 1] < cnt[arr[i]]) {
			cout << -1;
			return 0;
		}
	}

	inorder(0, 0);

	for (int i = 0; i < n; i++) {
		cout << q[arr[i]].front() << ' ';
		q[arr[i]].pop();
	}
	


	return 0;
}
