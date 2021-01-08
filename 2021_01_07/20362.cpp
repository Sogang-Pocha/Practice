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
string S, arr[1001][2];

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> S;
    int idx = 0;
    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
        if(arr[i][0] == S) idx = i;
    }
    int cnt = 0;
    for(int i=0; i<idx; i++){
        if(arr[i][1] == arr[idx][1]) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
