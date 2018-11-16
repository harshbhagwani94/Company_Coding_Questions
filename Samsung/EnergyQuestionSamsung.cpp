#include <bits/stdc++.h>
using namespace std;
const int INF = 2E9;

int dp[4040][1010][5];
inline int fun(int i, int j, int k, vector<int> &a, vector<int> &b) {
    // base case
    if (i < 0) return INF;
    if (j == 0) return 0;
    if (k < 0) return INF;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    return dp[i][j][k] = min(fun(i, j, k - 1, a, b), b[k] + fun(i - a[k], j - 1, k, a, b));
}

int getAns(vector<int> &cost, vector<int> &time, int H, int D) {
memset(dp, -1, sizeof dp); // #include <cstring>
    return fun(H, D, 4, cost, time);
}

int main() {
    vector<int> cost {4, 5, 2, 3, 6};
    vector<int> time {200, 210, 230, 235, 215};
cout << getAns(cost, time, 14, 4);
/*
t = 16, 17, … -> 800
t = 14 -> 830
*/
}
