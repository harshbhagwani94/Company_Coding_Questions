/*
Given an array, we partition the A into at K subarray such that
then the score is the sum of the average of each group. 
What is the maximum score than can be scored ?

Input : A = { 9, 1, 2, 3, 9 }
K = 3
Output : 20
Explanation : We can partition A into [9], [1, 2, 3], [9]. 
The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9]. 
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

Input : A[] = { 1, 2, 3, 4, 5, 6, 7 }
K = 4
Output : 20.5
Explanation : We can partition A into [1, 2, 3, 4], [5], [6], [7]. 
The answer is 2.5 + 5 + 6 + 7 = 20.5.

https://www.geeksforgeeks.org/maximum-average-sum-partition-array/
*/

#include<bits/stdc++.h>

using namespace std;

double maximumAverage(vector<int> &nums, int K)
{
	int N = nums.size();
	vector<int> pre_sum(N+1,0);
	for(int i=0; i<N; i++)
		pre_sum[i+1] = pre_sum[i] + nums[i];

	vector<double> dp(N,0.0);
	for(int i=0; i<N; i++)
		dp[i] = (pre_sum[N] - pre_sum[i])/(N-i);

	for(int k=0; k<K-1; k++)
	{
		for(int i=0; i<N;i++)
		{
			for(int j= i+1; j<N; j++)
			{
				dp[i] = max(dp[i],((double)pre_sum[j]-pre_sum[i])/(j-i)+ dp[j]);
			}
		}
	}
	return dp[0];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,K;
		cin>>N>>K;
		vector<int> nums(N);
		for(int i=0;i<N;i++)	cin>>nums[i];
		cout<<maximumAverage(nums,K)<<endl;
	}
	return 0;
}
