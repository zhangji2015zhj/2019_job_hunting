#include<bits/stdc++.h>

using namespace std;
const double esp=1e-5;
#define dis(x1,x2,y1,y2) (sqrt(pow(x1-x2,2)+(pow(y1-y2,2))))
double x1,x2,y1,y2;
double ang(double ang1,double ang2)
{
	return dis(x2,sin((ang2+ang1)/2),y2,cos((ang2+ang1)/2))+dis(x1,sin((ang2+ang1)/2),y1,cos((ang2+ang1)/2));
}
int  main()
{
	int r ;
	cin>>r;
	
	cin>>x1>>y1>>x2>>y2;
	x1/=r;x2/=r;y1/=r;y2/=r;
	double d;
	d=dis(x1,x2,y1,y2);
	double angel1,angel2,angel;
	double x3,x4,y3,y4;
	angel1=std::atan((y1-esp)/(x1));
	angel2=std::atan((y2-esp)/(x2));

	
	while(abs(angel1-angel2)>esp){
		double distan1=ang(angel1,angel1);
		double distan2=ang(angel2,angel2);
		double distan=ang(angel1,angel2);
		if(d<distan)
			d=distan;
		if(distan1<distan2)
		{
			angel2=(angel1+angel2)/2;

		}
		
		else
		{
				angel1=(angel1+angel2)/2;
		}
		
	}
	

	cout<<r*d;
	return 0;
}

//堆排序
//整理节点time:O(lgn)
template <typename T>
void MinHeapify(T *arry, int size, int cur_e)
{
	int l_child = cur_e * 2 + 1, r_child = l_child + 1; //左右子树
	while (r_child < size)							   //子树均在范围内
	{
		if (arry[cur_e] <= arry[l_child] && arry[cur_e] <= arry[r_child]) //如果比左右子树都小，完成整理
		{
			return;
		}
		if (arry[l_child] <= arry[r_child]) //如果左边最小
		{
			swap(arry[cur_e], arry[l_child]); //把左面的提到上面
			cur_e = l_child;				   //循环时整理子树
		}
		else //否则右面最小
		{
			swap(arry[cur_e], arry[r_child]); //同理
			cur_e = r_child;
		}
		l_child = cur_e * 2 + 1;
		r_child = l_child + 1; //重新计算子树位置
	}
	if (l_child < size && arry[l_child] < arry[cur_e]) //只有左子树且子树小于自己
	{
		swap(arry[l_child], arry[cur_e]);
	}
	return;
}
//堆排序time:O(nlgn)
template <typename T>
void HeapSort(T *arry, int size)
{
	int i;
	for (i = size - 1; i >= 0; i--) //从子树开始整理树
	{
		MinHeapify(arry, size, i);
	}
	while (size > 0) //拆除树
	{
		swap(arry[size - 1], arry[0]); //将根（最小）与数组最末交换
		size--;						   //树大小减小
		MinHeapify(arry, size, 0);	 //整理树
	}
	return;
}