#include<bits/stdc++.h>
using namespace std;
bool SubsetSum(int s[100], int n, int target)
{
    int dp[2*target+5]={0}, i, j;
    dp[0]=1;
    for(i=1;i<=n;++i)
    {
        for(j=2*target;j>=0;--j)
            if(dp[j]!=0)
                dp[j+s[i]]++;
    }
    cout<<"Target sum and number  of ways to get it:\n";
    cout<<setw(10)<<left<<"Target:";
    for(i=0;i<=2*target;++i)
        cout<<setw(2)<<i<<"  ";
    cout<<"\n";
    cout<<setw(10)<<left<<"Ways:";
    for(i=0;i<=2*target;++i)
        cout<<setw(2)<<dp[i]<<"  ";
    cout<<"\n";
    if(dp[target]!=0)
        return true;
    return false;
}
bool EqualPartition(int s[100], int n)
{
    int sum=0, i;
    for(i=1;i<=n;++i)
        sum+=s[i];
    if(sum&1)
        return false;
    return SubsetSum(s, n, sum/2);
}
int main()
{
    int n, s[100], i;
    cout<<"Enter the number of elements in the set: ";
    cin>>n;
    cout<<"Now enter the "<<n<<" elements:\n";
    for(i=1;i<=n;++i)
        cin>>s[i];
    s[0]=0;
    if(EqualPartition(s, n))
        cout<<"Equal partitioning possible\n";
    else
        cout<<"Equal partitioning not possible\n";
    return 0;
}