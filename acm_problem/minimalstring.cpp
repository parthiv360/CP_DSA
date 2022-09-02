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

int ch[26];
char s[1000005], t[1000005], u[1000005],m[1000005];




int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    cin>>s;
    int n=strlen(s);
    int c=0, k=0;
	m[n]='z'+1;
    m[n-1]=s[n-1];
	for(int i=n-2; i>=0; --i){
		m[i]=min(m[i+1],s[i]);
	}
	for(int i=0; i<n; ++i){
		t[c++]=s[i];
		while(c && t[c-1]<=m[i+1]) 
        u[k++]=t[--c];
	}
	u[k]=0;
	printf("%s\n", u);


  return 0;
}
 
