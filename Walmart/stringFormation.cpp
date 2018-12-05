/*

To find all the possible ways to form a string of length K that has the following rules:

1. The word can use X number of different Alphabets
2. The word can use Y number of different digits
3. The word should always start with an alphabet
4. The word should contain exactly P no of alphabet.
5. The word should contain exactly Q number of digits.
 print the answer modulo 1e9+7.
K = P + Q;
Each alphabet is unique and can be used multiple times.
*/
#include<bits/stdc++.h>
using namespace std;

long long int MOD = 1e9 + 7;
const int size = 60;

#define int long long
int dp[size][size];

inline int nCr(int n, int r)
{
	if(n<r) return 0;
	if(r==0) return 1;
	if(dp[n][r]!=-1) return dp[n][r];
	return (dp[n][r] = (nCr(n-1, r-1) + nCr(n-1,r)) % MOD);
}

int power(int a, int n)
{
	if(!a)	return 0;
	if(!n) 	return 1%MOD;
	int x = power(a, n>>1);
	x = x*x%MOD;
	return (n%2? x * a %MOD : x);
}

int main1()
{
	int x,y,k,p,q;
	cin>>x>>y>>p>>q;
	int sol = nCr(p+q-1, p-1);
	sol = sol * power(x,p) % MOD * power(y,q) % MOD;
	cout<<sol<<endl;
	return 0;
}

signed main()
{

	memset(dp,-1,sizeof(dp));
	cerr<<nCr(1,0)<<endl;
	cerr<<nCr(2,0)<<endl;
	cerr<<nCr(1,1)<<endl;
	cerr<<nCr(8,3)<<endl;

	int t;
	cin>>t;
	while(t--) main1();
	return 0;
}

