#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
#define cin(a,n)        for(ll i=1;i<=n;i++)cin>>a[i];
#define store(b,n)      for(int i=0;i<n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
ll a[1000005],b[1000005],cnt[1000005];
int dp[100][100];

bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}
int solve(string String, int i, int j)
{
    if( i >= j || isPalindrome(String, i, j) )
      return 0;
      if(dp[i][j]!=-1)
      return dp[i][j];
    int ans = INT_MAX, count,l,r;
    for(int k = i; k < j; k++)
    {
    //   count = solve(String, i, k) +
    //     solve(String, k + 1, j) + 1;

    if(dp[i][k]!=-1)
    l=dp[i][k];
    else{
        l=solve(String,i,k);
        dp[i][k]=l;
    }
    if(dp[k+1][j]!=-1)
    r=dp[k+1][j];
    else{
        r=solve(String,k+1,j);
        dp[k+1][j]=r;
    }
        count=1+l+r;
      ans = min(ans, count);
    }
    return dp[i][j]=ans;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   memset(dp,-1,sizeof(dp));
    string s;
    cin>>s;
    int n= s.length();
     cout << solve(s,0,n-1);
    
  return 0;
}
 
