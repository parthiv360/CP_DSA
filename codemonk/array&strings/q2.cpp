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
int m[1000][1000];

pi arr[1000005];


int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int t;
   cin>> t;
   while(t--){
     int n;
     cin>>n;
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++)
         cin>> m[i][j];
     }
     int c=0;
     for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int x = i; x < n; ++x) {
					for (int y = j; y < n; ++y) {
						if (m[x][y] < m[i][j]) c++;
					}
				}
			}
		}

		cout << c << endl;
   }
  return 0;
}
 
