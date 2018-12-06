/*

We are having an array prices, where ith price denote the price of a stock on ith day.
and we are having k, which represents at most k transaction.

We need to find the maximum profit with at most k transaction
Note : we must sell the stock before we can buy again.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
*/
int maxProfit(vector<int>& prices, int k) {
       
    int n = prices.size();
    if(n<=1)
        return 0;
    int maxProfit = 0;
    vector<vector<int>> dp(k+1, vector<int>(n));
    for(int i=1; i<=k; i++)
    {
        int tempMax = dp[i-1][0] - prices[0];
        for(int j=1; j<n; j++)
        {
            dp[i][j] = max(dp[i][j-1], tempMax + prices[j]);
            maxProfit = max(maxProfit, dp[i][j]);
            tempMax = max(tempMax, dp[i-1][j]-prices[j]);
        }
    }
    return maxProfit;
}
