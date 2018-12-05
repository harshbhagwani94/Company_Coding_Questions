/*
Given 2 string A and B, convert string A into a palindromic string such that it 
contains the string B as it's substringby using minimum number of operations.

You are alllowed to use only one type of operation i.e. you can replace 
any character of the string s1 with any other character.

If it is not possible to find the palindromic string, then print -1.
*/

#include<bits/stdc++.h>
using namespace std;

void check(string str,int &cost)
{
	int n = str.size();
	int i=0, j =n-1;
	while(i<j)
	{
		if(str[i]!=str[j])
			cost++;
		i++;
		j--;
	}
}

int solve(string s1, string s2)
{
	int n1 = s1.size(), n2 = s2.size(), total_cost = INT_MAX;
	if(n2>n1)
		return -1;
	else if(n1==n2)
	{
		string temp = s2;
		reverse(temp.begin(), temp.end());
		if(temp==s2)
			return 0;
		else
			return -1;
	}
	bool isSPalin = false;
	string temp = s2;
	reverse(temp.begin(), temp.end());
	if(s2==temp)
		isSPalin = true;

	for(int i=0; i<n1-n2+1; i++)
	{
		string temp = s1;
		int cost = 0, error =0;
		for(int j=i;j<(i + n2); j++)
		{
			if(temp[j]!=s2[j-i])
			{
				temp[j] = s2[j-i];
				cost++;
			}
		}
		for(int j=0; j<n1/2; j++)
		{
			if(temp[j]!=temp[n1-j-1])
			{
				if(j<i || n1-j-1 > i+n2-1)
					cost++;
				else
					error=1;
			}
		}

		if(!error)
			total_cost = min(total_cost, cost);
	}
	return (total_cost==INT_MAX)?-1:total_cost;

}

int main1()
{
	string s1, s2;
	cin>>s1>>s2;
	cout<<solve(s1,s2)<<endl;
	return 0;
}

signed main()
{
	int t;
	cin>>t;
	while(t--) main1();
}