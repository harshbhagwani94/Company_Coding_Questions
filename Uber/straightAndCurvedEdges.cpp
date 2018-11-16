/*

	We are given a list of edges in a graph and for each pair of vertices that are connected
	by an edge, there are two edges between them, one curved and one straight edge. i.e
	the tuple is in the in the form (x,y,w1,w2) means between vertices x and y, there is a straight
	edge with weight w1 and a curved edge with weight w2. We are given two vertices a and b and you 
	have to go from a to b through series of edges such that in the entire path you can use atmost 
	1 curved edge. The task is to find the shortest path from a to b satisfying above condition.

*/
/*#include<bits/stdc++.h>
using namespace std;

int main() {
    long n, m;
    cin >> n >> m;
    vector<pair<long, long> > s[n];
    vector<vector<long> > c(2*m, vector<long>(3));
    for(long t=0; t<m; ++t) {
        long i, j, p, q;
        cin >> i >> j >> p >> q;
        s[i].push_back({j, p}); 
        s[j].push_back({i, p});
        c[t] = {i, j, q};
        c[m+t] = {j, i, q};
    }
    long start, end;
    cin >> start>>end;
    vector<long> distf(n, INT_MAX);
    distf[start] = 0;
    priority_queue<pair<long, long>, vector<pair<long, long> > , greater<pair<long, long> > > q;
    q.push({distf[start], start});
    while(!q.empty()) {
        pair<long, long> p1 = q.top();
        q.pop();
        long s1 = p1.second, d1 = p1.first;
        for(long i=0; i<s[s1].size(); ++i) {
            pair<long, long> p2 = s[s1][i];
            long s2 = p2.first, d2 = p2.second;
            if(distf[s2] > d1+d2) {
                distf[s2]  = d1+d2;
                q.push({distf[s2], s2});
            }
        }
    }
    vector<long> distb(n, INT_MAX);
    distb[end] = 0;
    priority_queue<pair<long, long>, vector<pair<long, long> > , greater<pair<long, long> > > q1;
    q1.push({distb[end], end});
    while(!q1.empty()) {
        pair<long, long> p1 = q1.top();
        q1.pop();
        long s1 = p1.second, d1 = p1.first;
        for(long i=0; i<s[s1].size(); ++i) {
            pair<long, long> p2 = s[s1][i];
            long s2 = p2.first, d2 = p2.second;
            if(distb[s2] > d1+d2) {
                distb[s2]  = d1+d2;
                q1.push({distb[s2], s2});
            }
        }
    }
    long ans = distf[end];
    for(long i=0; i<2*m; ++i) {
        long ii = c[i][0], jj = c[i][1], dd = c[i][2];
        long new_ans = distf[ii] + dd + distb[jj];
        ans = min(new_ans, ans);
    }
    cout << ans << endl;
}*/
#include<bits/stdc++.h>

using namespace std;

/*typedef pair<int,int> pii;
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
*/
int main()
{
	long n,m;
	cin>>n>>m;
	vector<pair<long, long> > s[n];
	vector<vector<long> > c(2*m, vector<long>(3));
	for(long t=0;t<m;++t)
	{
		long i,j,p,q;
		cin >> i >>j >> p >> q;
		s[i].push_back({j, p});
		s[j].push_back({i, p});
		c[t] = {i, j, q};
		c[m+t] = {j, i, q};
	}
	/*    for(long t=0; t<m; ++t) {
        long i, j, p, q;
        cin >> i >> j >> p >> q;
        s[i].push_back({j, p}); 
        s[j].push_back({i, p});
        c[t] = {i, j, q};
        c[m+t] = {j, i, q};
    }*/



	long start, end;
	cin>>start>>end;
	priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>> > q, q1;
	vector<long> distf(n, INT_MAX);
	distf[start] = 0;
	q.push({distf[start], start});
	while(!q.empty())
	{
		pair<long, long> p = q.top();
		q.pop();
		long d1 = p.first;
		long s1 = p.second;
		for(auto &it: s[s1])
		{
			long d2 = it.second;
			long s2 = it.first;
			if(distf[s2]> d1+d2)
			{
				distf[s2] = d1+d2;
				q.push({distf[s2],s2});
			}
		}
	}

	vector<long> distb(n, INT_MAX);
	distb[end] = 0;
	q1.push({distb[end], end});
	while(!q1.empty())
	{
		pair<long, long> p = q1.top();
		q1.pop();
		long d1 = p.first;
		long s1 = p.second;
		for(auto it: s[s1])
		{
			long s2 = it.first;
			long d2 = it.second;
			if(distb[s2]>d1+d2)
			{
				distb[s2] = d1+d2;
				q1.push({distb[s2],s2});
			}
		}
	}


	long ans = distf[end];
	for(long i=0;i<2*m;i++)
	{
		long ii = c[i][0];
		long jj = c[i][1];
		long dd = c[i][2];
		long new_ans = distf[ii] + dd + distb[jj]; 
		ans = min(ans, new_ans);
	}

	cout<<ans<<endl;
	return 0;
}	