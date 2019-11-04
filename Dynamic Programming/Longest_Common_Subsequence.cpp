#include<bits/stdc++.h>
using namespace std;
int l[505][505];
string lcs="";
int Length_of_LCS(string x, string y)
{
    int i, j, m, n;
    m=x.length();
    n=y.length();
    for(i=0;i<m;++i)
        for(j=0;j<n;++j)
            l[i][j]=0;
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            if(x[i]==y[j])
            {
                if(i==0 || j==0)
                    l[i][j]=1;
                else
                    l[i][j]=l[i-1][j-1]+1;
            }
            else if(l[i-1][j]>=l[i][j-1])
            {
                if(i==0)
                    l[i][j]=0;
                else
                    l[i][j]=l[i-1][j];
            }
            else
            {
                if(j==0)
                    l[i][j]=0;
                else
                    l[i][j]=l[i][j-1];
            }
        }
    }
    cout<<"Length States:\n";
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
            cout<<l[i][j]<<"  ";
        cout<<"\n";
    }
    return l[m-1][n-1];
}
void Find_LCS(string x, string y)
{
    int i=x.length();
    int j=y.length();
    while(i>=0 && j>=0)
    {
        if(x[i]==y[j])
        {
            lcs=x[i]+lcs;
            --i;
            --j;
        }
        else if(l[i-1][j]>=l[i][j-1])
            --i;
        else
            --j;
    }
}
int main()
{
    int lcs_length;
    string x, y;
    cout<<"Input first string: ";
    cin>>x;
    cout<<"Input second string: ";
    cin>>y;
    lcs_length=Length_of_LCS(x, y);
    Find_LCS(x, y);
    cout<<"Length of longest common subsequence: "<<lcs_length<<"\n";
    cout<<"Longest common subsequence: "<<lcs;
}
