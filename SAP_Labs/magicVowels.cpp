/*

We define a magical subsequence to a sequence of letters within a string that contains all the
5 vowels in order : a, e, i ,o, u. There can be any number of occurences of each vowel, 
but they must be in that order. For instance, aeeiou is a magical subsequence, but aeaioua is not.
The magical subsequences of each string (red) would be aeeiou and /a/ea/i/o/ua with length
of 6 and 5 respectively.

Julia has a string s, consisting of one or more of the following letters: a,e,i,o, and u.
She wants to determine the longest magical subsequence in her string.

I/P:
Given a string s:
Constraints:
5 < |s| < 5 x 1E5
string s is composed of English vowels (i.e. a,e,i,o and u)


*/


#include<bits/stdc++.h>
using namespace std;

#define a 0
#define e 1
#define i 2
#define o 3
#define u 4

int longestSubsequence(string str)
{
	int size = str.size();
	vector<int> dp(5,0);
	int isa=0, ise = 0, isi = 0, iso = 0, isu = 0;
	for(int j=0; j<size; j++)
	{
		if(str[j]=='a')
		{
			dp[a] = dp[a] + 1;
			isa = 1;
		}

		if(str[j]=='e' && isa)
		{
			dp[e] = max(dp[e]+1, dp[a]+1);
			ise  =1;
		}

		if(str[j]=='i' && ise)
		{
			dp[i] = max(dp[i]+1, dp[e]+1);
			isi = 1;
		}

		if(str[j]=='o' && isi)
		{
			dp[o] = max(dp[i]+1, dp[o]+1);
			iso = 1;
		}

		if(str[j]=='u' && iso)
		{
			dp[u] = max(dp[u]+1, dp[o]+1);
			isu = 1;
		}
	}

	if(isa && ise && isu && isi && iso)
		return dp[u];
	else
		return 0;
}


int main()
{
	string str;
	cin>>str;
	cout<<longestSubsequence(str)<<endl;
	return 0;
}