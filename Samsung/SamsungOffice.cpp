#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int M = (1 << 12) + 5;
int x[N];
int y[N];
long dp[M][N];
int test, n;

int main(){
    cin>> test;
    
    while(test--){
        cin >> n;
        n += 2;
        // printf("%d\n", n);
        for(int i = 0; i < n; i++){
            cin>> x[i]>> y[i];
        }

        int m = (1 << n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = INT_MAX;
            }
        }

        dp[1][0] = 0;
        for(int state = 1; state < m; state++){
            for(int j = 0; j < n; j++){
                if(dp[state][j] == INT_MAX) continue;
                // printf("state = %d, j = %d\n", state, j);
                for(int k = 0; k < n; k++){
                    int state2 = (state | (1 << j));
                    dp[state2][k] = min(dp[state][j] + abs(x[j] - x[k]) + abs(y[j] - y[k]), dp[state2][k]);
                }
            }
        }

        printf("%ld\n", dp[m-1][1]);
    }
    return 0;
}

