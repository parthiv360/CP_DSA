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


ll vis[100001],cc[100001];
vector<ll>adj[100001];
queue<ll>q;
ll cc_count;
void dfs(ll node){
    
     vis[node]=1;
     cc[node]=cc_count;
    for(ll i: adj[node])
    {
        if(!vis[i])
        dfs(i);
    }
}
void solve(){
    ll n,k;
    vector<pair<ll,ll>>vp;
    cin>>n>>k;
    cc_count=0;
    for(ll i=1;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
    }
    string op;
    ll x,y;
    for(ll i=1;i<=k;i++){
        cin>>x>>op>>y;
        if(op == "="){
            adj[x].push_back(y);
            adj[y].push_back(x);

        }
        else{
            vp.push_back({x,y});
        }

    }
    for(ll i=1;i<=n;i++){
        if(!vis[i])
        {
            dfs(i);
            cc_count++;
        }
    }
    bool f= true;
    for(ll i=0;i<vp.size();i++){
        x=vp[i].first;
        y=vp[i].second;

        if(cc[x]==cc[y]){
            f=false;
            break;
        }
    }
    if(f)
    cout << "YES\n";
    else
    cout << "NO\n";
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