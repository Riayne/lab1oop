#include <iostream>
#include <string>
using namespace std;


const int MAX_MENU_SIZE = 10;
const int MAX_ORDERS_SIZE = 20;


class MenuItem {
public:
    string name;
    string type; 
    double price;

   
    MenuItem(string n = "", string t = "", double p = 0.0) : name(n), type(t), price(p) {}
};

/
class CoffeeShop {
private:
    string name;
    MenuItem menu[MAX_MENU_SIZE]; 
    int menuSize; 
    string orders[MAX_ORDERS_SIZE]; 
    int ordersSize;

public:
    
    CoffeeShop(string n, MenuItem m[], int mSize) : name(n), menuSize(mSize) {
       
        for (int i = 0; i < mSize; i++) {
            menu[i] = m[i];
        }
        ordersSize = 0; 
    }

   
    string addOrder(string itemName) {
       
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (ordersSize < MAX_ORDERS_SIZE) {
                    orders[ordersSize++] = itemName; 
                    return itemName + " added to orders!";
                } else {
                    return "Order list is full.";
                }
            }
        }
        return "This item is currently unavailable.";
    }

   
    string fulfillOrder() {
        if (ordersSize > 0) {
            string item = orders[0]; 
           
            for (int i = 1; i < ordersSize; i++) {
                orders[i - 1] = orders[i];
            }
            ordersSize--; 
            return "The " + item + " is ready.";
        } else {
            return "All orders have been fulfilled.";
        }
    }

    
    void listOrders() {
        if (ordersSize == 0) {
            cout << "No orders placed yet." << endl;
            return;
        }
        cout << "Orders: ";
        for (int i = 0; i < ordersSize; i++) {
            cout << orders[i] << " ";
        }
        cout << endl;
    }

   
    double dueAmount() {
        double total = 0.0;
        for (int i = 0; i < ordersSize; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

   
    string cheapestItem() {
        if (menuSize == 0) return "No items available.";
        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

   
    void drinksOnly() {
        cout << "Drinks: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }

   
    void foodOnly() {
        cout << "Foods: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    
    MenuItem menu[MAX_MENU_SIZE] = {
        MenuItem("Latte", "drink", 3.50),
        MenuItem("Cappuccino", "drink", 4.00),
        MenuItem("Sandwich", "food", 5.50),
        MenuItem("Croissant", "food", 2.50)
    };
    int menuSize = 4; 

    
    CoffeeShop shop("Java Junction", menu, menuSize);

    // Test the methods
    cout << shop.addOrder("Latte") << endl; 
    cout << shop.addOrder("Tea") << endl;   
    cout << shop.fulfillOrder() << endl;    
    shop.listOrders();                      
    cout << "Total Due: $" << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    shop.drinksOnly();                      
    shop.foodOnly();                        

    return 0;
}
