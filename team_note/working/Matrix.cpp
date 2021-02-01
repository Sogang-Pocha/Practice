#include <vector>

using namespace std;
using lint = long long;
const lint MOD = 987654321;
typedef vector<vector<lint>> matrix;

matrix operator * (const matrix &a, const matrix &b) {
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

matrix power(matrix a, lint n) {
	lint size = a.size();
	matrix ret(size, vector<lint>(size));
	for (lint i = 0; i < size; i++) {
		ret[i][i] = 1;
	}
	while (n > 0) {
		if (n % 2 == 1) {
			ret = ret * a;
		}
		n /= 2;
		a = a * a;
	}
	return ret;
}
