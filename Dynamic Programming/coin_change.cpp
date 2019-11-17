#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll count(ll c[], ll m, ll n ) 
{ 
    ll t[n+1]={0}, i, j;
    t[0] = 1;
    for(i=0; i<m; i++) 
        for(j=c[i]; j<=n; j++) 
            t[j] += t[j-c[i]]; 

    return t[n]; 
} 
int main()
{
    ll n, m, i, c[55], res;
    cin>>n>>m;
    for(i=0;i<m;++i)
        cin>>c[i];
    res=count(c, m, n);
    cout<<res<<"\n";
}