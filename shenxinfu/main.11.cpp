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

/*输出 行 不换行*/
template <typename Container_iter>
inline void Container_print(Container_iter start, Container_iter last, char del = ' ')
{
	while (start != prev(last))
	{
		//cout << *start++ << del;
		printf("%d%c",*start++,del);
	};
	//cout << *start;
		printf("%d",*start);

}

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //int ret=0;
        if(rotateArray.empty())
        {
            return 0;
        }
        vector<int>::iterator  s,t,mid;
        s=rotateArray.begin();
        t=rotateArray.end()-1;
        
       
        while(*s>=*t)
        {
            if(s>=t-1)
                return *t;
            mid=s+distance(s,t)/2;
            if(*s==*t==*mid)
            {
                for(mid=s+1;mid<=t&&*s==*mid;s=mid,mid++);
                return *mid;                
            }
            
            if(*s<=*mid){
                s=mid;
            }
            if(*mid<=*t)
            {
                t=mid;                
            }       
        }
        return *s;
    }
};
int main(int argc, char const *argv[])
{
	class Solution s;
	vector<int>  arra={6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335};
	s.minNumberInRotateArray(arra);

	return 0;
}
