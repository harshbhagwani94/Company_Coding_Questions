#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n;
	cin>>n;
	vector<int> number(n,0);
	for(int i=0;i<n;i++)
		cin>>number[i];

	stack<int> s;
	int root = INT_MIN,i;
	for(i=0;i<n;i++)
	{
		if(number[i]<root)
		{
			cout<<"false"<<endl;
			break;
		}

		while(!s.empty() && s.top() < number[i])
		{
			root = s.top();
			s.pop();
		}

		s.push(number[i]);
	}

	if(i==n)
		cout<<"true"<<endl;
	return 0;
}