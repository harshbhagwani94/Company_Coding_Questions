/*

Every Year Uber takes some of its empolyees on a vacation. This year is not different.

Uber has N employees, conveniently numbered from 1 to N. For each employee, we know which other
employees they are friend with. We also know that friendship is a bi-directional relation i.e.
if employee i is a friend of employee j, then j is also a friend of employee i.

An employee going on a vacation is only happy if they have at least K friends going with them.
Therefore, you must select the largest possible number of employees to go on vacation such that
every employee who goes on vacation has at least K friends going with them.
I/P:
N M K
where N vertices, M = edges and K = minimum number.
next M lines has 2 integer in one line.
 
O/P: Maximum number of people need to make everyone happy
https://www.geeksforgeeks.org/find-k-cores-graph/

I/P:

2
9 17 3
0 1
0 2
1 2
1 5
2 3
2 4
2 5
2 6
3 4
3 6
3 7
4 6
4 7
5 6
5 8
6 7
6 8
13 12 3
0 1 
0 2
0 3
1 4
1 5
1 6
2 7
2 8
2 9
3 10
3 12
3 11

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
void addEdge(vector<int> adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void printKCore(vector<int> adj[],int n,vector<int> &degree,int k)
{
    for(int s=0;s<n;s++){
        if(degree[s]<k) continue;
        cout<<s<<"-> ";
        for(int i=0;i<adj[s].size();i++){
            int x=adj[s][i];
            if(degree[x]<k) continue;
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void dfs(vector<int> adj[],int s,vector<bool> &visited,vector<int> &degree,int k,vector<bool> &processed)
{
    visited[s]=true;
    processed[s]=true;
    for(int i=0;i<adj[s].size();i++){
        int x=adj[s][i];
        if(visited[x]||processed[x])    continue;
        degree[x]--;
        if(degree[x]<k) dfs(adj,x,visited,degree,k,processed);
    }
}

void kCore(vector<int> adj[],int n, int k)
{
    vector<int> degree(n,0);
    for(int i=0;i<n;i++)    degree[i]=adj[i].size();
    int s=min_element(degree.begin(),degree.end())-degree.begin();
    if(degree[s]>k){
        printKCore(adj,n,degree,k);
        return;
    }
    vector<bool> processed(n,0);
    for(int i=0;i<n;i++){
        if(!processed[i]&&degree[i]<k){
            vector<bool> visited(n,false);
            dfs(adj,i,visited,degree,k,processed);
        }
    }
    printKCore(adj,n,degree,k);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> adj[n];
        while(m--){
            int a,b;
            cin>>a>>b;
            addEdge(adj,a,b);
        }
        kCore(adj,n,k);
    }
}
