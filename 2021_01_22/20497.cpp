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
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

bool check[12][12];
bool arr[12][12];
bool visit[12][12];
int N;

int dfs(int r, int c){
    visit[r][c] = true;
    int cnt = 0;

    for(int i=0; i <4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr >= 0 && nr < N && nc >= 0 && nc < N){
            if( arr[nr][nc] && !visit[nr][nc]){
                dfs(nr, nc);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    char input;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            cin >> input;
            if(input == '.') arr[r][c] = true;
            else arr[r][c] = false;
        }
    }

    int ans = 0;

    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            if(arr[r][c]){
                //dfs
                int t = dfs(r, c);
                if(t >= 2) {ans++; check[r][c] = true;}
                fill(visit[0], visit[0]+12*12, false);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}