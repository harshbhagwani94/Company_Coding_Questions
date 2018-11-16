/*

	Given a circular array containing of positive integers value. 
	The task is to find the maximum sum of a subsequence with the constraint that no 2 numbers 
	in the sequence should be adjacent in the array.

	Examples:
	Input: circular arr = {1, 2, 3, 1}
	Output : 4
	subsequence will be(1, 3), hence 1 + 3 = 4 

	Input: circular arr = {1, 2, 3, 4, 5, 1}
	Output: 9
	subsequence will be(1, 3, 5), hence 1 + 3 + 5 = 9 

*/

#include<bits/stdc++.h>

using namespace std;

int gets(vector<int> crops, int fl)
{
	int n = crops.size();
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][1] = crops[0];
	for(int i = 1; i<n; i++)
	{
		dp[i][0] = max(dp[i-1][0], dp[i-1][i]);
		dp[i][1] = dp[i-1][0] + crops[i];
	}
	return dp[n-1][fl];
}

int solve(vector<int> crops)
{
	if(crops.size()==1)
		return crops[0];
	int x = gets(crops,0);
	crops[0]  =0;
	return max(x, gets(crops,1));
}

int main()
{
	cout<<solve({400});
	return 0;
}