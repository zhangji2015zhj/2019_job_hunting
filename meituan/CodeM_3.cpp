#include<array>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

typedef  double P;

const int len=16;
int main(int argc, char const *argv[])
{
    array<array<P,len>,len> pij;
    
    for(size_t i = 0; i < len; i++)
    {
       
       for(size_t j = 0; j < len; j++)
       {
           cin>>pij[i][j];
       }       
    }

    int lun=floor(log2(len));

    

    array<P,len> pold,pnew;
    
    for(size_t i = 0; i < len; i++)
    {
       pold[i]=1;
       pnew[i]=1;
    }
    
    
    for(size_t l = 0; l < lun; l++)
    {
        for(size_t k=0;k<len;k++)
        {
            pold[k]=pnew[k];
            pnew[k]=0;
        }
        size_t steplen=pow(2,l);
        for(size_t is=0;is<len;is+=(steplen*2))
        {
            size_t js=is+steplen;
            size_t ie=js-1;
            size_t je=ie+steplen;

            for(size_t i=is;i<=ie;i++)
            {
                for(size_t j=js;j<=je;j++)
                {
                    pnew[i]+=pold[i]*pold[j]*pij[i][j];
                    pnew[j]+=pold[i]*pold[j]*pij[j][i];
                }
            }

        }
    }
    
    
    for(size_t i = 0; i < len-1; i++)
    {
        cout<<fixed<<setprecision(10)<<pnew[i]<<' ';
    }
    cout<<pnew[len-1];
    
    return 0;
}
