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
#define store(b,n)      for(int i=0;i<n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
ll a[1000005],b[1000005],pos[1000005];


pi arr[1000005];

string rev(string str)
{
    string y="";
   for (int i=str.length()-1; i>=0; i--)
      y+=str[i];
      return y;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    // memset(dp,-1,sizeof(dp));
    string x;
    cin>>x;
    string y = rev(x);
    int n= x.length();
    int m= y.length();
    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(x[i-1]==y[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);

        }
    }
    cout << dp[n][m] << endl;
  return 0;
}
 
