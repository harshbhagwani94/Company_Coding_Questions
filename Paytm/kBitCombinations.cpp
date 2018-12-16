/*
	Find all the combinations of k-bit numbers with n bitset with 1<=n<=k in sorted order
	Example: K=3
	001 010 100
	011 101 110
	111
	https://www.geeksforgeeks.org/find-combinations-k-bit-numbers-n-bits-set-1-n-k-sorted-order/
	
*/

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int 	LL;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void findCombinations(int k)
{
	string str="";
	vector<string> dp[k+1][k+1];
	for(int l=0; l<=k; l++)
	{
		dp[l][0].push_back(str);
		str = "0" + str;
	}

	for(int l=1; l<=k; l++)
	{
		for(int n=1; n<=l; n++)
		{
			for(string str : dp[l-1][n])
				dp[l][n].push_back("0" + str);

			for(string str : dp[l-1][n-1])
				dp[l][n].push_back("1" + str);
		}
	}

	for(int n=1; n<=k; n++)
	{
		for(string str : dp[k][n])
			cout<<str<<" ";
		cout<<endl;
	}
}

int main()
{
	int k;
	cin>>k;
	findCombinations(k);
	return 0;
}
