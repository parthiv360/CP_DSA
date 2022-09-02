#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
#define cin(a,n)        for(ll i=1;i<=n;i++)cin>>a[i];
#define store(b,n)      for(int i=0;i<n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
ll a[1000005],b[1000005],cnt[1000005];
int ma[100][100];

unordered_map<string,int>um;

int solve(string s, int i, int j, int istr)
{
    if(i>j)
    return 0;
    if(i==j){
        if(istr)
        return s[i]=='T';
        else
        return s[i]=='F';
    }
    string t;
    t= to_string(i);
    t.push_back(' ');
    t.append(to_string(j));
    t.push_back(' ');
    t.append(to_string(istr));
    if(um.find(t)!=um.end()){
        return um[t];
    }
    int lt,lf,rt,rf,ans=0;
    for(int k=i+1;k<=j-1;k+=2){
        lt=solve(s,i,k-1,true);
        lf=solve(s,i,k-1,false);
        rt=solve(s,k+1,j,true);
        rf=solve(s,k+1,j,false);

        if(s[k]=='&'){
            if(istr)
            ans+=(lt*rt);
            else
            ans+=(lf*rt)+(lt*rf)+(lf*rf);
        }
        else if(s[k]=='|'){
            if(istr)
            ans+=(lf*rt)+(lt*rf)+(lt*rt);
            else
            ans+=(lf*rf);
        }
        else if(s[k]=='^')
        {
            if(istr)
            ans+=(lf*rt)+(rf*lt);
            else
            ans+=(lf*rf)+(lt*rt);
        }
    }
    return  um[t]=ans;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    um.clear();
    string s;
    cin>>s;
    int n= s.length();
     cout << solve(s,0,n-1,1);
    
  return 0;
}
 
