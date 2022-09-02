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
    int i=n,j=m;
    string s="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
        s.push_back(x[i-1]);
        i--;
        j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
            s.push_back(y[j-1]);
            j--;
            }
            else{
            s.push_back(x[i-1]);
            i--;
            }
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
  return 0;
}
 
