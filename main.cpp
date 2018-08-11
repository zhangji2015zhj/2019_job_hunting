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

struct ta
{
    int high;
    int high_bak;
    int num;
};

vector<ta> apple;
int lowfun(int k);
int uppfun(int k);
//比较函数递增
bool comp(ta &a, ta &b)
{
    if (a.high < b.high) //递增
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    int n, k;

    cin >> n >> k;
    // vector<int> time_cost(m+1);
    apple.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> apple[i].high;
        apple[i].high_bak = apple[i].high;
        apple[i].num = i + 1;
    }
    sort(apple.begin(), apple.end(), comp);

    //lower_bound(apple.begin(), apple.end(), apple_now) - apple.begin();

    int max_ind, min_ind;
    int k_bak = k;
    string ret;
    max_ind = uppfun(k);
    min_ind = lowfun(k);
    // cout<< max_ind<<endl;
    // cout<<min_ind<<endl;

    int s = 0;
    int e = n - 1;
    int op = 0;

    // while (true)
    // {
    //     if (s > min_ind || e < max_ind)
    //     {
    //         break;
    //     }
    //     if(s>=e)
    //     break;

    //     // int low_change = apple[min_ind].high_bak-apple[s].high;
    //     // int up_change = apple[e].high - apple[max_ind].high_bak;
    //     // int change = min(low_change, up_change);
    //     // op += change;
    //     // apple[s].high += change;
    //     // apple[e].high -= change;
    //    int change =1;

    //     for (size_t i = 0; i < change; i++)
    //     {
    //         ret += "\n" + to_string(apple[e].num) + " " + to_string(apple[s].num);
    //     }

    //     if (apple[s].high - apple[min_ind].high_bak == 0)
    //     {
    //         s++;
    //     }
    //     if (apple[e].high - apple[max_ind].high_bak)
    //     {
    //         e--;
    //     }
    // }

    while (true)
    {

        max_ind = lower_bound(apple.begin(), apple.end(), apple[n - 1]) - apple.begin();
        min_ind = upper_bound(apple.begin(), apple.end(), apple[0]) - apple.begin();
        if (max_ind <= min_ind)
        {
            break;
        }

        if (k < max(n - max_ind, min_ind + 1))
        {
            break;
        }
         int change = min(n - max_ind, min_ind + 1);

        // int change = 1;

        for (auto i = max_ind + apple.begin(), j = min_ind + apple.begin(); change--; j--, i++)
        {
            i->high--;
            j->high++;
            ret += "\n" + to_string(i->num) + " " + to_string(j->num);
            op++;
        }
    }

   // cout << int(apple[n - 1].high - apple[0].high) << " " << op << ret;

    return 0;
}

int lowfun(int k)
{
    int count = apple.size();
    int sum = 0;
    int i;
    for (i = 0; i < count; i++)
    {
        /* code */
        sum += apple[i].high;
        if ((i + 1) * apple[i].high_bak > k + sum)
        {
            break;
        }
    }
    return i;
}

int uppfun(int k)
{
    const int count = apple.size();
    int sum = 0;
    int i;
    for (i = count - 1; i > 0; i--)
    {
        /* code */
        sum += apple[i].high;
        if ((i + 1) * apple[count - 1].high_bak > k + sum)
        {
            break;
        }
    }
    return i;
}