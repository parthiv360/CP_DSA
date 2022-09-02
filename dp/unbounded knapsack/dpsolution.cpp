// same solution for rod cutting problem
// no change in the code.

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
   memset(dp,-1,sizeof(dp));
   int wt[4]={1,3,4,5};
    int val[4]={10,40,50,70};
    int w=8,n=4;
   for(int i=0;i<n+1;i++){
       for(int j=0;j<w+1;j++){
       if(i==0)
        dp[i][j]=0;
        else if(j==0)
        dp[i][j]=0;
        else if(wt[i-1]<=j){
            dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
        }
        else
        dp[i][j]=dp[i-1][j];
       }
   }
   cout << dp[n][w] << endl;
  return 0;
}
 
