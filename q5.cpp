#include <iostream>
using namespace std;

int main(){
    string name;
    float totalPrice,adultPrice,childrenPrice,donated,net;
    float adult,children,total,gross;

    cout<<"enter movie name"<<endl;
    cin>>name;

    cout<<"enter no of adult tickets sold and price of one ticket respectively"<<endl;
    cin>>adult>>adultPrice;

    cout<<"enter no of children tickets sold and price of one ticket respectively"<<endl;
    cin>>children>>childrenPrice;

    cout<<"enter amount you want to donate to charity(in %)"<<endl;
    cin>>gross;
    total = adult + children;
    totalPrice=(adult * adultPrice) + (children * childrenPrice);
    donated=(gross/100)*totalPrice;
    net=(1+(gross/100))*totalPrice;

    cout<<"Movie................................"<<name<<endl;
    cout<<"Number of tickets sold..............."<<total<<endl;
    cout<<"Gross amount........................."<<totalPrice<<endl;
    cout<<"percentage of gross amount donated..."<<gross<<endl;
    cout<<"amount donated......................."<<donated<<endl;
    cout<<"net sale............................."<<net<<endl;



}
