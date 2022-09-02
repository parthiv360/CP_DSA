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

ll solve(ll a[],ll cur,ll sum, int i){
    if(i==0)
    return abs((sum-cur)-cur);

    return min(solve(a,cur+a[i],sum,i-1),solve(a,cur,sum,i-1));
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    cin(a,n);
    ll s=0;
    for( int i=0;i<n;i++)
    s+=a[i];
    cout << solve(a,0,s,n-1);
  return 0;
}
 
