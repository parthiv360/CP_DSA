#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
typedef pair<int,int>pi;
#define cin(a,n)        for(ll i=0;i<n;i++)cin>>a[i];
#define store(b,n)      for(int i=1;i<=n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
ll a[1000005],b[1000005],pos[1000005];
pi arr[1000005];


class Graph 
{
public:
    map<int,bool>visited;
    map<int,list<int>> adj;
    void addEdge(int v, int w);
    void dfs(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::dfs(int v){
    visited[v]= true;
    cout << v << " ";

    list<int>::iterator it;
    for(it= adj[v].begin(); it!=adj[v].end();it++){
        if(!visited[*it])
        dfs(*it);
    }

}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.dfs(0);
  return 0;
}
 
