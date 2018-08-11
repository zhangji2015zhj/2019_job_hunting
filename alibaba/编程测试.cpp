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
int c=0;
multimap<int,int> depend;

   vector<int> time_cost; 

int fun(int s )
{
    int ret=0;
    auto m=depend.find(s);
    int len=depend.count(s);
    ret+=time_cost[s];
    int retn=0;
    for(size_t i = 0; i < len; i++,m++)
    {
        retn=max(retn,fun(m->second));
    }
    if(len==0){
        c++;
    }
    ret+=retn;
    

    return ret;
}
int main(int argc, char const *argv[])
{
   int m,n;

    cin >> m>>n;
    // vector<int> time_cost(m+1); 
    time_cost.resize(m+1);
    for(int i=1;i<=m;i++){
        cin>>time_cost[i];
    }
  
    vector<bool> start(m+1,false),end(m+1,false);
    
    while(n--){
        /* code */
        int first ,sec;
        cin>>first>>sec;
        // depend[first]=sec;
        depend.insert(make_pair(first,sec));
        start[first]=true;
        end[sec]=true;

    }
    
    for(size_t i = 1; i <= m; i++)
    {
        if(start[i]==true&&end[i]==false){}
        else{
            start[i]=false;
        }
    }
    int max_cost=0;
    for(size_t i = 1; i <= m; i++)
    {
        if(start[i]==true){
           max_cost=max(fun(i),max_cost);
        }
    }
    cout<<c<<"  "<<max_cost;
    

    // while (n--)
    // {
    //     string T;
    //     cin >> T;
    //     if (fun(T))
    //     {
    //         cout << "yes";
    //     }
    //     else
    //     {
    //         cout << "no";
    //     }
    //     if (n != 0)
    //     {
    //         cout << endl;
    //     }
    // }
    return 0;
}
