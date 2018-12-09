/*
    Given an array A and a value k. Find the longest subarray which sums to k.
    https://www.geeksforgeeks.org/longest-sub-array-sum-k/
*/

int lenOfLongSubarr(vector<int> arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int maxLen = -1, sum=0;
    for(int i=0; i<n ;i++)
    {
        sum+=arr[i];
        if(sum==k)
            maxLen = i+1;
            
        if(mp.find(sum)==mp.end())
            mp[sum] = i;
        
        if(mp.find(sum-k)!=mp.end())
        {
            if(maxLen < (i - mp[sum-k))
                maxLen = i-mp[sum-k];
        }
    }
    return maxLen;
}
