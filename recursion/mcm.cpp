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
int ma[100][100];

int solve(int arr[], int i, int j){
    if(i>=j)
    return 0;
    int mi=INT_MAX,temp=0;
    for(int k=i;k<=j-1;k++){
        temp= solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        mi=min(mi,temp);
    }
    return mi;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
     int arr[4] = { 1, 2, 3, 4 };
     int n=4;
     cout << solve(arr,1,n-1);
    
  return 0;
}
 
