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
int dp[1005][1005];
 

ll lcm(ll c,ll d){
    return (c/__gcd(c,d))*d;
}
ll c,d,n;

void pre(){
    ll g= __gcd(c,d);
    tie(c,d) = make_pair(g,c/g*d);
}

int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    cin>>n>>c>>d;
pre();
    ll i=2;
    while(i<n){
        ll x;
        cin>>x;
        d= __gcd(d,x);
        pre();
        i++;
    }
    cout << d << endl;
  return 0;
}