#include<bits/stdc++.h>
using namespace std;
struct item
{
    int mass, val;
}a[101];
bool my_sort(struct item a1, struct item a2)
{
    double f1=(double)a1.val/a1.mass;
    double f2=(double)a2.val/a2.mass;
    return f1>f2;
}
int main()
{
    int t, N, i;
    double s, W;
    cin>>t;
    while(t--)
    {
        cin>>N>>W;
        for(i=0;i<N;++i)
            cin>>a[i].val>>a[i].mass;
        sort(a, a+N, my_sort);
        for(i=0;i<N;++i)
            cout<<a[i].val<<" "<<a[i].mass<<endl;
        cout<<endl;
        i=0;
        s=0;
        while(W!=0 && i<N)
        {
            if(a[i].mass>W)
            {
                s+=(double)a[i].val*W/a[i].mass;
                W=0;
            }
            else
            {
                s+=(double)a[i].val;
                W-=a[i].mass;
            }
            ++i;
        }
        cout<<fixed<<setprecision(2)<<s<<endl;
    }
    return 0;
}
