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
int dp[1000][1000];

pi arr[1000005];

int lcs(string x,string y,int n,int m){
    if(n==0 || m==0)
    return 0;

    if(dp[n][m]!=-1)
    return dp[n][m];
    
    if(x[n-1]==y[m-1])
    return dp[n][m]=(1+lcs(x,y,n-1,m-1));
    else{
        return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}

int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    memset(dp,-1,sizeof(dp));
    string x,y;
    cin>>x>>y;
    int n= x.length();
    int m= y.length();
    cout << lcs(x,y,n,m);
  return 0;
}
 
