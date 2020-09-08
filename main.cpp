#include "klass.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &cout,  CComplexVector &s){s.print(); return cout;}
ostream &operator<<(ostream &cout,  CComplexNum &s){s.print(); return cout;}
CComplexVector FuncVvoda(CComplexNum* arr, const char s[256])
{

   double n, m;
   cout<<endl;
    for (int i=0; i<LENGTH;i++)
    {
         cout<<"Enter "<<i+1<<" coordinate"<<endl;
         cout<<"double Re: ";cin>>m;
         if(cin.fail())
         {
             cout<<"Error! Wrong number";
             exit(1);
         }
         cout<<"double Im: ";cin>>n;
         if(cin.fail())
         {
             cout<<"Error! Wrong number";
             exit(1);
         }
         cout<<endl;
         CComplexNum c(m,n);
         arr[i]=c;
    }
         CComplexVector vect(arr);
         cout<<"Vector "<<s<<": ";
         vect.print();
         cout<<endl;
         return vect;
}

CComplexNum Machinator3000( CComplexVector vect1, CComplexVector vect2)
{
    CComplexVector vect3;
    CComplexNum r;
             cout<<"Results:"<<endl;

            vect3=vect1+vect2;
            cout<<"a+b="<<vect3;

            vect3=vect1-vect2;
            cout<<"a-b="<<vect3;

            r=vect1*vect2;
            cout<<"(a;b)="<<r<<endl;
            cout<<endl;
            return r;
}




int main(void)
{
    CComplexNum c, arr[LENGTH], brr[LENGTH];
    CComplexVector vect1, vect2, vect3;
    int a;
    cout<<"Welcome to "<<LENGTH<<"-dimensional unitary space with Hermitian scalar product!"<<endl;
    cout<<"Write down your vectors:"<<endl;
    vect1=FuncVvoda(arr, "a");
    vect2=FuncVvoda(brr, "b");
    Machinator3000(vect1, vect2);
    Autotest();
    return 0;
}
