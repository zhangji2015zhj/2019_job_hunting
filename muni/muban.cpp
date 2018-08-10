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



/*  字符串分割   */
struct split
{
	enum empties_t
	{
		empties_ok,
		no_empties
	};
};

//返回值《==返回值（容器list vector），待分割的字符串，分割字符，子串是否允许为空
template <typename Container>
Container &split(
	Container &result,
	const typename Container::value_type &s,
	typename Container::value_type::value_type del,
	split::empties_t empties = split::empties_ok)
{
	result.clear();
	std::istringstream ss(s);
	while (!ss.eof())
	{
		typename Container::value_type field;
		getline(ss, field, del);
		if ((empties == split::no_empties) && field.empty())
			continue;
		result.push_back(field);
	}
	return result;
}
/*  字符串分割   */

/*输出 行 不换行*/
template <typename Container_iter> 
void Container_print(Container_iter start, Container_iter last, char del=' ')
{
	while(start!=prev(last))
	{
		cout<<*start++<<del;
	};
	cout<<*start;
}

/*
比较函数递增
bool  comp(listnode* a, listnode* b)
{
	if(a->t<  b->t) //递增
    return true;
    else return false;
}
*/

//最大公约数
int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  辗转相除法
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}


//最小公倍数
int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  辗转相除法
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}

/*
    |Dijkstra算法|
    |适用于边权为正的有向图或者无向图|
    |求从单个源点出发，到所有节点的最短路|
    |优化版：时间复杂度 O(elbn)|
    |16/11/05ztx, thanks to chaixiaojun|
*/

struct node {  
    int v, len;  
    node(int v = 0, int len = 0) :v(v), len(len) {}  
    bool operator < (const node &a)const {  //  距离从小到大排序  
        return len > a.len;  
    }  
};  

vector<node>G[maxn];  
bool vis[maxn];  
int dis[maxn];

void init() {  
    for (int i = 0; i<maxn; i++) {  
        G[i].clear();  
        vis[i] = false;  
        dis[i] = INF;  
    }  
}  
int dijkstra(int s, int e) {  
    priority_queue<node>Q;  
    Q.push(node(s, 0)); //  加入队列并排序  
    dis[s] = 0;  
    while (!Q.empty()) {  
        node now = Q.top();     //  取出当前最小的  
        Q.pop();  
        int v = now.v;  
        if (vis[v]) continue;   //  如果标记过了, 直接continue  
        vis[v] = true;  
        for (int i = 0; i<G[v].size(); i++) {   //  更新  
            int v2 = G[v][i].v;  
            int len = G[v][i].len;  
            if (!vis[v2] && dis[v2] > dis[v] + len) {  
                dis[v2] = dis[v] + len;  
                Q.push(node(v2, dis[v2]));  
            }  
        }  
    }  
    return dis[e];  
} 

/*
    |SPFA算法|
    |队列优化|
    |可处理负环|
*/

vector<node> G[maxn];
bool inqueue[maxn];
int dist[maxn];

void Init()  
{  
    for(int i = 0 ; i < maxn ; ++i){  
        G[i].clear();  
        dist[i] = INF;  
    }  
}  
int SPFA(int s,int e)  
{  
    int v1,v2,weight;  
    queue<int> Q;  
    memset(inqueue,false,sizeof(inqueue)); // 标记是否在队列中  
    memset(cnt,0,sizeof(cnt)); // 加入队列的次数  
    dist[s] = 0;  
    Q.push(s); // 起点加入队列  
    inqueue[s] = true; // 标记  
    while(!Q.empty()){  
        v1 = Q.front();  
        Q.pop();  
        inqueue[v1] = false; // 取消标记  
        for(int i = 0 ; i < G[v1].size() ; ++i){ // 搜索v1的链表  
            v2 = G[v1][i].vex;  
            weight = G[v1][i].weight;  
            if(dist[v2] > dist[v1] + weight){ // 松弛操作  
                dist[v2] = dist[v1] + weight;  
                if(inqueue[v2] == false){  // 再次加入队列  
                    inqueue[v2] = true;  
                    //cnt[v2]++;  // 判负环  
                    //if(cnt[v2] > n) return -1;  
                    Q.push(v2);  
                } } }  
    }  
    return dist[e];  
}


/*
    |求解最大匹配问题|
    |递归实现|
    |16/11/05ztx|
*/

vector<int>G[maxn];  
bool inpath[maxn];  //  标记  
int match[maxn];    //  记录匹配对象  
void init()  
{  
    memset(match, -1, sizeof(match));  
    for (int i = 0; i < maxn; ++i) {  
        G[i].clear();  
    }  
}  
bool findpath(int k) {  
    for (int i = 0; i < G[k].size(); ++i) {  
        int v = G[k][i];  
        if (!inpath[v]) {  
            inpath[v] = true;  
            if (match[v] == -1 || findpath(match[v])) { // 递归  
                match[v] = k; // 即匹配对象是“k妹子”的  
                return true;  
            }  
        }  
    }  
    return false;  
}  

void hungary() {  
    int cnt = 0;  
    for (int i = 1; i <= m; i++) {  // m为需要匹配的“妹子”数  
        memset(inpath, false, sizeof(inpath)); // 每次都要初始化  
        if (findpath(i)) cnt++;  
    }  
    cout << cnt << endl;  
}


/*
    |求最长公共子序列|
    |递推形式|
    |16/11/05ztx|
*/

void solve() {  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < m; ++j) {  
            if (s1[i] == s2[j]) {  
                dp[i + 1][j + 1] = dp[i][j] + 1;  
            }else {  
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);  
            } } }
}  


/*
    |16/11/06ztx|
	字典树
*/

struct Trie{  
    int cnt;  
    Trie *next[maxn];  
    Trie(){  
        cnt = 0;  
        memset(next,0,sizeof(next));  
    }  
};  

Trie *root;  

void Insert(char *word)  {  
    Trie *tem = root;  
    while(*word != '\0')  {  
        int x = *word - 'a';  
        if(tem->next[x] == NULL)  
            tem->next[x] = new Trie;  
        tem = tem->next[x];  
        tem->cnt++;  
        word++;  
    }  
}  

int Search(char *word)  {  
    Trie *tem = root;  
    for(int i=0;word[i]!='\0';i++)  {  
        int x = word[i]-'a';  
        if(tem->next[x] == NULL)  
            return 0;  
        tem = tem->next[x];  
    }  
    return tem->cnt;  
}  

void Delete(char *word,int t) {  
    Trie *tem = root;  
    for(int i=0;word[i]!='\0';i++)  {  
        int x = word[i]-'a';  
        tem = tem->next[x];  
        (tem->cnt)-=t;  
    }  
    for(int i=0;i<maxn;i++)  
        tem->next[i] = NULL;  
} 

int main()
{
	string sentence = "and i dsf.. .. good";
	list<string> vec;
	split(vec, sentence, '.', split::no_empties);

	std::istringstream stream("1 2 3 4 5");
	std::copy(
		std::istream_iterator<int>(stream),
		std::istream_iterator<int>(),
		std::ostream_iterator<int>(std::cout, " "));
	Container_print(sentence.begin(),sentence.end());
	Container_print(vec.begin(),vec.end());
}