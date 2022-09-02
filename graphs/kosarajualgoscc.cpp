#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define REP(i,n) for (int i = 1; i <= n; i++)
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


vector<ll>ar[1001],tr[1001];
vector<ll>ord,scc;
ll vis[1001];
ll n,m;

void dfs(ll node)
{
	vis[node] = 1;
 
	for(ll child : ar[node])
	if(vis[child] == 0)
	dfs(child);
 
	ord.push_back(node);
}
 
void dfs1(ll node)
{
	vis[node] = 1;
 
	for(ll child : tr[node])
	if(vis[child] == 0)
	dfs1(child);
 
	scc.push_back(node);
}
int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--){
        cin>>n>>m;
        REP(i , n) ar[i].clear() , tr[i].clear() , vis[i] = 0;
        ord.clear();
        REP(i , m)
            {
                ll x,y;
                cin>>x>>y;
                ar[x].push_back(y);
                tr[y].push_back(x);
            }
        REP(i , n)
		if(vis[i] == 0) dfs(i);
 
		REP(i , n) vis[i] = 0;
        REP(i , n)
		if(vis[ord[n-i]] == 0)
		{
			scc.clear();
			dfs1(ord[n - i]);
 
			cout<<"dfs1() called from "<<ord[n-i]<<" and printing SCC"<<endl;
			for(ll node : scc)
			cout<<node<<" ";
			cout<<endl;
		}

   }
    
    return 0;
}