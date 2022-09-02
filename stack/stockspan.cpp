#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
#define pie acos(-1.0)
typedef long long ll;
typedef long long int lli;
typedef long long unsigned llu;
typedef pair<int,int> pi;
#define cin(a,n)        for(ll i=0;i<n;i++)cin>>a[i];
#define store(b,n)      for(int i=1;i<=n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
ll a[1000005],b[1000005];


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int a[7]={100,80,60,70,60,75,85};
  vector<int>v;
  stack<pair<int,int>>st;
  for(int i=0;i<7;i++){
       if(st.size()==0)
       v.push_back(-1);
       else if(st.size()>0 && st.top().first>a[i])
       v.push_back(st.top().second);
       else if(st.size()>0 && st.top().first<=a[i]){
           while(st.size()>0 && st.top().first<=a[i])
           st.pop();
           if(st.size()==0)
           v.push_back(-1);
           else
           v.push_back(st.top().second);
       }
       st.push({a[i],i});
   }
   for(int i=0;i<7;i++){
       cout << i-v[i] << " ";
   }
   
  return 0;
}
 
