// same solution for target sum problem.
// use the same concept. use susbet sum as reference.


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
//    memset(dp,-1,sizeof(dp));
   int wt[4]={1,1,2,3};
   int d=1;
    // int val[4]={1,4,5,7};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=wt[i];
    int w= (d+sum)/2;
    dp[0][0]=1;
   for (int i = 1; i < w+1; i++)
        dp[0][i] = 0;
    for (int i = 1; i < n+1; i++)
        dp[i][0] = 1;
  
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
          
            if (a[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - wt[i - 1]];
            }
        }
    }
  
   cout << dp[n][w] << endl;
  return 0;
}
 
