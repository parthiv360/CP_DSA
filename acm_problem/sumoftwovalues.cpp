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


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   ll n,x;
   cin>>n>>x;
   cin(a,n);
   map<ll,ll> m;
   for(int i=0;i<n;i++){
       if(m.count(x-a[i]))
       {
           cout << m[x-a[i]]  << " " << i+1  << endl;
           return 0;
       }
       m[a[i]]=i+1;
   }
   cout << "IMPOSSIBLE\n";
  return 0;
}
 
