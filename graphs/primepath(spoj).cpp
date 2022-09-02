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


ll vis[100001],dis[100001];
vector<ll>adj[100001];
vector<ll>primes;
queue<ll>q;

bool isprime(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)
        return false;
    }
    return true;
}

bool isvalid(ll d,ll e){
    ll cnt=0;
    while(d>0){
        if(d%10!= e%10)
        cnt++;
        d=d/10;
        e=e/10;
    }
    if(cnt==1)
    return true;
    else
    return false;
}

void build(){
    for(ll i=1000;i<=9999;i++){
        if(isprime(i)==true)
        primes.push_back(i);
    }
    for(ll i=0;i<primes.size();i++){
        for(ll j=i+1;j<primes.size();j++){
            ll e= primes[i];
            ll f= primes[j];
            if(isvalid(e,f)){
                adj[e].push_back(f);
                adj[f].push_back(e);
            }
        }
    }
}

void bfs(ll node){
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    while(!q.empty()){
        ll cur=q.front();
        q.pop();
        for(ll i: adj[cur]){
            if(vis[i]==0){
                q.push(i);
                dis[i]=dis[cur]+1;
                vis[i]=1;
            }
        }
    }
    
}

void solve(){
   ll x,y;
   cin>>x>>y;
   for(ll i=1000;i<=9999;i++){
       dis[i]=-1;
       vis[i]=0;
   }
   bfs(x);
   if(dis[y]==-1)
   cout << "Impossible\n";
   else
   cout << dis[y] << endl;
}


int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    build();
    while(t--)
    solve();
    return 0;
}