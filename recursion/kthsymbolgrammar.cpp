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

int solve(int n, int k){
    if(n==1 && k==1)
    return 0;
    int mid= pow(2,n-1)/2;
    if(k<=mid){
        return solve(n-1,k);
    }
    else{
        return !solve(n-1,k-mid);
    }
}


int main(){
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    
    int n,k;
    cin>> n>>k;
    cout<< solve(n,k) << endl;
   return 0;
}