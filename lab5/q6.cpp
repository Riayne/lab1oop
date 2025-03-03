#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CoffeeShop {
private:
    const string Name; // Constant name of the coffee shop
    vector<vector<string>> Menu; // Menu items: {name, type, price}
    vector<string> Orders; // List of orders

public:
    // Constructor to initialize the coffee shop name and menu
    CoffeeShop(const string& name, const vector<vector<string>>& menu)
        : Name(name), Menu(menu) {}

    // Function to add an order
    string addOrder(const string& itemName) {
        for (const auto& item : Menu) {
            if (item[0] == itemName) { // Check if the item exists in the menu
                Orders.push_back(itemName);
                return itemName + " added to orders!";
            }
        }
        return "This item is currently unavailable!";
    }

    // Function to fulfill an order
    string fulfillOrder() {
        if (!Orders.empty()) {
            string item = Orders[0]; // Get the first order
            Orders.erase(Orders.begin()); // Remove the first order
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled!";
    }

    // Function to list all orders
    vector<string> listOrders() {
        return Orders;
    }

    // Function to calculate the total amount due
    float dueAmount() {
        float total = 0.0;
        for (const auto& order : Orders) {
            for (const auto& item : Menu) {
                if (item[0] == order) {
                    total += stof(item[2]); // Convert price string to float
                    break;
                }
            }
        }
        return total;
    }

    // Function to find the cheapest item on the menu
    string cheapestItem() {
        if (Menu.empty()) return "No items available!";
        string cheapest = Menu[0][0]; // Assume the first item is the cheapest
        float cheapestPrice = stof(Menu[0][2]);
        for (const auto& item : Menu) {
            float price = stof(item[2]);
            if (price < cheapestPrice) {
                cheapest = item[0];
                cheapestPrice = price;
            }
        }
        return cheapest;
    }

    // Function to return only drink items
    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : Menu) {
            if (item[1] == "drink") {
                drinks.push_back(item[0]);
            }
        }
        return drinks;
    }

    // Function to return only food items
    vector<string> foodOnly() {
        vector<string> food;
        for (const auto& item : Menu) {
            if (item[1] == "food") {
                food.push_back(item[0]);
            }
        }
        return food;
    }
};

int main() {
    // Example usage
    vector<vector<string>> menu = {
        {"Latte", "drink", "3.50"},
        {"Cappuccino", "drink", "4.00"},
        {"Sandwich", "food", "5.50"},
        {"Croissant", "food", "2.50"}
    };

    CoffeeShop shop("Java Junction", menu);

    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Pizza") << endl; // Unavailable item

    cout << "Orders: ";
    for (const auto& order : shop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due: $" << shop.dueAmount() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks: ";
    for (const auto& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food: ";
    for (const auto& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;

    return 0;
}
