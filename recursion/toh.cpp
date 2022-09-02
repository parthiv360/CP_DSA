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


void toh(int n, char a, char c, char b){
    if(n==0)
    return;
    toh(n-1,a,b,c);
    cout << a << " " << c<< endl;
    toh(n-1,b,c,a);
}

int main(){
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    
    int n;
    cin>> n;
    cout << pow(2,n)-1 <<endl;
    toh(n,'1','3','2');
   return 0;
}