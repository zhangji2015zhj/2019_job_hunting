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

void fun();
int n;
map<int, bitset<1003>> start;
vector<vector<int>> start_num(1003, vector<int>(1003));
int main()
{
    malloc();
    cin >> n;
    int x, y;
    while (n--)
    {
        cin >> x >> y;
        start[x][y] = 1;
    }

    int m;
    cin >> m;
    if (m < 100)
        while (m--)
        {
            fun();
            if (m)
            {
                cout << endl;
            }
        }
    else
    {
        for (int x = 1; x <= 1000; x++)
        {
            int x_sum = 0;
            for (int y = 1; y <= 1000; y++)
            {
             x_sum += start[x][y];
                start_num[x][y] = start_num[x - 1][y] + x_sum;
            }
        }
        while (m--)
        {
            fun();
            if (m)
            {
                cout << endl;
            }
        }
    }
}

void fun()
{
    int a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int start_count = 0;
    for (int x = a1; x <= a2; x++)
        for (int y = b1; y <= b2; y++)
        {
            if (start[x][y] == 1)
            {
                start_count++;
            }
        }
    cout << start_count;
}