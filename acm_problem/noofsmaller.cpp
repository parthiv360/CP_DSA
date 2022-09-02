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


ll binary_search(ll arr[], ll l, ll h, ll x)
{
    while (l <= h) {
        ll mid = (l + h) / 2;
 
        
        if (arr[mid] < x)
            l = mid + 1;
 
        
        else
            h = mid - 1;
    }
 
    
    return h;
}
 

void count(
    ll arr1[], ll arr2[],
    ll m, ll n)
{

    for (ll i = 0; i < m; i++) {
        
        ll index = binary_search(
            arr2, 0, n - 1, arr1[i]);
 
        
        cout << (index + 1) << " ";
    }
}

int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   ll n,m;
   cin>>n >> m;
   
   cin(a,n);
   cin(b,m);
   count(b,a,m,n);
   
   
  return 0;
}
 
