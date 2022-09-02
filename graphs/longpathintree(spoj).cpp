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


ll vis[100001];
vector<ll>adj[100001];
ll maxd,maxn;
void dfs(ll node, ll dis){
    vis[node]=1;
    if(dis>maxd){
        maxd=dis;
        maxn=node;
    }
    for(ll i: adj[node])
    {
        if(!vis[i])
        dfs(i, dis+1);
    }
    
}

int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    ll n,e;
    cin>>n;
    ll x,y;
    for(ll i=1;i<=n-1;i++)
    {
        cin>>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    maxd=-1;
    dfs(1,0);
    maxd=-1;
    for(ll i=1;i<=n-1;i++)
    vis[i]=0;
    dfs(maxn, 0);

    cout << maxd << endl;
    return 0;
}