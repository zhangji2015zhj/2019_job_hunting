#include<bits/stdc++.h>

using namespace std;

int enter_move(string str);
int enter_num(char c);
int shorest(int a,int b);

int main(int argc, char const *argv[])
{
    int T=0;
    cin>>T;
   string film;
    
    for(size_t i = 1; i < T; i++)
    {
        cin>>film;
        cout<<enter_move(film)<<endl;
    }
        cin>>film;
        cout<<enter_move(film);
    
    return 0;
}


int enter_move(string str)
{
    int len=str.size();
    int pre=0;
    int next=0;
    int sum=0;
    for(size_t i = 0; i < len; i++)
    {
        pre=next;
        next=enter_num(str[i]);
        sum+=shorest(pre,next);
    }
    return sum;
}
int shorest(int a,int b)
{
    int col=abs((a%3)-(b%3));
    int row=abs((a/3)-(b/3));
    return col+row;
}

int enter_num(char c)
{
    int ret=0;
    if (c<'A') {
        ret=0;
    }    
    else 
    if (c<='C') {
        ret=1;
    }    
    else 
    if (c<='F') {
        ret=2;
    }
      else 
    if (c<='I') {
        ret=3;
    }  else 
    if (c<='L') {
        ret=4;
    }  else 
    if (c<='O') {
        ret=5;
    }  else 
    if (c<='S') {
        ret=6;
    }  else 
    if (c<='V') {
        ret=7;
    }  else 
    if (c<='Z') {
        ret=8;
    }
    
    return ret;
}
