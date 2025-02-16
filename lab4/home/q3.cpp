
#include <iostream>
using namespace std;

class Invoice {
    
    string partNum;
    string partDesc;
    int quantity;
    double pricePerItem;
    
    public:
    
    Invoice(string n,string d,int q,double p){
        partNum = n;
        partDesc = d;
        
        if(q>0){
            quantity = q;
        }
        else{
            quantity = 0;
        }
       
        if (p > 0.0) {
            pricePerItem = p;
        } else {
            pricePerItem = 0.0;
        }
        
    }
    
    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {

    Invoice invoice1("1234", "Hammer", 2, 15.99); // Valid invoice
    Invoice invoice2("5678", "Screwdriver", -5, 9.99); // Invalid quantity
    Invoice invoice3("91011", "Pliers", 10, -3.99); // Invalid price

    cout << "Invoice 1 Amount: $" << invoice1.getInvoiceAmount() << endl; 
    cout << "Invoice 2 Amount: $" << invoice2.getInvoiceAmount() << endl; 
    cout << "Invoice 3 Amount: $" << invoice3.getInvoiceAmount() << endl;

    return 0;
}
