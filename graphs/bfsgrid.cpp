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


ll vis[1001][1001],dis[1001][1001];
vector<ll>adj[100001];
queue<pair<ll,ll>>q;
 ll n,m;
bool isvalid(ll x, ll y){
    if(x<1 || x>n || y<1 || y>m)
    return false;
    if(vis[x][y]==1)
    return false;
    return true;
}
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void bfs(ll x, ll y){
    q.push({x,y});
    dis[x][y]=0;
    vis[x][y]=1;
    while(!q.empty()){
        ll curx=q.front().first;
        ll cury=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(isvalid(curx+dx[i],cury+dy[i])){
                ll newx=curx+dx[i];
                ll newy= cury+dy[i];
                dis[newx][newy]=dis[curx][cury]+1;
                vis[newx][newy]=1;
                q.push({newx,newy});
            }
        }
    }
    cout<<"Distance array:\n";
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++)
            cout << dis[i][j] << " ";
            cout << endl;
        
    }
}

int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    cin>>n>>m;
    ll c,d;
    cin>>c>>d;
    bfs(c,d);

    
    return 0;
}