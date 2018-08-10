#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <iterator>

using namespace std;

//网易1
vector<int> money = {0, 3000, 12000, 25000, 35000, 55000, 80000,100000000};
vector<int> rate = {3, 10, 20, 25, 30, 35, 40};
int len=7;

int fun(int T){
    if(T<=5000)
        return 0;
        T-=5000;
    int ret=0;
    for(int i=0;i<len;i++){
        if(T<=money[i])
        {
            break;
        }
        ret+= (min(T,money[i+1])-money[i])*rate[i];
        
    }


    int r=(ret+50)/100.0;
    return r;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while(n--){
        int T;
        cin>>T;
        cout<<fun(T);
        if(n!=0)
        {
            cout<<endl;
        }
    }
    return 0;
}


