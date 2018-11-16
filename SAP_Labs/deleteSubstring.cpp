/*

Given two string s and t, we want to delete either first or last occurence of substring t in s.
For example: if s = "bcbbc" and t = "b". then s could become either "cbbc" or "bcbc" after
performing the first move. The task is to find the maximum number of moves we can make for
a given s and t;

Example:
s = "bcbbc" and t = "b";
bcbbc - cbbc
cbbc - cbc
cbc - cc 
We are able to make 3 total moves.

Constraints:

1 <= |s| <= 2E4
1 <= |t| <= 1E2
Alphabets in s and t are in lowercase.

*/


#include<bits/stdc++.h>
using namespace std;

int res = 0;

void deleteSubstring(string s, string t, int level)
{
	res = max(res, level);
	int pos = s.find(t);
	if(pos>=0)
	{
		string temp = s;
		temp.erase(pos,t.length());
		deleteSubstring(temp,t,level+1);
	}

	int pos1 = s.rfind(t);
	if(pos1!=pos && pos1>=0)
	{
		string temp = s;
		temp.erase(pos1, t.length());
		deleteSubstring(temp,t, level+1);
	}
}


int main()
{
	string a,b;
	cin>>a>>b;
	deleteSubstring(a,b,0);
	cout<<res<<endl;
	return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

int res=0;

void check(string s,string ds,int level)
{
	res=max(0,level);
	int c=s.find(ds);
	if(c>=0)
	{
		string t=s;
		t.erase(c,ds.length());
		check(t,ds,level+1);
	}
	int c2=s.rfind(ds);
	if(c!=c2 && c2>=0)
	{
		string t=s;
		t.erase(c2,ds.length());
		check(t,ds,level+1);
	}
}
int main() {
string a,b;
cin>>a>>b;
check(a,b,0);
cout<<res<<endl;
return 0;
}*/