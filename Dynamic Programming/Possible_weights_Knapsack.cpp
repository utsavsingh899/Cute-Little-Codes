#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, w, s[105], i, j, sum=0;
    bool dp[1005]={false};
    cout<<"Enter the number of elements in the set: ";
    cin>>n;
    cout<<"Now enter the "<<n<<" elements:\n";
    for(i=1;i<=n;++i)
        cin>>s[i], sum+=s[i];
    dp[0]=true;
    for(i=1;i<=n;++i)
    {
        for(j=sum;j>=0;--j)
            if(dp[j])
                dp[j+s[i]]=true;
    }
    for(i=0;i<=sum;++i)
        cout<<setw(2)<<i<<"  ";
    cout<<"\n";
    for(i=0;i<=sum;++i)
        if(dp[i])
            cout<<setw(2)<<"X"<<"  ";
        else
            cout<<setw(2)<<"O"<<"  ";
    cout<<"\n";
    return 0;
}