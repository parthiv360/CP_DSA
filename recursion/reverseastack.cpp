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


stack<char> st;
 

string ns;
 

char insert_at_bottom(char x)
{
 
    if(st.size() == 0)
    st.push(x);
 
    else
    {
         
        
             
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
 
        
        st.push(a);
    }
}
 

char reverse()
{
    if(st.size()>0)
    {
         
        
        char x = st.top();
        st.pop();
        reverse();
         
        
        insert_at_bottom(x);
    }
}
 
// Driver Code
int main()
{
     
    
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
     
    cout<<"Original Stack"<<endl;
     
    
    cout<<"1"<<" "<<"2"<<" "
        <<"3"<<" "<<"4"
        <<endl;
     
    
    reverse();
    cout<<"Reversed Stack"
        <<endl;
     
    
    while(!st.empty())
    {
        char p=st.top();
        st.pop();
        ns+=p;
    }
     
    
    cout<<ns[3]<<" "<<ns[2]<<" "
        <<ns[1]<<" "<<ns[0]<<endl;
    return 0;
}