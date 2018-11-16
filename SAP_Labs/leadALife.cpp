/*
	You are working in Samara, Russia for a few days. Each day has a new pay per unit of
	work and a new cost per unit of food. Working 1 unit costs 1 unit of energy, and eating
	1 unit of food adds 1 unit of energy. Here, are some specifications of employment.

	1. You arrive with no money, but with energy. You can never have more energy than you arrive
	   with, and it can never be negative.
	2. You can do any amount of work everyday(possibly not do any work at all), limited only by
	   your energy. You cannot work when your energy is zero.
	3. You can eat any amount of food everyday(possibly bot have any food at all), limited by the
	   money you have. You cannot eat when the money you have is zero.
	4. You can eat food at the end of the day, and cannot return to work after eating. You can
	   return to work on the next day.

	Goal : is to maximize the amount of money you can take home.

	Example:
	Consider 3 day stay where per unit work for each day is as follows:
	earning = [1,2,4]
	cost = [1,3,6]
	and you start with E=5 units of energy.
	First day: 1 unit work is worth 1 and 1 unit food costs 1. There is no financial
	incentive to go to work this day.
	Second day: 1 unit work earns 2 and 1 unit food costs 3. Thus you spend more to eat
	thatn total earning so there is no financial incentive to go to work on this day.
	Third Day: you earn 4 units of work. The cost of food is irrelevant this day, as you 
	are leaving for the homes straight from work. You spend all of the energy working,
	collect your pays: 5x4 = 20.


	Constraint:
	1 <= n <= 100
	1 <= e <= 15
	1 <= earning[i] <= 100
	2 <= cost[i] <= 5

	Example 2:
	n = 2 
	earning = [1,2]
	cost = [1, 4]
	e = 5;
	Ans : 10
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int earn[n],cost[n], energy;
		cin>>n;
		cin>>energy;
		for(int i=0;i<n;i++)
			cin>>earn[i];
		for(int i=0;i<n;i++)
			cin>>cost[i];

		vector<int> arr(energy+1,0);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<=energy; j++)
			{
				for(int k=j; k<=energy; k++)
				{
					arr[j] = max(arr[j], arr[k] + earn[i]*(k-j));
				}
			}	

			/*cout<<"After earning the elements from the array: \n";
			for(int l = 0; l<=energy; l++)
				cout<<arr[l]<<" ";
			cout<<endl;*/

			for(int j=0; j<=energy; j++)
			{
				for(int k=j; k>=0 ;k--)
				{
					arr[j] = max(arr[j], arr[k]- cost[i]*(j-k));
				}
			}

			/*cout<<"After purchase the elements from the array: \n";
			for(int l = 0; l<=energy; l++)
				cout<<arr[l]<<" ";
			cout<<endl;*/
		}

		int maxVal = INT_MIN;
		for(int i=0; i<=energy; i++)
			maxVal = max(maxVal, arr[i]);

		cout<<maxVal<<endl;
	}
	return 0;
	/*int dp[n][er+1];
	for(int i=0;i<n;i++)
		for(int j=0;j<=er;j++)
			dp[i][j]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=er;j++)
		{
			dp[i][j]=max(dp[i][j],(er-j)*e[0]);
			dp[i][j]=max(dp[i][j],j*(e[0]-c[0]));
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<=er;k++)
			{
				for(int l=0;l<=er;l++)
				{
					//inc
					if(e[i]>=c[j])
					{
						dp[j][l]=max(dp[j][l],dp[i-1][l]+l*(e[i]-c[j]));
					}
					//cost
					if(k<=l)
						dp[j][l]=max(dp[j][l],dp[j-1][k]-(l-k)*c[j]);
					//earn
					if(k>=l)
						dp[i][l]=max(dp[i][l],dp[i-1][k]+(k-l)*e[i]);
				}
			}
		}
	}
	int max1=0;

	for(int i=n-1;i<n;i++)
	{
		for(int j=0;j<=er;j++)
			max1=max(max1,dp[i][j]);
	}
	cout<<max1<<endl;
	return 0;*/
}




/*
for (int i=0; i<n; i++){

for(int j=0; j<=e; j++){
for(int k=j; k<=e; k++){
arr[j] = max(arr[j], arr[k] + earn[i]*(k-j));
}
}

for(int j=0; j<=e; j++){
for(int k=j; k>0; k--){
arr[j] = max(arr[j], arr[k] - cost[i]*(k-j));
}
}
}

for(int i=0; i<=e; i++)
cout<<arr[i]<<" ";*/