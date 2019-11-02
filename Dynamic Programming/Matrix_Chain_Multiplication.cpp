#include<bits/stdc++.h>
using namespace std;
int m[100][100], s[100][100];
void MCO(int p[100], int n)
{
    int i, j, k, l, temp;
    for(i=1;i<=n;++i)
        m[i][i]=0;
    for(l=2;l<=n;++l)
    {
        for(i=1;i<=n-l+1;++i)
        {
            j=i+l-1;
            m[i][j]=100000;
            for(k=i;k<=j-1;++k)
            {
                temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp<m[i][j])
                {
                    m[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
}
void PrintSeq(int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        PrintSeq(i, s[i][j]);
        PrintSeq(s[i][j]+1, j);
        cout<<")";
    }
}
int main()
{
    int n, p[100], i, j;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>p[i];
    MCO(p, n-1);
    cout<<"Minimum Cost: "<<m[1][n-1]<<"\n";
    cout<<"Sequence: ";
    PrintSeq(1, n-1);
    cout<<"\n\n";
    for(i=1;i<n;++i)
    {
        for(j=1;j<n;++j)
            cout<<setw(5)<<m[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"\n\n";
    for(i=1;i<n-1;++i)
    {
        for(j=2;j<n;++j)
            cout<<setw(5)<<s[i][j]<<"  ";
        cout<<"\n";
    }
    return 0;
}