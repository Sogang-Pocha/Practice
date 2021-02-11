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
lint dp[31][31];
string s;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;

    int len = s.length();

    for(int i=0; i<len; i++){
        dp[i][i] = 1;
    }
    for(int i=0; i<len-1; i++){
        if(s[i] == s[i+1]) dp[i][i+1] = 3;
        else dp[i][i+1] = 2;
    }

    int tmp = 2;
    lint t;
    while(tmp < len){
        for(int l=0; l<len; l++){
            int r = l + tmp;

            if(r >= len) continue;

            if(s[l] == s[r]) t = 1;
            else t = -1 * dp[l+1][r-1];

            dp[l][r] = dp[l+1][r] + dp[l][r-1] + t;
        }
        tmp++;
    }

    cout << dp[0][len-1] << '\n';

    return 0;
}
