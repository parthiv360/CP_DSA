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

int findMin(int arr[], int n)
{
    
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
  
    
    bool dp[n + 1][sum + 1];
  
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
  
    
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
  
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            
            dp[i][j] = dp[i - 1][j];
  
            
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
  
    
    int diff = INT_MAX;
  
    
    for (int j = sum / 2; j >= 0; j--) {
        
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
//    memset(dp,-1,sizeof(dp));
   int wt[4]={1,5,6,11};
    // int val[4]={1,4,5,7};
    int w,n=4;
    cout << findMin(wt,n);
  return 0;
}
 
