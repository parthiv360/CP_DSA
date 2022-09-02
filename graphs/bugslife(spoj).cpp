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


ll vis[2001];
vector<ll>adj[2001];
ll color[2001];

bool dfs(ll node, ll c){
    vis[node] = 1;
	color[node] = c;
	
	for(ll v : adj[node])
	{
		if(vis[v] == 0){
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
    ll t;
    cin>>t;
    for(ll j=1;j<=t;j++){
        ll n,m;
        cin>>n>>m;
        ll x,y;
        for(ll i=1;i<=n;i++){
            vis[i]=0;
            adj[i].clear();
        }
        for(ll i=1;i<=m;i++){
            
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool f= true;
        for(ll i=1;i<=n;i++){
            if(vis[i]==0){
                bool res= dfs(i,0);

                if(res==false)
                f=false;
            }
        }
        cout << "Scenario #"<< j << ":"<< endl;
        if(f==false)
        cout << "Suspicious bugs found!" << endl;
        else
        cout << "No suspicious bugs found!" << endl;
    }
    return 0;
}