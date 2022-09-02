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

int maxWater(int a[], int n)
{
     
//    with stack implementation
    // stack <int> st;
 
    
    // int ans = 0;
 
    
    // for(int i = 0; i < n; i++)
    // {
        
    //     while ((!st.empty()) &&
    //            (height[st.top()] < height[i]))
    //     {
            
    //         int pop_height = height[st.top()];
    //         st.pop();
 
    //         if (st.empty())
    //             break;
 
    //         int distance = i - st.top() - 1;
 
    //         int min_height = min(height[st.top()],
    //                              height[i]) -
    //                          pop_height;
 
    //         ans += distance * min_height;
    //     }
 
    //     st.push(i);
    // }
    // return ans;

//    without stack implementation
    int maxl[n],maxr[n],water[n];
    maxl[0]=a[0];
    maxr[n-1]=a[n-1];
    for(int i=1;i<n;i++)
    maxl[i]= max(a[i],maxl[i-1]);
    for(int i=n-2;i>=0;i--)
    maxr[i]=max(a[i],maxr[i+1]);
    for(int i=0;i<n;i++)
    water[i]= min(maxl[i],maxr[i])-a[i];
    int ans=0;
    for(int i=0;i<n;i++)
    ans+=water[i];

    return ans;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    int arr[] = { 0, 1, 0, 2, 1, 0,
                  1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    cout << maxWater(arr, n);
  return 0;
}
 
