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
   ll n,k;
   cin>>n>>k;
   cin(a,n);
   sort(a,a+n);
   ll l=0,h=1e10;
   ll med=n/2;
   ll ans= a[med];
   while(l<=h){
       ll mid= l+(h-l)/2;
       ll sum=0;
       for(ll i=med;i<n;i++){
           if(a[i]<=mid)
           sum+=(mid-a[i]);
           if(sum>k)
           break;
       }
       if(sum<=k)
       {
           ans=max(ans,mid);
           l=mid+1;
       }
       else{
           h=mid-1;
       }
   }
   cout << ans << endl;
  return 0;
}
 
