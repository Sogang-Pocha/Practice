#include <vector>
#include <set>
using namespace std;

using lint = long long;
using pll = pair<lint, lint>;
const int mxn = 400005;
const lint MOD = 1000000000000000LL + 37;

class Karp_Rabin {
public:
	string S;
	string P;
	int lenS = 0;
	int lenP = 0;
	int cur_idx = 0;

	lint hash2_P = 0;
	lint hash3_P = 0;
	lint hash2_S = 0;
	lint hash3_S = 0;

	lint pow2P = 1;
	lint pow3P = 1;

	void init() {
		hash2_S = hash3_S = hash2_P = hash3_P = 0;
		pow2P = pow3P = 1;
		cur_idx = 0;
	}

	void make_hash_P() {
		lint pow3 = 1;
		lint pow2 = 1;

		for (int i = 0; i < lenP; i++) {
			hash2_P += P[lenP - i - 1] * pow2%MOD;
			hash3_P += P[lenP - i - 1] * pow3%MOD;
			hash2_P %= MOD;
			hash3_P %= MOD;
			pow2 *= 2;
			pow3 *= 3;
			pow2 %= MOD;
			pow3 %= MOD;
		}
	}

	void hash_next() {
		lint pow3 = 1;
		lint pow2 = 1;

		if (cur_idx == 0) {
			for (int i = 0; i < lenP; i++) {
				hash2_S += S[lenP - i - 1] * pow2 % MOD;
				hash3_S += S[lenP - i - 1] * pow3 % MOD;
				hash2_S %= MOD;
				hash3_S %= MOD;
				pow2 *= 2;
				pow3 *= 3;
				pow2 %= MOD;
				pow3 %= MOD;
			}
			pow2P = pow2;
			pow3P = pow3;
		}
		else if (cur_idx <= lenS - lenP) {
			hash2_S = 2 * hash2_S - S[cur_idx - 1] * pow2P + S[cur_idx + lenP - 1];
			hash2_S = (hash2_S%MOD + MOD) % MOD;
			hash3_S = 3 * hash3_S - S[cur_idx - 1] * pow3P + S[cur_idx + lenP - 1];
			hash3_S = (hash3_S%MOD + MOD) % MOD;
		}
		else {
			cur_idx = -1;
			hash2_S = 0;
			hash3_S = 0;
		}
		cur_idx++;
	}

	pll get_hash() {
		return { hash2_S, hash3_S };
	}

	bool match() {
		if (hash2_S == hash2_P && hash3_S == hash3_P) return true;
		return false;
	}
};