
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    string publisher;
    double price;
    int stockPosition;

public:
    // Constructor to initialize book details
    Book(string auth, string ttl, double prc, string pub, int stk)
        : author(auth), title(ttl), price(prc), publisher(pub), stockPosition(stk) {}

    // Method to check if the book matches the search criteria
    bool isMatch(string searchTitle, string searchAuthor) const {
        return (title == searchTitle && author == searchAuthor);
    }

    // Method to display book details
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock Position: " << stockPosition << endl;
    }

    // Method to process the purchase
    void purchase(int copies) {
        if (copies <= stockPosition) {
            double totalCost = price * copies;
            stockPosition -= copies;
            cout << "Total Cost: $" << totalCost << endl;
        } else {
            cout << "Insufficient copies available." << endl;
        }
    }
};

int main() {
    // Create an array of books to represent the inventory
    Book inventory[] = {
        Book("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", 15.99, "Bloomsbury", 10),
        Book("George Orwell", "1984", 12.50, "Secker & Warburg", 5),
        Book("Harper Lee", "To Kill a Mockingbird", 10.99, "J.B. Lippincott & Co.", 7)
    };

    // Input from the customer
    string searchTitle, searchAuthor;
    cout << "Enter the title of the book: ";
    getline(cin, searchTitle);
    cout << "Enter the author of the book: ";
    getline(cin, searchAuthor);

    // Search for the book in the inventory
    bool found = false;
    for (auto& book : inventory) { // Remove 'const' to allow modification
        if (book.isMatch(searchTitle, searchAuthor)) {
            found = true;
            book.displayDetails();

            // Request the number of copies
            int requestedCopies;
            cout << "Enter the number of copies required: ";
            cin >> requestedCopies;

            // Process the purchase
            book.purchase(requestedCopies);
            break;
        }
    }

    // Display message if the book is not found
    if (!found) {
        cout << "The book is not available in the inventory." << endl;
    }

    return 0;
}
