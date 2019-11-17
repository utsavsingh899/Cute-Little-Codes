#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m[100][100], dp[105][105], i, j, res;
    stack<int> s1;
    stack<char> s2;
    cout<<"Enter the size of the grid: ";
    cin>>n;
    cout<<"Now enter the "<<n<<"x"<<n<<" elements:\n";
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            cin>>m[i][j];
    for(i=0;i<=n;++i)
        dp[i][0]=0;
    for(j=0;j<=n;++j)
        dp[0][j]=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            dp[i][j]=max(dp[i-1][j], dp[i][j-1])+m[i][j];
    cout<<"States: \n";
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            cout<<setw(2)<<dp[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"Maximum weight: "<<dp[n][n]<<"\n";
    i=n, j=n;
    while(i!=0 && j!=0)
    {
        s1.push(m[i][j]);
        if(dp[i-1][j]>dp[i][j-1])
        {
            --i;
            s2.push('d');
        }
        else
        {
            --j;       
            s2.push('r');
        } 
    }
    s2.pop();
    cout<<"Elements is the heaviest path:\n";
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<"\n";
    cout<<"Path to be followed:\n";
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<"\n";
    return 0;
}