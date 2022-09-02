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

int downToZero(int n) {
    
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    vector<int> step(n+1,0);
    queue<int>q;
    q.push(n);
    step[n]=1;
    while(1){
        int e= q.front();
        q.pop();
        if(e==2){
            return step[2]+1;
            break;
        }
        if(step[e-1]==0){
            step[e-1]=step[e]+1;
            q.push(e-1);
            
        }
        for(int i=2;i*i<=e;i++){
            if(e%i==0){
                int val= e/i;
                if(step[val]==0){
                    step[val]=step[e]+1;
                    q.push(val);
                }
            }
        }
    }
    return 0;
}



int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
    int n;
    cin>> n;
    cout << downToZero(n) << endl;


  return 0;
}
 
