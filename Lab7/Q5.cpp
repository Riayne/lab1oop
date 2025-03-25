#include <iostream>
#include <vector>
using namespace std;

// Base class: Media
class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isAvailable;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isAvailable(true) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
             << "\nAvailability: " << (isAvailable ? "Available" : "Checked Out") << "\n";
    }

    virtual void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << title << " has been checked out.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }

    virtual void returnItem() {
        if (!isAvailable) {
            isAvailable = true;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }

    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
    string getUniqueID() const { return uniqueID; }

    virtual ~Media() {}
};

// Derived class: Book
class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

// Derived class: DVD
class DVD : public Media {
private:
    string director, rating;
    int duration; // in minutes

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << "\n";
    }
};

// Derived class: CD
class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pubDate, string id, string pub, string art, string gen, int tracks)
        : Media(t, pubDate, id, pub), artist(art), genre(gen), numberOfTracks(tracks) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nGenre: " << genre << "\nTracks: " << numberOfTracks << "\n";
    }
};

// Derived class: Magazine
class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(string t, string pubDate, string id, string pub, int issue)
        : Media(t, pubDate, id, pub), issueNumber(issue) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << "\n";
    }
};

// Library class to manage media items
class Library {
private:
    vector<Media*> catalog;

public:
    void addMedia(Media* item) {
        catalog.push_back(item);
    }

    // Function overloading for searching
    void search(string title) const {
        cout << "\nSearching for title: " << title << "\n";
        for (const auto& item : catalog) {
            if (item->getTitle() == title) {
                item->displayInfo();
                return;
            }
        }
        cout << "No media found with title: " << title << "\n";
    }

    void searchByPublicationDate(string pubDate) const {
        cout << "\nSearching for publication date: " << pubDate << "\n";
        for (const auto& item : catalog) {
            if (item->getPublicationDate() == pubDate) {
                item->displayInfo();
            }
        }
    }

    void displayAll() const {
        cout << "\n=== Library Catalog ===\n";
        for (const auto& item : catalog) {
            item->displayInfo();
            cout << "------------------------\n";
        }
    }

    ~Library() {
        for (auto item : catalog) {
            delete item;
        }
    }
};

// Main function
int main() {
    Library lib;

    // Creating media objects
    Book* book = new Book("C++ Programming", "2022-01-15", "B1001", "O'Reilly", "Bjarne Stroustrup", "123456789", 500);
    DVD* dvd = new DVD("Inception", "2010-07-16", "D2001", "Warner Bros.", "Christopher Nolan", 148, "PG-13");
    CD* cd = new CD("Thriller", "1982-11-30", "C3001", "Epic Records", "Michael Jackson", "Pop", 9);
    Magazine* magazine = new Magazine("National Geographic", "2023-03", "M4001", "National Geographic Society", 104);

    // Adding to library
    lib.addMedia(book);
    lib.addMedia(dvd);
    lib.addMedia(cd);
    lib.addMedia(magazine);

    // Display all media
    lib.displayAll();

    // Searching for media
    lib.search("Inception");
    lib.searchByPublicationDate("2022-01-15");

    // Checking out and returning items
    book->checkOut();
    book->returnItem();
    dvd->checkOut();

    return 0;
}
