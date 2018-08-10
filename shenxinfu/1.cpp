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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

int hole[1010] = {0};
int num[1010] = {0};

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i=0; i<k; ++i) cin >> num[i];
    hole[0] = 1;
    hole[n + 1] = 1;
    int s;
    for (int i=0; i<k; ++i)
    {
        s = n;
        hole[num[i]] = 1;
        int temp = hole[0];
        for (int j=1; j<=n; ++j)
        {
            if (temp && hole[j + 1])
            {
                temp = hole[j];
                hole[j] = 1;
                --s;
            }
            else
            {
                temp = hole[j];
                hole[j] = 0;
            }
        }
        if (s <= 0) break;
    }
    if (s <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
