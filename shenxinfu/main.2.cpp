
#include <bits/stdc++.h>

using namespace std;

struct treenode
{
    treenode* f=nullptr;
    int value;
    int key;
    treenode *l = nullptr;
    treenode *r = nullptr;
};

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    vector<int> score;
    score.resize(n + 1);
    int tmp;
    int all = 0;
    score[0] = 0;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> score[i];
        all += score[i];
    }
    list<treenode *> treelist;
    treenode *head = new treenode;
    head->value = 0;
    head->key = 0;
    treelist.push_back(head);
    head->f=nullptr;
    while (!treelist.empty())
    {
        auto var = treelist.front();
        int value = score[var->key + 1];

        if (var->value + value <= 100)
        {
            var->l = new treenode;
            var->l->value = var->value + value;
            var->l->key = var->key + 1;
            var->l->f=var;
            treelist.push_back(var->l);

            if (var->value + value == 100)
            {
                break;
            }
        }
        else
        {
            var->l = nullptr;
        }

        var->r = new treenode;
        var->r->value = var->value;
        var->r->key = var->key + 1;
        var->r->f=var;

        treelist.push_back(var->r);

        treelist.pop_front();
    }

    treenode *k=treelist.front();
    treelist.clear();
    list<int> key;
    
    while (k->f!=head)
    {
        
        if(k->value!=k->f->value)
        {
            key.push_front(k->key);
        }
        k=k->f;
    }
    int ret_n=key.size();
    cout<<ret_n<<endl;
    auto v=key.begin();
    for(size_t i = 1; i < ret_n; i++)
    {
        cout<<*v++<<endl;
    }cout<<*v++;
    



    treelist.clear();
    treelist.push_back(head);
    while (!treelist.empty())
    {
        auto var = treelist.front();
        treelist.pop_front();
        treelist.push_back(var->l);
        treelist.push_back(var->r);
        delete var;
    }

    return 0;
}

void printftree(treenode * h, treenode *k)
{

}
