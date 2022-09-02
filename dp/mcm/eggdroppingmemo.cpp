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
int dp[1005][1005];

ll solve(ll e, ll f){
    if(f==0 || f==1)
    return f;
    if(e==1)
    return f;
    if(dp[e][f]!=-1)
    return dp[e][f];
    ll mn=INT_MAX;ll lo,hi;
    for(ll k=1;k<=f;k++){
        // optimisation....
        if(dp[e-1][k-1]!=-1)
        lo=dp[e-1][k-1];
        else{
            lo=solve(e-1,k-1);
            dp[e-1][k-1]=lo;
        }
        if(dp[e][f-k]!=-1)
        hi=dp[e][f-k];
        else{
            hi=solve(e,f-k);
            dp[e][f-k]=hi;
        }

        ll t= 1+max(lo,hi);
        mn=min(mn,t);
    }
    dp[e][f]=mn;
    return mn;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
  
   ll e,f;
    cin >> e >>f;
    memset(dp,-1,sizeof(dp));
    cout << solve(e,f) << endl;
  return 0;
}
 
