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


void solve(stack<int> &st, int k){
    if(k==1){
    st.pop();
    return ;
    }
    int t= st.top();
    st.pop();
    solve(st,k-1);
    st.push(t);
    return;
}
stack<int> middel(stack<int> st,int size){
    if(size==0)
    return st;
    int k= size/2+1;
    solve(st,k);
    return st;

}
int main(){
    cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    stack<int> q= middel(st,5);
    while(q.size()>0){
        cout << q.top() << " ";
        q.pop();
    }
   return 0;
}