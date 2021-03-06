// 美团在吃喝玩乐等很多方面都给大家提供了便利。最近又增加了一项新业务：小象生鲜。这是新零售超市，你既可以在线下超市门店选购生鲜食品，也可以在手机App上下单，最快30分钟就配送到家。
// 新店开张免不了大优惠。我们要在小象生鲜超市里采购n个物品，每个物品价格为ai，有一些物品可以选择八折优惠（称为特价优惠）。
// 有m种满减优惠方式，满减优惠方式只有在所有物品都不选择特价优惠时才能使用，且最多只可以选择最多一款。
// 每种满减优惠描述为(bi,ci)，即满bi减ci（当消费>=bi时优惠ci）。
// 求要买齐这n个物品（必须一单买齐），至少需要多少钱（保留两位小数）。
// 输入描述:
// 第一行，两个整数n,m。
// 接下来n行，每行一个正整数ai，以及一个0/1表示是否可以选择特价优惠（1表示可以）。
// 接下来m行，每行两个正整数bi,ci，描述一款满减优惠。

// 1 <= n,m <=10
// 1 <= ai <= 100
// 1 <= ci < bi <= 1000
// 输出描述:
// 一行一个实数，表示至少需要消耗的钱数（保留恰好两位小数

// 输入
// 2 1
// 6 1
// 10 1
// 12 2
// 输出
// 12.80

#include <iostream>
#include<vector>
#include<iomanip>
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
