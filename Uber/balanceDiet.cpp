/*
Ankit is extremely lazy and buys boxes of pre-cooked food instead of preparing his own meals.
Each box contains N dishes and each dish has 2 properties, its protein content and 
its fat content. Ankit is planning on eating some non empty subset of there dishes.
He believes that his meal is balanced if 
the ratio of total protein consumed to total fat consumed is equal to some target value.

He wants to know if it is possible to create such a subset of dishes but doesn't have the skills
or the energy required to find it out.

I/P:
N Target.
next N lines contains proteins and fat.
Case 1
3 5
8 1 
1 1       O/P: YES
2 1

Case 2
3 6
8 1
1 1       O/P: NO
2 1

*/
#include<bits/stdc++.h>

using namespace std;

const int N = 50;

bool dp[N][510][510];

int test,n,target;

int main()
{
	cin>>test;
	while(test--)
	{
		cin>>n>>target;
		vector<int> pro(n), fat(n);
		for(int i = 0;i<n; i++)
			cin>>pro[i]>>fat[i];
		int tp=0, tf = 0;
		for(int i=0;i<n;i++)
			tp+=pro[i], tf+=fat[i];

		fill(&dp[0][0][0], &dp[0][0][0]+N*510*510, false);

		dp[0][0][0] = true;
		bool found = false;
		for(int i=1; i<=n; i++)
		{
			for(int j=0;j < tp+1 ; j++)
			{
				for(int k=0; k< tf+1 ; k++)
				{
					dp[i][j][k]|=dp[i-1][j][k];
					if(j>=pro[i-1] && k>=fat[i-1])
						dp[i][j][k]|=dp[i-1][j-pro[i-1]][k-fat[i-1]];

					if(j>0 && k>0 && dp[i][j][k] && j%k==0 && j/k==target)
						found=true;
				}
			}
		}

		if(found)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}