/*

You are given a number n, you have to convert the number to 0,
only operations allowed are:
1. flip the last bit
2. flip the ith bit only if (i+1)th bit is 1 and (i+2)th bit to end bits are 0

Example:
n = 0;
1000 -> 1001-> 1011 -> 1010 -> 1110 -> 1111 -> 1101 -> 1100 -> 0100 -> 0101 -> 0111 -> 0110 ->0010
-> 0011 -> 0001 -> 0000

Ans =  15:

*/

#include <bits/stdc++.h>

using namespace std;

int getRank(int n)
{
	int ans = n;
	while(n >>= 1)
		ans^=n;
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<getRank(n)<<endl;
	return 0;
}