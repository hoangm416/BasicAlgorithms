//C++ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int n,k,ans=1;

int ksm(int a, int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

signed main()
{
    cin>>k>>n;
    for(int i=n-k+1;i<=n;i++) ans=ans*i%mod;
    for(int i=1;i<=k;i++) ans=ans*ksm(i,mod-2)%mod;
    cout<<ans<<endl;
    return 0;
}

