//  Created by 도찡.
//  Copyright © 2020 도찡. All rights reserved.

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

int N;
string s;

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> s;
    int left = 0, right = N-1, cnt = 0;
    while(left < right){
        if(s[left] == s[right]){
            while(s[left] == s[left + 1]) left++;
            while(s[right] == s[right - 1]) right--;
            left++; right--;
            cnt++;
        }
        else{
            while(s[left] == s[left + 1]) left++;
            left++;
            cnt++;
        }
    }
    if(left == right) cnt++;
    cout << cnt << '\n';

    return 0;
}
