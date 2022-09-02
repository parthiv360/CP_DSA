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

void dfs(ll node, ll d){
    vis[node]=1;
    dis[node]=d;
    for(ll i: adj[node])
    {
        if(vis[i]==0)
        dfs(i,dis[node]+1);
    }
}

int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    ll n,q,x,y;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    cin>>q;
    ll g,ans=-1,mindis=INT_MAX;
    while(q--){
        cin>>g;
        if(dis[g]<mindis){
            mindis=dis[g];
            ans=g;
        }
        else if(dis[g]==mindis && g<ans)
        ans=g;
    }
    cout << ans ;
    return 0;
}