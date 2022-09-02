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
unordered_map<string,bool>mp;


bool solve(string s, string s1)
{
    if(s.length()!=s1.length())
    return false;
    ll n=s.length();
    if(n==0)
    return false;
    if(s==s1)
    return true;
    string copy_S1 = s, copy_S2 = s1;
 
    sort(copy_S1.begin(), copy_S1.end());
    sort(copy_S2.begin(), copy_S2.end());
 
    if (copy_S1 != copy_S2) {
        return false;
    }
    string key = (s + " " + s1);
    if (mp.find(key) != mp.end()) {
        return mp[key];
    }
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (solve(s.substr(0, i), s1.substr(0, i))
            && solve(s.substr(i, n - i),
                          s1.substr(i, n - i))) {
            flag=true;
            return true;
        }
        if (solve(s.substr(0, i),
                       s1.substr(n - i, i))
            && solve(s.substr(i, n - i),
                          s1.substr(0, n - i))) {
            flag=true;
            return true;
        }
    }
    mp[key]=flag;
    return false;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    string s,s1;
    cin>>s>>s1;
    cout<<solve(s,s1)<< endl;
    
  return 0;
}
 
