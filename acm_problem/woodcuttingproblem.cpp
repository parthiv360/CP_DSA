#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
typedef pair<int,int>pi;
#define cin(a,n)        for(int i=0;i<n;i++)cin>>a[i];
#define store(b,n)      for(int i=0;i<n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
int a[1000005],b[1000005],pos[1000005];
pi arr[1000005];



int solve(int* A, int n1, int B) {
    int i,m=0;
    for(i=0;i<n1;i++)
   {
       if(A[i]>m)
       m=A[i];
   }
    int l=0,r=m;long ans=0;
    while(l<=r){
        int mid = l+(r-l)/2;
          long wood = 0;
          for(i=0;i<n1;i++){
              if(A[i]-mid>0){
                  wood = wood+A[i]-mid;
              }
          }
          
          if(wood>=(long)B){
              l = mid+1;
              if(mid>ans)
              ans=mid;
          }else{
              r = mid-1;
          }
      }
      return ans;
    }



int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int n;
   cin>>n;
   cin(a,n);
   int x;
   cin>>x;
   
   int sol= solve(a,n,x);
   cout << sol << endl;
  return 0;
}
 
