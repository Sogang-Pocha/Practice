#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

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
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;

int N, K;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    if(N == 2){
        cout << "YES" << '\n';
        cout << "swap 1 2" << '\n';
        cout << "swap 1 2" << '\n';
        cout << "swap 1 2" << '\n';
        cout << "swap 1 2" << '\n';
        cout << "swap 1 2" << '\n';
    }
    else if(N == 3){
        cout << "NO" << '\n';
    }
    else {
        if(K == 1){
            cout << "YES" << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
            cout << "reverse " << 2 << ' ' << N-1 << '\n';
            cout << "reverse " << 1 << ' ' << N-1 << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
        }
        else if(K == N-1){
            cout << "YES" << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
            cout << "reverse " << 2 << ' ' << N-1 << '\n';
            cout << "reverse " << 2 << ' ' << N << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
        }
        else{
            cout << "YES" << '\n';
            cout << "reverse " << 1 << ' ' << K << '\n';
            cout << "reverse " << K+1 << ' ' << N << '\n';
            cout << "reverse " << 1 << ' ' << N << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
            cout << "swap " << 1 << ' ' << N << '\n';
        }
    }

    return 0;
}
