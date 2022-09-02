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

void solve(string s , string s1){
    if(s.length()==0){
    cout << s1 << endl;
    return;
    }
    string op1=s1,op2=s1;
    op2.push_back(s[0]);
    s.erase(s.begin()+0);
    solve(s,op1);
    solve(s,op2);

}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   string s;
   cin>>s;
   string s1="";
   solve(s,s1);
  return 0;
}
 
