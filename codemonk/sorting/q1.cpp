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
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
    cin>>s[i];
    vector<int>ans(n,0);
    ans[0]=0;
    for(int i=1;i<n;i++){
      int j=0;int c=0;
      while(j<i){
      if(s[j]<s[i])
      c++;
      j++;
      }
      ans[i]=c;
    }
    for(int i=0;i<n;i++)
    cout << ans[i] <<endl; 
  return 0;
}
 
