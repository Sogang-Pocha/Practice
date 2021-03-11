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
const int mxn = 101010;

int tc, cnt;
int n;

int inOrder[mxn], postOrder[mxn];

void solve(int pstart, int pfinish, int istart, int ifinish) {
	if (pfinish < pstart || ifinish < istart) return;
	cout << postOrder[pfinish] << ' ';
	if (pstart == pfinish) return;

	int pivot;
	for (int i = istart; i <= ifinish; i++) 
		if (inOrder[i] == postOrder[pfinish]) {
			pivot = i;
			break;
		}
	
	solve(pstart, pstart + pivot - istart - 1, istart, pivot - 1);
	solve(pstart + pivot - istart, pfinish - 1, pivot + 1, ifinish);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> inOrder[i];
	for (int i = 0; i < n; i++) cin >> postOrder[i];

	solve(0, n - 1, 0, n - 1);

	return 0;
}
