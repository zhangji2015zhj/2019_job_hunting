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

struct plan
{
    int x;
    int y;
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    n++;
    vector<vector<int>> cost(n + 1, vector<int>(m + 1));
    vector<plan> pla(m + 1);
    for(int i=1;i<=m;i++){
        cin>>pla[i].x>>pla[i].y;
    }
    for(int x=1;x<=n;x++){
        cost[x][0]=x*k;
        for(int y=1;y<=m;y++){

            if(x>=pla[y].y){
                cost[x][y]=min(cost[x][y-1],cost[x-pla[y].y][y]+pla[y].x);
            }else{
                cost[x][y]=min(cost[x][y-1],0+pla[y].x);
            }
        }
    }
    cout<<cost[n][m];

}
