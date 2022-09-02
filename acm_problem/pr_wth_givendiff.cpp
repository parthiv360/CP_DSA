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
ll a[1000005],b[1000005],pos[1000005];
pi arr[1000005];



int solve(ll *A,ll n1, ll B){
     int arr[2001] = {0}, *map, i;
 
 
map= &arr[1000];
 
 
for(i=0; i<n1; i++) map[A[i]]++;
 
for(i=0; i<n1; i++){
    
    
    if((A[i]+B>= -1000 && A[i]+B <=1000 )) 
    if((B==0 && map[-1*(A[i]+B)] >0 )||(B !=0 && map[A[i]+B] > 0)) return 1;
     
    
}
    return 0;
}

int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   ll n;
   cin>>n;
   cin(a,n);
   sort(a,a+n);
   ll m;
   cin>>m;
   if(solve(a,n,m)==1)
   cout << "YES\n";
   else 
   cout << "NO\n";
   
   
   
  return 0;
}
 
