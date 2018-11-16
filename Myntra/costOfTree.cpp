/* 
We are given an array of integers, Each node of the tree has either two children or none
in which case it is a leaf node. A leaf node costs 0 to construct. The cost to build a
parent node is the product of the maximum leaf values in it left and right-sub trees. 

Partition the array to minimize the cost of building the entire tree.
Example:

Array : {4, 6, 2}. 
There are two possible choices to split the array :
Case 1:											Case 2:
{4} & {6,2}										{4,6} & {2}
This will result in cost  						This will result in cost
to 24											to 12.

The entire tree cost is 24 + 12  = 36

Constraints:
2 <= N <= 50
1 <= arr[i] <= 1000
*/

#include<bits/stdc++.h>

using namespace std;

int CostOfTree(vector<int> values)
{
	int N = values.size();
	vector<vector<int>> dp(N, vector<int>(N,0));

	for(int l=2; l<=N; l++)
	{
		for(int i=0; i<N-l+1; i++)
		{
			int j = i+l-1;
			cout<<i<<" "<<j<<endl;
			dp[i][j] = INT_MAX;
			for(int k = i; k<j; k++)
			{
				cout<<"K values: "<<k<<endl;
				int x = dp[i][k] + dp[k+1][j] + *max_element(values.begin()+i, values.begin()+k+1)*(*max_element(values.begin()+k+1,values.begin()+j+1));
				dp[i][j]=min(dp[i][j],x);
			}
		}
	}
	for(int i=0; i<N;i++)
	{
		for(int j=0; j<N; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	return dp[0][N-1];
}

int main()
{
	cout<<CostOfTree({4,6,2})<<endl;
	//cout<<CostOfTree({1,2})<<endl;
	return 0;
}
