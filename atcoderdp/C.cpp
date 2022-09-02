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
ll a[1000005],b[1000005],c[1000005];
pi arr[1000005];



int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
  
   ll n;
   cin>>n;
   for(ll i=0;i<n;i++)
   cin>> a[i] >> b[i] >> c[i];
    ll dp[n][3];
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    for(ll i=1;i<n;i++){
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
  return 0;
}
 
