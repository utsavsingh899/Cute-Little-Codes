#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, w[1005], p[1005], i, j, W, res, k[1005][1005], s[1005];
    cout<<"Enter the capacity of knapsack: ";
    cin>>W;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Now enter the weights and profits of the "<<n<<" items: \n";
    for(i=1;i<=n;++i)
    {
        cin>>w[i];
        cin>>p[i];
    }
    for(i=0;i<=n;++i)
    {
        for(j=0;j<=W;++j)
        {
            if(i==0 || j==0)
                k[i][j]=0;
            else if(w[i]<=j)
                k[i][j]=max(k[i-1][j], k[i-1][j-w[i]]+p[i]);
            else
                k[i][j]=k[i-1][j];
        }
    }
    cout<<"State Table: \n";
    for(i=0;i<=n;++i)
    {
        for(j=0;j<=W;++j)
            cout<<setw(2)<<k[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"Maximum Profit: "<<k[n][W]<<"\n";
    i=n;
    j=W;
    while(i>0 && j>0)
    {
        if(k[i][j]!=k[i-1][j])
        {
            j-=w[i];
            s[i--]=1;
        }
        else
            s[i--]=0;
    }
    cout<<"Items present in the knapsack are: \n";
    for(i=1;i<=n;++i)
        cout<<s[i]<<" ";
    cout<<"\n";
}