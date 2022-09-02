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
ll in[100001],out[100001];
ll timer=1;
void dfs(ll node){
    vis[node]=1;
    in[node]=timer++;
    for(ll i: adj[node])
    {
        if(!vis[i])
        dfs(i);
    }
    out[node]=timer++;
}

int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    ll n,e;
    cin>>n>>e;
    ll x,y;
    for(ll i=1;i<=e;i++)
    {
        cin>>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for(ll i=1;i<=n;i++)
    cout << in[i] << " " << out[i] << endl;
    return 0;
}