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

int getMaxArea(int arr[], int n)
{
    
    stack<int> s;
    
    s.push(-1);
    int area = arr[0];
    int i = 0;
    
    vector<int> left_smaller(n, -1), right_smaller(n, n);
    while(i<n){
        while(!s.empty()&&s.top()!=-1&&arr[s.top()]>arr[i]){
            
            right_smaller[s.top()] = i;
            s.pop();
        }
        if(i>0&&arr[i]==arr[i-1]){
            
            left_smaller[i] = left_smaller[i-1];
        }else{
           
            left_smaller[i] = s.top();
        } 
        s.push(i);
        i++;
    }
    for(int j = 0; j<n; j++){
        
        area = max(area, arr[j]*(right_smaller[j]-left_smaller[j]-1));
    }
    return area;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   int a[7]={6,2,5,4,5,1,6};
   cout << getMaxArea(a,7) << endl;
  return 0;
}
 
