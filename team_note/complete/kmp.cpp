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
const int mxn = 360000;

int tc, cnt;
int n;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();

	vector<int> ret(patternSize, 0);

	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = ret[j - 1];
		if (pattern[i] == pattern[j])
			ret[i] = ++j;
	}
	return ret;
}

bool kmp(string target, string pattern) {
	vector<int> table = makeTable(pattern);

	int targetSize = target.size();
	int patternSize = pattern.size();

	int j = 0;
	for (int i = 0; i < targetSize; i++) {
		while (j > 0 && target[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (target[i] == pattern[j]) {
			if (j == patternSize - 1) return true;
			else j++;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



	return 0;
}
