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
vector<int> m_pow = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
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
inline int64_t getsum(int r,int num)
{
	if(num==0||r==0)
	return 0;
	int64_t ret=0;
	size_t i;
	r=min(r,num);
	for( i = 1; i <= r&&i*i<=num
	; i++)
	{
		ret+=(num/i);
	}

	for (int k = num / i; k >= num / r; k--)
	{
		int cnt = min(r, num / k) - num / (k + 1);
		ret += k * cnt;
	}
	return ret;
}

inline void sumall(int num,vector<int64_t>& sum)
{
	
	for(size_t i = 1; i < 10; i++)
	{
		for(size_t j=0;j< 9;j++)
		{
			if((i*m_pow[j])>num)
			{
				break;
			}else{
				sum[i]+=getsum(((i+1)*m_pow[j]-1),num)-getsum(i*m_pow[j]-1,num);
			}
		}

	}
	
}

int main(int argc, char const *argv[])
{
	int l, r;
	cin >> l >> r;
	vector<int64_t> sum,a,b;
	sum.resize(10);
	a.resize(10);
	b.resize(10);
	sumall(l-1,a);
	sumall(r,b);
	
	for(size_t i =0;i<10;i++)
	{
		sum[i]=b[i]-a[i];
	}

	Container_print(sum.begin() + 1, sum.end(), '\n');

	return 0;
}
