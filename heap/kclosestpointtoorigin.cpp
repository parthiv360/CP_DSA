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
   int a[4][2]={{1,3},{-2,2},{5,8},{0,1}};
   int n=4,x=7,k=2;
   
   priority_queue<pair<int,pair<int,int>>>maxh;
   for(int i=0;i<n;i++){
       int d= (a[i][0]*a[i][0])+(a[i][1]*a[i][1]);
       maxh.push({d,{a[i][0],a[i][1]}});
       if(maxh.size()>k)
       maxh.pop();

   }
   while(maxh.size()>0){
       pair<int,int>p= maxh.top().second;
       cout << p.first <<" " << p.second<< endl;
        maxh.pop();
   }
 
  return 0;
}
 
