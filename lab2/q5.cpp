#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the structure
struct Entity {
    int id;
    string name;
};

// Function to print the structure data
void printEntities(const vector<Entity>& entities) {
    for (const auto& entity : entities) {
        cout << "ID: " << entity.id << ", Name: " << entity.name << endl;
    }
}

// Comparator function to compare two entities
bool compareEntities(const Entity& e1, const Entity& e2) {
    if (e1.id != e2.id) {
        return e1.id < e2.id; // Sort by id
    }
    return e1.name[0] < e2.name[0]; // If ids are equal, sort by the first character of the name
}

// Function to implement bubble sort
void bubbleSort(vector<Entity>& entities) {
    int n = entities.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            // Compare adjacent entities using the compareEntities function
            if (!compareEntities(entities[j], entities[j + 1])) {
                // Swap entities if they are in the wrong order
                swap(entities[j], entities[j + 1]);
            }
        }
    }
}

int main() {
    int N;

    // Get the number of entities
    cout << "Enter the number of entities: ";
    cin >> N;

    vector<Entity> entities(N);

    // Input entities
    for (int i = 0; i < N; ++i) {
        cout << "Enter ID and Name for entity " << i + 1 << ": ";
        cin >> entities[i].id >> entities[i].name;
    }

    // Sort by id and name's first character using bubble sort
    bubbleSort(entities);

    // Print the sorted entities
    cout << "\nEntities sorted by ID and name's first character:" << endl;
    printEntities(entities);

    return 0;
}
