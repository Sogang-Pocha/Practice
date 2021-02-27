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

int N, M, input[100003];
int arr[2][100003];

int query(int left, int right){

    int tmp1, tmp2;

    if(left == 1) tmp1 = arr[1][left] + (1 - arr[1][right]);
    else{
        if(input[left - 1] < input[right]){
            tmp1 = arr[1][left] + (arr[0][left-1] - arr[1][right]);
        }
        else tmp1 = arr[1][left] + (arr[0][left-1] + 1 - arr[1][right]);
    }

    if(right == N) tmp2 = tmp1;
    else{
        if(input[left] < input[right+1]){
            tmp2 = arr[0][N] + (tmp1 - arr[0][right+1]);
        }
        else tmp2 = arr[0][N] + (tmp1 + 1 - arr[0][right+1]);
    }

    return tmp2;
}

int main() {
#ifndef ONLINE_JUDGE
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> input[i];
    }

    arr[0][1] = 1; arr[1][N] = 1;
    for(int i=2; i<=N; i++){
        if(input[i-1] < input[i]) arr[0][i] = arr[0][i-1];
        else arr[0][i] = arr[0][i-1] + 1;
    }
    for(int i=N-1; i>=1; i--){
        if(input[i] > input[i+1]) arr[1][i] = arr[1][i+1];
        else arr[1][i] = arr[1][i+1] + 1;
    }

    int l, r;
    for(int i=0; i<M; i++){
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }

    return 0;
}
