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

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    int cnt = 0, heart = 0, arm1 = 0, arm2 = 0, mid = 0, leg1 = 0, leg2 = 0;
    char input;

    for(int r=1; r<=N; r++){
        if(cnt == 1 && arm2 != 0) cnt++;

        for(int c=1; c<=N; c++){
            cin >> input;

            if(input == '_') continue;

            if(cnt == 0){
                cout << r+1 << ' ' << c << '\n';
                heart = c;
                cnt++;
            }
            else if(cnt == 1){
                if(c < heart) arm1++;
                else if(c > heart) arm2++;
            }
            else if(cnt == 2){
                if(c != heart) {
                    cnt++;
                    leg1++;
                }
                else mid++;
            }
            else{
                if(c == heart - 1) leg1++;
                else leg2++;
            }
        }
    }

    cout << arm1 << ' ' << arm2 << ' ' << mid << ' ' << leg1 << ' ' << leg2 << '\n';

    return 0;
}
