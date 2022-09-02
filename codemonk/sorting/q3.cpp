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


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int i,n;
        int req[100001],index = 0;
        cin>>n;
        cin(a,n);
        unordered_map<int,int>mp;
        for(i=0;i<n;i++)
        mp[a[i]]++;
        for(auto x : mp)
        req[index++] = x.second;
        sort(req,req+index);
        int diff;
        diff = req[index-1] - req[0];
        if(diff>0)
            cout<<diff<<endl;
        else
            cout<<-1<<endl;
    }
  return 0;
}
 
