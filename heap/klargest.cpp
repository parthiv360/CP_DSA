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
   int a[6]={7,3,10,4,20,15};
   int n=6,k=3;
   priority_queue<int,vector<int>,greater<int>>minh;
   for(int i=0;i<n;i++){
       minh.push(a[i]);
       if(minh.size()>k){
           minh.pop();
       }
   }
  while(minh.size()>0){
      cout << minh.top() << " ";
      minh.pop(); 
  }
 
  return 0;
}
 
