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


ll vis[100001],dis[100001];
vector<ll>adj[100001];
queue<ll>q;

void bfs(ll node){
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    while(!q.empty()){
        ll cur=q.front();
        q.pop();
        for(ll i: adj[cur]){
            if(vis[i]==0){
                q.push(i);
                dis[i]=dis[cur]+1;
                vis[i]=1;
            }
        }
    }
    
}
void solve(){
    ll n,e;
    cin>>n>>e;
    ll x,y;
    for(ll i=1;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
    }
    for(ll i=1;i<=e;i++)
    {
        cin>>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    cout << dis[n] << endl;
}
int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}