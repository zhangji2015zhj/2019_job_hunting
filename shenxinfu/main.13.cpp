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

vector<char> specify = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '[', ']', '{', '}', ',', '.', '<', '>', '/', '?'};

vector<string> other = {"password", "admin", "qwerty", "hello", "iloveyou", "112233"};
bool fun(string str)
{
    if (str.length() < 8)
        return false;
    bool ret, n_, big_, small_, specify_, num_, char_, other_;
    ret = n_ = big_ = small_ = specify_ = num_ = char_ = other_ = false;


    for (auto s : str)
    {
        if (s <= 'Z' && s >= 'A')
            big_ = true;
        if (s <= 'z' && s >= 'a')
            small_ = true;
        if (s <= '9' && s >= '0')
            n_ = true;
        if (find(specify.begin(), specify.end(), s) != specify.end())
        {
            specify_ = true;
        }
    }
    if (big_ && small_ && n_ && specify_)
        ;
    else
    {
        return false;
    }

    int len = str.length();

    for (size_t i = 1; i < len - 1; i++)
    {
        if (str[i] >= '0' && str[i] <= '9' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
        {
            if (str[i] == (str[i - 1] + str[i + 1]) / 2)
            {
                num_ = true;
            }
        }
        if (str[i] >= 'a' && str[i] <= 'z' && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
        {
            if (str[i] == (str[i - 1] + str[i + 1]) / 2 && (str[i] - str[i - 1]) == 1)
            {
                char_ = true;
            }
        }
        if (str[i] >= 'A' && str[i] <= 'Z' && (str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
        {
            if (str[i] == (str[i - 1] + str[i + 1]) / 2 && (str[i] - str[i - 1]) == 1)
            {
                char_ = true;
            }
        }
    }
    if (num_ || char_)
        return false;

    for(auto s:other)
    {
        if(str.find(s)!=-1)
        {return false;}

    }
    return true;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        string T;
        cin >> T;
        if (fun(T))
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
        if (n != 0)
        {
            cout << endl;
        }
    }
    return 0;
}
