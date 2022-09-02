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


void solve(int c1,int c0,int n,string op, vector<string> &v){
    if(n==0){
        v.push_back(op);
        return;
    }
    string op1=op;
    op1.push_back('1');
    solve(c1+1,c0,n-1,op1,v);

    if(c1>c0){
        string op2=op;
        op2.push_back('0');
        solve(c1,c0+1,n-1,op2,v);
    }
    return;
}
vector<string> form(int n){
    vector<string>v;
    int c0=0,c1=0,n1=n;
    string op="";
    solve(c1,c0,n,op,v);
    return v;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int n;
   cin>>n;
   vector<string> ans;
   ans= form(n);
   for(int i=0;i<ans.size();i++)
   cout << ans[i] << endl;
  return 0;
}
 
