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

int T, N;
int func(string str){
    switch(str[0]){
        case 'M': return 0;
        case 'T':
            if(str[1] == 'u') return 1;
            else return 3;
        case 'W': return 2;
        case 'F': return 4;
    }

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T >> N;
    int t1, t2;
    string str1, str2;

    for(int i=0; i<N; i++){
        cin >> str1 >> t1 >> str2 >> t2;

        int t = func(str2) - func(str1);
        T -= t2 + t*24 - t1;
    }

    if(T > 48) cout << -1;
    else if(T > 0) cout << T;
    else cout << 0;

    return 0;
}
