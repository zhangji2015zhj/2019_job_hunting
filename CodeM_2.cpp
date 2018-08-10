// 
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> socre;
    socre.resize(n+1);
    for(size_t i=1;i<=n;i++)
    {
        cin>>socre[i];
    }
    for(size_t i=0;i<m;i++)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='Q')
        {
            if(a>b)
            {
                a+=b;
                b=a-b;
                a-=b;
            }
            int max=socre[b];
            for(size_t i=a;i<b;i++)
            {
                if(socre[i]>max)
                {
                    max=socre[i];
                }
            }
            cout<<max<<flush<<endl;
        }
        if(c=='U')
        {
            socre[a]=b;
        }
    }
    return 0;
}