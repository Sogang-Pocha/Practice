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
using pll = pair<lint, lint>;


const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 10000;

pll ext_gcd(lint a, lint b) {
	if (b != 0) {
		pll ret = ext_gcd(b, a%b);
		return { ret.second, ret.first - (a / b) * ret.second };
	}

	return { 1,0 };
}

lint mod_inv(lint a, lint M) {
	return (ext_gcd(a, M).first + M) % M;
}

int tc, cnt;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);




	return 0;
}