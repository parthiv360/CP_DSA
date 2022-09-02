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
pi arr[1000005];


// fuck you constraints
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
  //  memset(dp,-1,sizeof(dp));
  ll n,w;
  cin>>n>>w;
  
  ll wt[n],val[n],s=0;
  for(ll i=0;i<n;i++){
  cin>> wt[i] >> val[i];
  s+=val[i];
  }
  ll dp[n+1][s+1];
 memset(dp,0,sizeof(dp));
  for(ll i=0;i<=s;i++)
  dp[0][i]=1e18;
  for(ll i=0;i<=n;i++)
  dp[i][0]=0;
  for(ll i=1;i<=n;i++){
      for(ll j=1;j<=s;j++){
          if(val[i-1]>j)
          dp[i][j]=dp[i-1][j];
          else
          dp[i][j]=min(dp[i-1][j],wt[i-1]+dp[i-1][j-val[i-1]]);
      }
  }
  ll ans;
  for(ll i=0;i<=s;i++){
      if(dp[n][i]<=w)
      ans=i;
  }
  cout << ans << endl;
  return 0;
}
 
