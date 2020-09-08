#pragma once
#define LENGTH 3
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


class CComplexNum
{
    double re, im;
public:
    CComplexNum(){re=0; im=0;}
    CComplexNum(double re, double im){this->re=re; this->im=im;}
    double Re()const{return re;}
    double Im()const{return im;}
    CComplexNum operator+(const CComplexNum &b){CComplexNum m(re+b.Re(), im+b.Im()); return m;}
    CComplexNum operator-(const CComplexNum &b){CComplexNum m(re-b.Re(), im-b.Im()); return m;}
    CComplexNum operator*(const CComplexNum &b){CComplexNum m(re*b.Re()-im*b.Im(), re*b.Im()+ im*b.Re()); return m;}
    void print(){if (im>=0){printf("%lg+%lgi", re, im);}else{printf("%lg%lgi", re, im);}}
};


class CComplexVector
{
    CComplexNum a[LENGTH];
public:
    CComplexVector(){for(int i=0; i<LENGTH; i++){CComplexNum m; a[i]=m;}}
    CComplexVector(const CComplexNum *b){for(int i=0; i<LENGTH; i++){a[i]=b[i];}}
    CComplexVector Conjugate(){CComplexVector m; for(int i=0; i<LENGTH; i++){CComplexNum c(a[i].Re(), -a[i].Im()); m.a[i]=c;} return m; }
    CComplexVector &operator=(const CComplexVector &b){for(int i=0; i<LENGTH; i++){a[i]=b.a[i];}}
    CComplexVector operator+(const CComplexVector &b){CComplexVector m; for(int i=0; i<LENGTH; i++){m.a[i]=a[i]+b.a[i];} return m;}
    CComplexVector operator-(const CComplexVector &b){CComplexVector m; for(int i=0; i<LENGTH; i++){m.a[i]=a[i]-b.a[i];}; return m;}
    CComplexNum operator*(CComplexVector &b){CComplexNum m; b=b.Conjugate(); for(int i=0; i<LENGTH; i++){m=m+a[i]*b.a[i];}; return m;}
    void print(){CComplexNum m; printf("("); for(int i=0; i<LENGTH-1; i++){m=a[i]; m.print(); printf(", ");} m=a[LENGTH-1]; m.print(); printf(")\n");}
};

CComplexVector FuncVvoda(CComplexNum* arr, const char t[256]);
ostream &operator<<(ostream &cout,  CComplexVector &s);
ostream &operator<<(ostream &cout,  CComplexNum &s);
CComplexNum Machinator3000( CComplexVector vect1,  CComplexVector vect2);
void Autotest(void);








