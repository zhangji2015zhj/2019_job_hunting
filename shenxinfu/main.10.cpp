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

int main(int argc, char const *argv[])
{
	int n,m;
	vector<int > a,b;
	cin>>n;
	a.resize(n);
	
	for(size_t i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	cin>>m;
	b.resize(m);

	for(size_t i = 0; i < m; i++)
	{
		cin>>b[i];
	}

	int64_t diff=0;

	
	for(size_t i = 0; i < n; i++)
	{
		diff+=pow(a[i]-b[i],2);
	}
	
	for(size_t j = 1; j < m-n; j++)
	{
		int64_t diffnew=0;
		for (size_t i = 0; i < n; i++)
		{
			diffnew += pow(a[i] - b[i+j],2);
			if(diffnew>diff)
			{
				break;
			}
		}
		diff=min(diff,diffnew);
	}
	
	

	cout<<diff;

	return 0;
}
