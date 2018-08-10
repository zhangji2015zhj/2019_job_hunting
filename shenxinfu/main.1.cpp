
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{

    int n;
    cin>>n;
    vector<int> list_ves;
    map<int,bool> ves_map;

    int tmp;
    while(n--)
    {
        cin>>tmp;



        if(ves_map.count(tmp)==0)
        {
            list_ves.push_back(tmp);
            ves_map.insert({tmp,true});
            if(ves_map.size()>=10)
            {
                break;
            }
        }
    }
    int ret_n=ves_map.size();
    cout<<ret_n<<endl;
    auto iter=list_ves.begin();
    for(size_t i = 1; i < ret_n; i++)
    {
        cout<<*iter++<<endl;
    }
    cout<<*iter;
    return 0;
}
