/*
Alex has an integer and wants to convert it to 0 using the following operations on its binary
representation.
1. Change the ith binary digit only if (i+1)th binary digit is 1 and all the other binary digit
   from (i+2) to the end are zeros.
2. Change the rightmost digit without restriction.

We can use above operations as many times as possible, but we want to determine the minimum
number of operations required. 
For example: n =8 and in binary it is : 1000.
So, we require 15 operations to convert it to zero.
1000
1001
1011
1010
1110
1111
1101
1100
0100
0101
0111
0110
0010
0011
0001
0000
*/
#include<bits/stdc++.h>

using namespace std;

int getRank(int n) {
    int ans = n;
    while (n >>= 1) ans ^= n;
    return ans;
}

int main()
{
	int x;
	cin>>x;
	cout<<getRank(x)<<endl;
	return 0;
}

