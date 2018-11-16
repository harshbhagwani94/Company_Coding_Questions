/*

Dilku was thinking about the first time he met his girl... It was indeed a walk to remember. The romantic weather and her silly talks. He was completely mesmarized. Those were the days!..

Today is his girl's birthday and he wants to make it special for her. He wants to again take her on a "special walk" that they would remember for the lifetime.

The city in which Dilku lives is represented as an unweighted directed graph with N nodes and M edges. A "special walk" in the graph starting at node u is a simple path that begins and ends at the same node u.

Formally, A special walk is path u , a1 , a2 , a3 ,..., ai ,.... , u where ai are distinct and not equal to u for all i.

Now since Dilku is really nervous about taking his girl out, he needs your help. For every node in the given graph, tell whether it is possible for Dilku to take his girl on a "special walk" starting at that node.

Input:

First line of a two space separated integers denoting N and M, the number of nodes and number of directed edges in the corresponding graph.
Following M lines contain two space separated integers u v denoting a directed edge in the graph from vertex numbered u to vertex numbered v.

Output:

Print N space separated integers, where ith integer can be either 1 or 0 depicting whether it is possible to go on a special walk starting at node i or not.

Constraints:

    1 ≤ N ≤ 105
    1 ≤ M ≤ 2 · 105
    1 ≤ u, v ≤ N

Input:
5 5
1 2 
2 3 
3 4 
4 5
4 2

Output:
0 1 1 1 0

https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/description/

This program uses the concept of Strongly Connected Components to find all the cycle in the graph in O(V+E) time;

*/


#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int 	LL;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


const int N = 200050;
vector<int> g[N], gr[N];
vector<int> used(N), order, ans(N), comp;

void dfs(int u)
{
	used[u] = 1;
	for(auto v: g[u])
	{
		if(!used[v])
			dfs(v);
	}
	order.push_back(u);
}

void dfs2(int u)
{
	comp.push_back(u);
	used[u] = 1;
	for(auto v: gr[u])
	{
		if(!used[v])
			dfs2(v);
	}
}

int main()
{
	fast_io;
	int n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		gr[y].push_back(x);
	}

	for(int i=1;i<=n;i++)
	{
		if(used[i])
			continue;
		dfs(i);
	}
	reverse(all(order));
	fill(used.begin(), used.end(),0);

	for(int i=0; i<(int)order.size(); i++)
	{
		int id = order[i];	
		if(used[id])
			continue;
		comp.clear();
		dfs2(id);
		if(comp.size()==1)
			continue;
		for(int j=0;j<(int)comp.size(); j++)
			ans[comp[j]]=1;
	}

	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}


