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

map<string, string> maps;
vector<string> tobefind;

int fun(bool endl__)
{

    int n, m;
    maps.clear();
    cin >> n;
    while (n--)
    {
        string num, where;
        cin >> num >> where;
        auto p = num.find('x');
        if (p != string::npos)
        {
            num.erase(p, num.size() - p);
        }
        maps[num] = where;
    }
    cin >> m;
    while (m--)
    {
        string num;
        cin >> num;
        bool f = false;
        // for (auto s : maps)
        // {
        //     if (num.find(s.first) != string::npos)
        //     {
        //         cout << s.second;
        //         f = true;
        //         break;
        //     }
        // }
        int len = num.size();
        int i;
        for (i = 1; i <= len; i++)
        {

            if (maps.count(num.substr(0, i)) == 1)
            {
                cout << maps[num.substr(0, i)];
                f = true;
                break;
            }
        }
        if (f == false)
            cout << "unknown";
        if (m == 0 && endl__ == false)
        {
            ;
        }
        else
        {
            cout << endl;
        }
    }

    return true;
}
int main(int argc, char const *argv[])
{
    int T, n;
    cin >> T;
    while (T--)
    {
        bool flag = true;
        if (T == 0)
        {
            flag = false;
        }
        fun(flag);
    }

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
