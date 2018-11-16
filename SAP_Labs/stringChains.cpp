/*
	https://www.careercup.com/question?id=5647083983863808
	Given an array of words representing your dictionary, you test each word to see if it can 
	be made into another word in the dictionary. This will be done by removing characters one at
	a time. Each word represents its own first element of its string chain, so start with a string chain 
	length of 1. Each time you remove a character, increment your string chain by 1. In order
	to remove a character, the resulting word must be in your original dictionary. You goal is
	determine the longest string chain achievable for a given dictionary.

	For example, given a dictionary [a, and, an, bear], the word 'and' could be reduced to 'an' 
	and	then to 'a'. The single character 'a' cannot be reduced any further as the 
	null string is not in the dictionary. This would be the longest string chain, 
	having the length 3. The word 'bear' cannot be reduced at all.

	Input:
	words[word[0].........word[n-1]]: an array of strings to test

	Constraints:
	1 <= N <= 50000
	1 <= |words[i]| <= 60, where 0 <= i <= n
	Each words[i] is composed of lower letters in ascii [a-z].

	Example 2:
	I/P:
	6
	a
	b
	ba
	bca
	bda
	bdca
	O/P:
	4
*/

#include<bits/stdc++.h>

using namespace std;

bool comp(string s1, string s2)
{
	return (s1.length()<s2.length());
}


int longestChain(vector<string> &strs)
{
	int N  = strs.size();
	vector<int> temp(N+1,1);
	map<string, int> mp;
	sort(strs.begin(), strs.end(), comp);
	for(int i=0; i<N; i++)
	{
		string str = strs[i];
		int l = strs[i].size();
		mp[str] = i+1;
		for(int j=0; j<l; j++)
		{
			char c = str[j];
			str.erase(str.begin()+j);
			if(mp[str]!=0 && temp[mp[str]]+1 > temp[i+1])
				temp[i+1] = temp[mp[str]]+1;
			str.insert(j,1,c);
		}
	}

	int maxChain = INT_MIN;
	for(int i=0; i<=N; i++)
		maxChain = max(maxChain, temp[i]);
	return maxChain;
}

int main()
{
	int N;
	cin>>N;
	vector<string> strs(N);
	for(int i=0; i<N; i++)	cin>>strs[i];
	cout<<longestChain(strs)<<endl;
	return 0;
}