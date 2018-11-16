/*
    Hacker Industries has a number of employee. The company assigns each employee a numeric
    evaluation score and stores these scores in a list. A manager is assembling a team for
    a new project and selects a number of employees from the list to create a team. 
    He selects the team members in the following ways.

    1. During each selection, the manager chooses the employee with the highest score among 
       either the first m available employees or the last m available employees in the list.
       The manager then removes the selected employee from the list and adds them to the team.
       That employee's score is stored to the teamlist.

    2. If there are multiple employees with the same highest score among the first or last m available
       employees, the manager selects the employee whose score is at the lowest index in the list of scores.

    3. If there are fewer than m available employees, then the manager picks the employee with the 
       highest score from availabe employees.


    I/P:
    scores from 0......n-1 i.e score[score[0], score[1],........score[n-1]]
    team: number of members required
    m: the size of the array segements to select from:

    Constraints:
    1 <= N <= 1E5
    1 <= score[i] <= 1E9
    1 <= team <=n
    1 <=m <=n


*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, n, m, j, k, temp, team;
    cin>>n>>m>>team;
    vector<int> a;
    for(i=0;i<n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    priority_queue<pair<int, int> > pq;
    i = 0;
    while(i<n&&i<m){
        pq.push(make_pair(a[i], -i));
        i++;
    }
    j = n-1;
    while(j>=0&&j>=n-m){
        if(j>=i) pq.push(make_pair(a[j], -j));
        else break;
        j--;
    }
    int ans = 0;
    while(!pq.empty()&&team--){
        cout<<pq.top().first<<" "<<-pq.top().second<<"\n";
        ans+=pq.top().first;
        int idx = -pq.top().second;
        pq.pop();
        if(idx<i){
            if(i<=j){
                pq.push(make_pair(a[i], -i));
                i++;
            }
        }
        else if(idx>j){
            if(j>=i){
                pq.push(make_pair(a[j], -j));
                j--;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}