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
ll cc_size;
void dfs(ll node){
    vis[node]=1;
    cc_size++;
    for(ll i: adj[node])
    {
        if(!vis[i])
        dfs(i);
    }
}

int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll n,e;
    cin>>n>>e;
    for(ll i=1;i<=n;i++){
        vis[i]=0;
        adj[i].clear();
    }
    ll x,y;
    for(ll i=1;i<=e;i++)
    {
        cin>>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll cnt=0;lli r=1;
    for(ll i=1;i<=n;i++){
        if(!vis[i])
        {
            cc_size=0;
            dfs(i);
            cnt++;
            r= (r*cc_size)%mod;
        }
    }
    cout << cnt << " " << r << endl;
    }
    return 0;
}