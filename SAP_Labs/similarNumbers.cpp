/* Similar numbers 

Two numbers, without leading zeros, are similar if rearranging the digits gives matching
numbers i.e. numbers with equal frequency of each digit. For example, the numbers 1100 and
1001 are similar numbers, but 1100 and 0110 are not similar numbers because 0110 has
leading zero.

Given 2 strings representing long integers a and b, check their similarity. Based on
your finding, determine one of the following:

1. if a and b are similar, find the total number of similar numbers to a.
2. if a and b are not similar, find the total number of similar numbers to b.

For example: if a = 112 and b = 121, they are similar. We count the 3 numbers similar to a:
{112, 121, 211}

if a=11 and b = 223, they are not similar, so we count the 3 numbers similar to b: 
{223, 232, 322}.

I/P: a and b repreqents to long integer in string format.
Constraints:

1<= numeric values of a and b <= 1E15
The input do not contain ambiguous values. Specifically, there will be no leading zeros
such as a = 002 , b = 200.


Example:
1234
2341

O\P:
24


*/


#include<bits/stdc++.h>
using namespace std;

long factorial(int n)
{
	long fact = 1;
	for(int i=2;i<=n;i++)
		fact*=i;
	return fact;
}

int main()
{
	string a,b;
	cin>>a>>b;
	if(b[0]=='0')
	{
		cout<<0<<endl;
		return 0;
	}		
	int n = b.size();
	
	int nums[10]={};
	for(int i=0;i<n; i++)
		nums[b[i]-'0']++;

	int nz = 0;
	for(int i=1;i<10;i++)
		nz+=nums[i];

	long fact = nz*factorial(n-1);
	for(int i=0;i<10;i++)
		fact/=factorial(nums[i]);
	cout<<fact<<endl;
	return 0;
}
