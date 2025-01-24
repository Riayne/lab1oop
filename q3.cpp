#include <iostream>
using namespace std;

int main(){
    int id;
    float bill,charge,units,surBill = 1,surAmount = 0;
    string name;

    cout<<"enter your id,name and units consumed:"<< endl;
    cin >> id>>name>>units;

    if (units<=199){
        bill = units*16.2;
    }
    else if (units>=200 && units<300)
    {
        bill = units*20.10;
    }
    else if(units>=300 && units <500){
        bill = units*27.1;
    }
     else if(units >= 500){
        bill = units*35.9;
    }
    if (bill>18000){
        surBill = bill*1.15;
        surAmount = surBill-bill;
    }
    else{
        surBill = bill;
    }
    
    cout<<"ID: "<<id<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"units consumed: "<<units<<endl;
    cout<<"bill (before surcharge): "<<bill<<endl;
    cout<<"surcharge "<<surAmount<<endl;
    cout<<"bill(after surcharge)"<<surBill<<endl;


}
