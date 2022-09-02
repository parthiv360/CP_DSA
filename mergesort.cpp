#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define maxn 1000005
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
#define cin(a,n)        for(ll i=1;i<=n;i++)cin>>a[i];
#define store(b,n)      for(int i=0;i<n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)

ll a[maxn],b[maxn],dp[maxn];
int ma[100][100];

void merge(int a[],int p, int q, int r){
    int n1=q-p+1;
    int n2= r-q;
    int l1[n1],l2[n2];
    for(int i=0;i<n1;i++)
    l1[i]=a[p+i];
    for(int j=0;j<n2;j++)
    l2[j]=a[q+j+1];
    int i=0,j=0,k=p;
    while(i<n1 && j<n2){
        if(l1[i]<=l2[j]){
            a[k]=l1[i];
            i++;
        }
        else{
            a[k]=l2[i];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=l1[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k]=l2[j];
        k++;
        j++;
    }
}
void merge_sort(int a[], int l, int r){
    if(l>=r)
    return;
    int mid= l+(r-l)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge(a,l,mid,r);
}

int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   
   int a[6]={2,5,7,3,1,9};
   int n=6;
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout << a[i] << " ";
  return 0;
}
 
