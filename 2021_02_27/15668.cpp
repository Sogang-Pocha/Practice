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

int tc, cnt[11];
int n;
vector<int> arr;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	
	for (int i = 1; i < 101010; i++) {
		memset(cnt, 0, sizeof(cnt));

		int a = i;
		int b = n - i;
		if (b <= 0) break;
		
		while (a) {
			cnt[a % 10]++;
			a /= 10;
		}
		while (b) {
			cnt[b % 10]++;
			b /= 10;
		}

		bool flag = true;
		for (int i = 0; i <= 9; i++) {
			if (cnt[i] > 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i << " + " << n - i;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
