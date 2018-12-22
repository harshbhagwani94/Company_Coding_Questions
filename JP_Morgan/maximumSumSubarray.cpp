/*

Given an array arr and number K, segment the array into K contiguous subarrays with 
at least 1 element in each subarray such that the sum of averages of each subarray is maximum.

Example 1:
arr = [9,1,2,3,9]
K = 3
maximum value = 9 + (1+2+3)/3 + 9 = 20.

Example 2:
arr = [1,2,3,4,5,6,7]
K=4
maximum value = [1,2,3,4],[5],[6],[7] = 2.5+5+6+7 = 20.5
https://www.geeksforgeeks.org/maximum-average-sum-partition-array/
*/
#include<bits/stdc++.h>

using namespace std;

int maximumSumSubarray(vector<int> &arr, int K)
{
	int n = arr.size();
	vector<double> pre_sum(n+1);
	for(int i=0; i<n; i++)
		pre_sum[i+1] = pre_sum[i] + arr[i];

	vector<double> dp(n);
	double sum=0;
	for(int i=0; i<n; i++)
		dp[i] = (pre_sum[n]-pre_sum[i])/(n-i);

	for(int k=0; k<K-1; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
				dp[i] = max(dp[i], (pre_sum[j]-pre_sum[i])/(j-i) + dp[j]);
		}
	}
	return dp[0];
}

int main()
{
	vector<int> arr = {9,1,2,3,9};
	int K = 3;
	cout<<maximumSumSubarray(arr, K)<<endl;
	return 0;
}
