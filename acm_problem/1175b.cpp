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

const ll inf= 1ll<<32;

int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   ll t,ans=0;
   cin>> t;
   stack<ll>st;
   st.push(1);
   while(t--){
       string s;
       cin>> s;
        if(s=="add")
        ans+=st.top();
        else if(s=="for"){
            ll n;
            cin>> n;
            n= min(inf,st.top()*n);
            st.push(n);
        }
        else{
            st.pop();
        }
   }
    if(ans>=inf)
    cout << "OVERFLOW!!!\n";
    else  
    cout << ans << endl;

  return 0;
}
 
