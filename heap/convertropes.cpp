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
   int a[5]={1,2,3,4,5};
   int n=5,x=7,k=3,cost=0;
   priority_queue<int,vector<int>,greater<int>>minh;
   for(int i=0;i<n;i++)
   minh.push(a[i]);
   while(minh.size()>=2){
       int f=minh.top();
       minh.pop();
       int s= minh.top();
       minh.pop();
        cost+=(f+s);
        minh.push(f+s);

   }
   cout << "Min cost:" << cost << endl;
  return 0;
}
 
