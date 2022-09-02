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
int a[1000005],b[1000005],pos[1000005];

pi arr[1000005];

void RightRotate(int a[], int n, int k)
{
    k = k % n;
 
    for(int i = 0; i < n; i++)
    {
       if(i < k)
       {
           cout << a[n + i - k] << " ";
       }
       else
       {
           cout << (a[i - k]) << " ";
       }
    }
    cout << "\n";
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int t;
   cin>> t;
   while(t--){
     int n,k;
     cin >> n>>k;
     cin(a,n);
     RightRotate(a,n,k);
   }
  return 0;
}
 
