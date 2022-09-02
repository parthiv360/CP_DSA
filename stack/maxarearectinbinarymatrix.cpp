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

#define R 4
#define C 4
int maxHist(int row[])
{
    
    stack<int> result;
 
    int top_val; 
 
    int max_area = 0; 
 
    int area = 0; 
 
    
    int i = 0;
    while (i < C) {
        
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
           
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
 
    
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}
int maxRectangle(int A[][C])
{
    
    int result = maxHist(A[0]);
 
    
    for (int i = 1; i < R; i++) {
 
        for (int j = 0; j < C; j++)
 
           
            if (A[i][j])
                A[i][j] += A[i - 1][j];
 
        
        result = max(result, maxHist(A[i]));
    }
 
    return result;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
 
    cout << "Area of maximum rectangle is "
         << maxRectangle(A);
  return 0;
}
 
