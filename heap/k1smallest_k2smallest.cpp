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

int smallest(int a[],int k, int n){
    priority_queue<int>maxh;
   for(int i=0;i<n;i++){
       maxh.push(a[i]);
       if(maxh.size()>k){
           maxh.pop();
       }
   }
   return maxh.top();
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int a[6]={1,3,12,5,15,11};
   int n=6,k1=3,k2=6;
  int f= smallest(a,k1,n);
  int s= smallest(a,k2,n);
  int sum=0;
  for(int i=0;i<n;i++){
      if(a[i]>f && a[i]<s)
      sum+=a[i];
  }
 cout << "Sum:" << sum << endl;
  return 0;
}
 
