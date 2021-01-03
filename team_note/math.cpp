#include <vector>
#include <map>
using namespace std;
using lint = long long;
lint MOD = 987654321;

lint extgcd(lint a, lint b, lint& x, lint& y) {
	lint ret = a;
	if (b != 0) {
		ret = extgcd(b, a%b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return ret;
}

//return x^n, O(log n)
lint mod_pow(lint x, lint n) {
	lint ret = 1;
	while (n > 0) {
		if (n & 1) ret = (ret * x) % MOD;
		x = (x * x) % MOD;
		n >>= 1;
	}
	return ret;
}

//약수 vector 반환 O(sqrt(n))
vector<int> divisor(int n) {
	vector<int> ret;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i != n / i) ret.push_back(n / i);
		}
	}
	return ret;
}

//소인수분해 O(sqrt(n))
map<int, int> prime_factor(int n) {
	map<int, int> ret;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}
//곱셈의 역원
lint mod_inverse(lint a, lint mod) {
	lint x, y;
	extgcd(a, mod, x, y);
	return (mod + (x % mod)) % mod;
}

//오일러 파이 O(sqrt(n))
lint euler_phi(lint n) {
	lint ret = n;
	for (lint i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret = ret / i * (i - 1);
			for (; n % i == 0; n /= i);
		}
	}
	if (n != 1) ret = ret / n * (n - 1);
	return ret;
}

//오일러 테이블 만들기 O(mxn);
const int mxn = 1;
lint euler[mxn];

void make_euler() {
	for (lint i = 0; i < mxn; i++) euler[i] = i;
	for (int i = 2; i < mxn; i++) {
		if (euler[i] == i) {
			for (int j = i; j < mxn; j += i) euler[j] = euler[j] / i * (i - 1);
		}
	}
}

// n!의 mod p 테이블 만들기 O(p)
const int mxn = 1;
int fact[mxn];

int mod_fact(int n, int p, int & e) {
	e = 0;
	if (n == 0) return 1;

	int ret = mod_fact(n / p, p, e);
	e += n / p;

	if (n / p % 2 != 0) return ret * (p - fact[n % p]) % p;
	return ret * fact[n % p] % p;
}

//nCk mod p 구하기 O(log_p n)
int mod_comb(int n, int k, int p) {
	if (n < 0 || k < 0 || n < k) return 0;
	int e1, e2, e3;
	int a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
	if (e1 > e2 + e3) return 0;
	return a1 * mod_inverse(a2 * a3 % p, p) % p;
}