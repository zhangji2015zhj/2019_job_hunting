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

vector<long long int> apple;

void fun(long long int s)
{
    

    return;
}
int main(int argc, char const *argv[])
{
    int m, n;

    cin >> n;
    // vector<int> time_cost(m+1);
    apple.resize(n + 1);
    apple[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> apple[i];
        apple[i] += apple[i - 1];
    }
    cin >> m;

    while (m--)
    {
        /* code */
        long long int apple_now;
        cin >> apple_now;
       cout<<lower_bound(apple.begin(), apple.end(), apple_now) - apple.begin();
        // fun(apple_now);
        if (n != 0)
        {
            cout << endl;
        }
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
