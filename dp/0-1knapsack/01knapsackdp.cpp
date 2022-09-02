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

int maxprof(int wt[],int val[],int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1)
    return dp[n][w];
  
    if(wt[n-1]<=w){
        dp[n][w]= max((val[n-1]+ maxprof(wt,val,w-wt[n-1],n-1)),maxprof(wt,val,w,n-1));
        return dp[n][w];
    }
    else if(wt[n-1]>w){
        dp[n][w]= maxprof(wt,val,w,n-1);
        return dp[n][w];
    }
    return 0;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   memset(dp,-1,sizeof(dp));
   int wt[4]={1,3,4,5};
    int val[4]={1,4,5,7};
    int w=7;
    cout << maxprof(wt,val,w,4);
  return 0;
}
 
