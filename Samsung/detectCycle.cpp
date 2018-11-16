#include <iostream>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<pair<ll,ll>> vll;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL) {};
};

const int N = 1e3;
Node* graph[N];
int parent[N];
bool iscycle[N];
bool found;
bool vis[N];
int n, m;

void dfs(int u, int p){
    vis[u] = true;
    parent[u] = p;
    Node* curr = graph[u];
    while(curr){
        if(!vis[curr->val]){
            dfs(curr->val, u);
        }else{
            found = true;
            iscycle[curr->val] = true;
            while(u != curr->val){
                iscycle[u] = true;
                u = parent[u];
            }
        }
        if(found) return;
        curr = curr->next;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        graph[i] = NULL;
        iscycle[i] = false;
        vis[i] = false;
        parent[i] = -1;
    }

    int u, v;
    for(int i = 0; i < m; i++){
        cin>> u >> v;
        Node* curr = graph[u];
        if(!curr) graph[u] = new Node(v);
        else{
            while(curr->next){
                curr = curr->next;
            }
            curr->next = new Node(v);
        }
    }
    
    found = false;
    for(int i=0;i<=n;i++)
        if(vis[i]!=-1)
            dfs(i, -1);

    if(!found) printf("-1\n");
    else{
        for(int i = 1; i <= n; i++){
            if(iscycle[i]) printf("%d ", i);
        }
        printf("\n");
    }
}

