#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int id;
    float kilo,pound,rkilo,rpound;
    cout<<"enter wieght in kilogram"<<endl;
    cin>>kilo;
    rkilo = round(kilo*100)/100;
    pound = 2.2 *rkilo;
    rpound = round(pound*100)/100;
    cout<<"pound: "<<rpound<<endl;
    cout<<"kilogram: "<<rkilo<<endl;


}
