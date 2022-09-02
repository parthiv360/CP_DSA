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


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    // memset(dp,-1,sizeof(dp));
    string x,y;
    cin>>x>>y;
    int m= x.length();
    int n= y.length();
  
    int dp[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         dp[i][j] = 0;
       else if (x[i-1] == y[j-1])
         dp[i][j] = dp[i-1][j-1] + 1;
       else
         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
     }
   }
   int index = dp[m][n];
  
   
   char lcs[index+1];
   lcs[index] = '\0';
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      
      if (x[i-1] == y[j-1])
      {
          lcs[index-1] = x[i-1]; 
          i--; j--; index--;     
      }
  
      
      else if (dp[i-1][j] > dp[i][j-1])
         i--;
      else
         j--;
   }
  
   
   cout <<  lcs;
  return 0;
}
 
