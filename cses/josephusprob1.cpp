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


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int n;
   cin>>n;
   int c=0,i=0;
   vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        v[i]=i;
    }
   while(c!=n){
       i+=2;
       int r= v[i%n];
        cout << r << " ";
        
        
        c++;
   }
  
    
  return 0;
}
 
