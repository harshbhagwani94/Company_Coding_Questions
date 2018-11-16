#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int search(int nodes[N], int element)
{
	for(int i=0;i<N;i++)
		if(nodes[i]==element)
			return i;
	return -1;
}

int findColor(int nodes[N], int edges[][2], int color[N])
{
	int sum=0;
	bool even=true;
	int clr=1;
	int index=0;
	int prev = 0;
	while(index<N-1)
	{
		int node = nodes[index];
		color[index] = clr;
		while(index<N-1 && edges[index][0]==node)
		{
			int i  = search(nodes, edges[index][1]);
			if(even)
				color[i] = clr+1;
			else
				color[i] = clr;
			index++;
		}
	}
}


int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, num,u,v;
		cin>>N;
		int nodes[N];
		int edges[N][2];
		for(int i=0;i<N;i++)
		{
			cin>>num;
			nodes[num];
		}

		for(int i=0;i<N-1;i++)
		{
			cin>>u>>v;
			edges[i][0]=u;
			edges[i][1]=v;
		}
		int color[N]={};
		int sum = findColor(nodes,edges, color);
		cout<<sum<<endl;
	}
	reutrn 0;
}
