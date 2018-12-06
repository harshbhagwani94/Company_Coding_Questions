/*
-----------------INDEED-------------------
Given a keypad with 2 - ABC (A-2, B-22, C-222)
                    3 - DEF (D-3, E-33, F-333)
                    4 - GHI (G-4, H-44, I-444)
                    5 - JKL (J-5, K-55, L-555)
                    6 - MNO (M-6, N-66, O-666)
                    7 - PQRS (P-7, Q-77, R-777, S-RRRR)
                    8 - TUV (T-8, U-88, V-888)
                    9 - WXYZ (W-9, X-99, Y-999, Z-9999)

We are given a string having numbers from 2-9, we have to find the different decoding possible from the given string s:
example:
s = 222
o/p: 4
Explanation: 222 can be decoded in 4 ways:
             AAA
             AB
             BA
             C

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<long> dp(n + 1);

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        if(s[i-1] == '1') continue;
        dp[i] = dp[i-1];
        if(i > 1 && s[i-1] == s[i-2]) dp[i] += dp[i-2];
        if(i > 2 && s[i-1] == s[i-2] && s[i-2] == s[i-3]) dp[i] += dp[i-3];
        if(i > 3 && (s[i-1] == '7' || s[i-1] == '9') && s[i-1] == s[i-2] && s[i-2] == s[i-3] && s[i-3] == s[i-4]) dp[i] += dp[i-4];
    }

    printf("ans = %ld\n", dp[n]);
}
