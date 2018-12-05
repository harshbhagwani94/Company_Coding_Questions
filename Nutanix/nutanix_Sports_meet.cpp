/*

Nutanix IISc 2018
Given destination x = M, initial positions of participants x[1], x[2], .. x[N],
and constant speeds of participants y[1], y[2], .. y[N], the race goes on in a
single line formation such that noone can overtake someone else. Hence, if a 
person with higher speed meets another person with a lower speed during the race
then he starts moving at the lower speed for rest of the race.
Find the number of groups that will reach the destination. If two people meet
at the destination, they are also assumed to form a group.
1 <= #testcases <= 10
0 <= N <= 10^5
1 <= M <= 10^6
1 <= x[i] < M
1 <= y[i] <= 10^6
All x[i] are guaranteed to be different.
O(n log n)

*/

#include<iostream>
#include<vector>
#include<set>
#include <algorithm>


using namespace std;

struct nutanix
{
	int position;
	int speed;
	double time;
};

bool comp(nutanix n1, nutanix n2)
{
	return n1.position>n2.position;
}

const double eps = 1e-12;
int main()
{

	int size, dist;
	cin>>size>>dist;
	nutanix n[size];
	for(int i=0;i<size;i++)
		cin>>n[i].position;
	for(int i=0;i<size;i++)
		cin>>n[i].speed;

	
	for(int i=0;i<size;i++)
		n[i].time = (double)(dist-n[i].position)/n[i].speed;
		
	sort(n, n+size, comp);
	int count = 0, i=0;
	while(i<size)
	{
		double t = n[i].time;
		i++;
		count++;
		while(i<size && t>n[i].time-eps )
			i++;
	}
	cout<<count<<endl;
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-12;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<pair<int,double>> xts;
        for (int i = 0; i < n; i++) {
            double yi; cin >> yi;
            xts.emplace_back(-x[i], (m - x[i]) / yi);
        }
        sort(xts.begin(), xts.end());

        int ans = 0;
        double cur = 0;
        for (auto xt : xts) {
            if (xt.second > cur + eps) {
                cur = xt.second;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}*/

