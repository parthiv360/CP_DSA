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
int ma[100][100];

pi arr[1000005];

char s[1000000];

int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
   ll n,x;
   cin>>x>>n;
   set<ll>li; multiset<ll>p;
   li.insert(0);
   li.insert(x);
   p.insert(x);
   while(n--){
       ll c;
       cin>>c;
       auto it = li.upper_bound(c);
       auto it2=it;
       --it2;
       p.erase(p.find(*it-*it2));
       p.insert(c-*it2);
       p.insert(*it-c);
       li.insert(c);
       auto ans= p.end();

       --ans;
       cout << *ans << " ";

   }
  return 0;
}
 
