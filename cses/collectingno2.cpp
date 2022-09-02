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
#define store(b,n)      for(int i=1;i<=n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
ll a[1000005],b[1000005],pos[1000005];
pi arr[1000005];
int dp[1005][1005];


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    

    int n,m; cin>>n>>m;
    int l = 1;
    int ind[n+2] = {0}, a[n+1] = {0};
    ind[n+1] = n+1;
    for (int i = 1; i <= n; i++) {
		int x; cin>>x;
		ind[x] = i;
		a[i] = x;
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
		if (l > ind[i]) 
		c++;
		l = ind[i];
    }
    while(m--) {
		int x,y; cin>>x>>y;
		int r = a[x], s = a[y];
		swap(a[x], a[y]);
		if (ind[r-1] <= ind[r] && ind[r-1] > y) c++;
		if (ind[r-1] > ind[r] && ind[r-1] <= y) c--;
		if (ind[r] <= ind[r+1] && y > ind[r+1]) c++;
		if (ind[r] > ind[r+1] && y <= ind[r+1]) c--;		
		ind[r] = y;
		if (ind[s-1] <= ind[s] && ind[s-1] > x) c++;
		if (ind[s-1] > ind[s] && ind[s-1] <= x) c--;
		if (ind[s] <= ind[s+1] && x > ind[s+1]) c++;
		if (ind[s] > ind[s+1] && x <= ind[s+1]) c--;	
		ind[s] = x;
		cout<<c<<endl;
    }
    
  return 0;
}
 
