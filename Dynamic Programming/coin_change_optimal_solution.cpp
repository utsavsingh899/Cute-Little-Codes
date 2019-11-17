#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define hell INT_MAX
bool done[500];
ll val[500], first[500], nos[500];
void initialise(ll s)
{
    for(ll i=0;i<=s;++i)
    {
        done[i]=false;
        val[i]=0;
        first[i]=-1;
        nos[i]=0;
    }
}
void Solution(vector<ll> c, ll s)
{
    nos[0]=1;
    for(ll i=1;i<=s;++i)
    {
        val[i]=hell;
        for(ll t: c)
        {
            if(i-t>=0)
            {
                if(val[i]>val[i-t]+1)
                {
                    val[i]=val[i-t]+1;
                    first[i]=t;
                }
                nos[i]+=nos[i-t];
            }
        }
    }
}
void PrintSolution(ll s)
{
    while(s>0)
    {
        cout<<first[s]<<" ";
        s-=first[s];
    }
}
int main()
{
    ll s, i, n, x;
    vector<ll> c;
    cout<<"Enter the target sum: ";
    cin>>s;
    cout<<"Enter the no. of types of coin: ";
    cin>>n;
    cout<<"Now enter the "<<n<<" coin values:\n";
    for(i=0;i<n;++i)
    {
        cin>>x;
        c.push_back(x);
    }
    initialise(s);
    Solution(c, s);
    cout<<"Total no. of possible solutions are: "<<nos[s]<<"\n";
    cout<<"Minimum coins to be used are: "<<val[s]<<"\n";
    cout<<"Coins selected are: \n";
    PrintSolution(s);
    cout<<"\n";
    return 0;
}