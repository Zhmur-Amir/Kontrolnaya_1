#include "klass.h"

void Autotest(void)
{
    double m=0;
    CComplexNum n[LENGTH], f;
    cout<<endl;
    cout<<"AUTOTEST STARTED"<<endl;
    for(int i=0; i<LENGTH; i++)
    {
        CComplexNum c(i+1,i+1);
        n[i]=c;
    }
    CComplexVector a(n),b(n);
    f=Machinator3000(a, b);
    for(int i=1; i<LENGTH+1; i++)
    {
        m=i*i+m;
    }
    if(  f.Re()==2*m && f.Im()==0  )
        {
            cout<<"Autotest passed! respect+..."<<endl;
        }

    else
    {
        cout<<"Autotest failed! wasted..."<<endl;
    }
}
