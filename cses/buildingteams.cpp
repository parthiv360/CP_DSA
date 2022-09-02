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


bool vis[100001];
vector<ll>adj[100001];
ll color[100001];

bool dfs(ll node, ll c){
    vis[node] = true;
	color[node] = c;
	
	for(ll v : adj[node])
	{
		if(vis[v] == false){
			bool res = dfs(v , c ^ 1);
			if(res == false) return false;
		}
		else{
			if(color[node] == color[v]) return false;
		}
	}
	
	return true;
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
    bool f=true;
    for(ll i=1;i<=n;i++){
        if(vis[i] == false)
	{
		f = dfs(i , 0);
		if(f == false) break;
	}
    }
    if(!f)
    cout << "IMPOSSIBLE\n";
    else
    {
        for(ll i=1;i<=n;i++)
        cout << color[i]+1 << " " ;
    }
    return 0;
}