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


ll vis[100001],in[100001],out[10001];
vector<ll>adj[100001];
queue<ll>q;
ll timer=0;
void dfs(ll node, ll par=-1){
    
    vis[node]=1;
    in[node]=out[node]=timer;
    timer++;
    ll c=0;
    for(ll i : adj[node]){
        if(i==par)
        continue;

        if(vis[i]==1){
            // back edge
            out[node]= min(out[node],in[i]);
        }
        else{
            // front edge
            dfs(i,node);
            out[node]=min(out[node],out[i]);
            ++c;
            if(out[i]>=in[node] && par!=-1)
            cout << "Articulation Point: " << node << endl;
        }
        if(par==-1 && c>1)  
        // condition for root 
        cout << "Articulation Point: " << node << endl;

        out[node]= min(out[node],out[i]);
    }

}
void solve(){
    ll n,m;
    cin>>n>>m;
    while(m--){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=0;i<n;i++){
        if(vis[i]==0)
        dfs(i);
    }

}
int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
    return 0;
}