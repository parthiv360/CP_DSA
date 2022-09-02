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


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
  
   ll n,k;
    cin >> n >>k;
    vector<ll> dpp(n,mod);
    for (ll i = 0; i < n; i++)
    cin >> a[i];
    dpp[0] = 0;
    for (ll i = 0; i < n; i++){
        for(ll j=i+1;j<=i+k;j++){
            if(j<n)
            dpp[j]=min(dpp[j],dpp[i]+abs(a[j]-a[i]));
        }
    }
    cout << dpp[n - 1];
  return 0;
}
 
