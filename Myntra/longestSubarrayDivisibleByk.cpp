/*
 Given an array and a value K.
 Find the longest subarray whose sum of element is divisible by k.
 https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/
*/

int longestSubarrayWithSumDivByK(vector<int> arr, int k)
{
    unordered_map<int, int> mp;
    int n = arr.size();
    vector<int> mod_sum(n);
    int maxLen = 0;
    int curr_sum=0;
    for(int i=0; i<n; i++)
    {
        curr_sum+=arr[i];
        mod_sum[i] = ((curr_sum % k) + k) % k;
    }
    for(int i=0; i<n; i++)
    {
        if(mod_sum[i]==0)
            maxLen = i+1;
        else if(mp.find(mod_sum[i])==mp.end())
            mp[mod_sum[i]]=i;
        else
            maxLen = max(maxLen, i-mp[mod_sum[i]]);
    }
    return maxLen;
}
