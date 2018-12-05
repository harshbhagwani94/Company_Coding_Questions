/*

Minimum cost to creaste a number from 0 to N with addition and  subtraction with 1 cost A 
and multiplyication by 2 cost B.

A is the cost to Add/ Subtract 1 from curent number
B is the cost to double the current number.

I/p : 
2
4 1 1
4 1 5

O/p:
3
4
*/

#include <bits/stdc++.h>
using namespace std;

int ans[400001];


int find_min_cost(int cost1, int cost2, int x) {
    
    memset(ans, -1, sizeof(ans));
    
    ans[0] = 0;
    
    for (int i=1; i<=x; i++) {
        
        ans[i] = ans[i-1] + cost1;
        
        if (i%2 == 0)
            ans[i] = min(ans[i], ans[i/2] + cost2);
        else
            ans[i] = min(ans[i], ans[i/2] + cost2 + cost1);
            
        if (ans[i+1]!=-1)
            ans[i] = min(ans[i], ans[i+1] + cost1);
            
        ans[2*i] = ans[i] + cost2;
        ans[2*i + 1] = ans[i] + cost2 + cost1;
    }
    
    return ans[x];
}

int main()
{
    cout<<find_min_cost(1e6,1,1e3);
    return 0;
}
