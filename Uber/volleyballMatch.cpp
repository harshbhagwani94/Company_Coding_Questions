/*

Two teams are playing volleyball match.
During one round of the game, a team scores a point and thus increases its scores by 1.
Both team starts with 0 points each.

The game ends when:
1. One of the teams gets 25 points and another team has < 24 points( strictly less than 24).
2. If score ties at 24:24, the teams continue to play until the absolute difference between
   the scores is 2.

After the game has ended, the final score is given in the format X:Y, which means the
first team has scored X points and the second has scored Y points.
Find the different sequences of getting points by teams that leads to this final score.

return result%(1E9+7)
and 
 0 <= X,Y <= 1E9.

*/

#include<bits/stdc++.h>

using namespace std;

const int size = 60;

long long int dp[size][size];

const long long int MOD = 1E9+7;

inline long long int nCr(long long int n, long long int r)
{
	if(n<r) return 0;
	if(r==0) return 1;
	if(dp[n][r]!=-1) return dp[n][r];
	return (dp[n][r] = (nCr(n-1, r-1) + nCr(n-1,r)) % MOD);
}

long long int power(long long int a, long long int n)
{
	if(!a)	return 0;
	if(!n) 	return 1%MOD;
	long long int x = power(a, n>>1);
	x = x*x%MOD;
	return (n%2? x * a %MOD : x);
}

long long int solution(long long int x, long long int y)
{
	if(x<y)
	{
		long long t = x;
		x = y;
		y = t;
	}
	if (x < 25)
		return 0;
	if (x == 25) 
	{
    	if (y > 23) 
    		return 0;
    	return nCr(24 + y, y);
	}
	if (y != x - 2) 
		return 0;
	return nCr(48, 24) % MOD * power(2, x - 24) % MOD;

}

int main()
{
	long long x,y;
	memset(dp,-1,sizeof(dp));
	cin>>x>>y;
	cout<<solution(x,y)<<endl;
	return 0;
}