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





// ..........
// KAHN'S ALGORITHM
// ..........





ll vis[100001],in[100001],out[10001];
vector<ll>adj[100001];vector<ll>ans;

set<ll>se;
ll timer=0;

void kahn(ll n){
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(in[i]==0)
        q.push(i);
    }
    while(!q.empty()){
        ll cur= q.front();
        ans.push_back(cur);
        q.pop();

        for(ll i :adj[cur]){
            in[i]--;
            if(in[i]==0)
            q.push(i);
        }
    }

    cout << "TOPO SORT:\n";
    for(auto &i: ans)
    cout << i << " ";

}

void solve(){
    ll n,m;
    cin>>n>>m;
    while(m--){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]++;
    }
    kahn(n);
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