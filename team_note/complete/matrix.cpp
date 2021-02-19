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

const lint MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 10000;

typedef vector<vector<lint>> matrix;

struct MAT {
	matrix table;
	lint sz;
	
	void init(lint n) {
		sz = n;
		table = matrix(n, vector<lint>(n));
	}

	matrix cross(const matrix &a, const matrix &b) {
		lint size = a.size();

		matrix ret(size, vector<lint>(size));
		for (lint i = 0; i < size; i++) {
			for (lint j = 0; j < size; j++) {
				for (lint k = 0; k < size; k++) {
					ret[i][j] += a[i][k] * b[k][j] % MOD;
				}
				ret[i][j] %= MOD;
			}
		}

		return ret;
	}

	matrix cross(const matrix &a) {
		return cross(table, a);
	}

	matrix power(lint n) {
		matrix ret(sz, vector<lint>(sz));
		for (lint i = 0; i < sz; i++) {
			ret[i][i] = 1;
		}
		while (n > 0) {
			if (n % 2 == 1) {
				ret = cross(ret);
			}
			n /= 2;
			table = cross(table);
		}
		return table = ret;
	}
};

int tc, cnt;
int n, m;

MAT mat;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	return 0;
}
