
#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<int> ai,aibool,bi,ci;
    int sum=0;
    int sumdeczhe=0;

    ai.resize(n);
    aibool.resize(n);
    for(size_t i = 0; i < n; i++)
    {
        cin>>ai[i]>>aibool[i];
        sum+=ai[i];
        
        if (aibool[i]==1) {
            sumdeczhe+=ai[i];
        }        
    }

    bi.resize(m);
    ci.resize(m);
    
    int manjian=0;
    for(size_t i = 0; i < m; i++)
    {
        cin>>bi[i]>>ci[i];
        if(sum>=bi[i]&&ci[i]>manjian)
        {
            manjian=ci[i];
        }
    }
    float solution1,solution2;
    solution1=sum-0.2*sumdeczhe;
    solution2=sum-manjian;
    if(solution1<solution2)
    {
        cout<<fixed<<setprecision(2)<<solution1;
    }
    else{
        cout<<fixed<< setprecision(2)<<solution2;
    }
    
    
    return 0;
}
