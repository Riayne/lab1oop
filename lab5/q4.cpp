#include <iostream>
#include <thread> 
#include <chrono> 

using namespace std;


class Blend {
public:
    void blendFruits() {
        cout << "Selecting fruits for blending...\n";
        for (int i = 1; i <= 5; ++i) {
            cout << "Blending in progress... (" << i << " seconds)\n";
            this_thread::sleep_for(chrono::seconds(1)); 
        }
        cout << "Blending complete!\n";
    }
};


class Grind {
public:
    void grindFruits() {
        cout << "Selecting fruits for grinding...\n";
        cout << "Grinding in progress...\n";
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Grinding complete!\n";
    }
};


class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void blendJuice() {
        cout << "Starting blend juice process...\n";
        blender.blendFruits();
        cout << "Blend juice is ready!\n";
    }

    void grindJuice() {
        cout << "Starting grind juice process...\n";
        grinder.grindFruits();
        cout << "Grind juice is ready!\n";
    }
};

int main() {
    JuiceMaker juiceMaker;

   
    cout << "--- Blending Juice ---\n";
    juiceMaker.blendJuice();

    
    cout << "\n--- Grinding Juice ---\n";
    juiceMaker.grindJuice();

    return 0;
}
