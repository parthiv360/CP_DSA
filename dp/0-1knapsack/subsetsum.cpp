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
bool dp[1005][1005];


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
//    memset(dp,-1,sizeof(dp));
   int wt[5]={2,3,5,8,10};
    // int val[4]={1,4,5,7};
    int w=10,n=5;
   for(int i=0;i<n+1;i++){
       for(int j=0;j<w+1;j++){
       if(i==0)
        dp[i][j]=false;
        else if(j==0)
        dp[i][j]=true;
        else if(wt[i-1]<=j){
            dp[i][j]= (dp[i-1][j-wt[i-1]]) || (dp[i-1][j]);
        }
        else
        dp[i][j]=dp[i-1][j];
       }
   }
   cout << dp[n][w] << endl;
  return 0;
}
 
