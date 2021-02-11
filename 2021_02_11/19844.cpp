#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using ll = long long;

const int MOD = 1e9 + 7, INF = 987654321;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    int word = 1;
    f(i, s.size()) {
        if (s[i] == ' ') word++;
        else if (s[i] == '-') word++;
        else if (s[i] == '\'') {
            if(s[i+1]=='a'|| s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u' || s[i + 1] == 'h')
            switch (s[i - 1]) {
            case 'c':
            case 'j':
            case 'n':
            case 'm':
            case 't':
            case 's':
            case 'l':
            case 'd':
                if (i - 1 == 0) word++;
                else if (s[i - 2] == ' ' || s[i - 2] == '-') word++;
                break;
            case 'u':
                if (i - 1 == 0) break;
                if (s[i - 2] == 'q') {
                    if (i - 2 == 0) word++;
                    else if (s[i - 3] == ' ' || s[i - 3] == '-') word++;
                    break;
                }
            }
        }
    }
    cout << word;
    return 0;
}