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

char ar[1001][1001];
ll vis[1001][1001];
vector<ll>adj[100001];

 ll n,m;
bool isvalid(ll x, ll y){
    if(x<1 || x>n || y<1 || y>m)
    return false;
    if(vis[x][y] == 1 || ar[x][y] == '#')
	return false;
    return true;
}
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void dfs(ll x, ll y){
   vis[x][y]=1;
//    cout << x << " " << y << endl;

   for(int i=0;i<4;i++){
       if(isvalid(x+dx[i],y+dy[i]))
       dfs(x+dx[i],y+dy[i]);
   }

}

int main()
{
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>ar[i][j];
        }
    }
    int cnt=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(vis[i][j]==0 && ar[i][j]=='.'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt << endl;
    // dfs(1,1);
    return 0;
}