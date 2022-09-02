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
ll color[100001];

bool dfs(ll node, ll parent){
    vis[node] = 1;
	
	for(ll v : adj[node])
	{
		if(vis[v] == 0){
			if(dfs(v,node)==true)
            return true;
		}
		else{
			if(v!=parent)
            return true;
		}
	}
	
	return false;
}

int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll x,y;
    for(ll i=1;i<=m;i++)
    {
        cin>>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(dfs(1,-1)==true)
    cout << "YES\n";
    else
    cout << "NO\n";
    return 0;
}