#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string encrypt(const string &text) {
    string encrypted_text = "";
    
    for (int i = 0; i < text.length(); ++i) {
        char encrypted_char = text[i] + (i + 1); 
        encrypted_text += encrypted_char;
    }
    
   
    ofstream outfile("encrypted_text.txt");
    outfile << encrypted_text;
    outfile.close();
    
    cout << "Encrypted text inserted in file" << endl;
    return encrypted_text;
}


string decrypt() {
    
    ifstream infile("encrypted_text.txt");
    string encrypted_text;
    infile >> encrypted_text;
    infile.close();
    
    string decrypted_text = "";
    
   
    for (int i = 0; i < encrypted_text.length(); ++i) {
        char decrypted_char = encrypted_text[i] - (i + 1); 
        decrypted_text += decrypted_char;
    }
    
    cout << "Decrypted text Read then decoded from file" << endl;
    return decrypted_text;
}

int main() {
    string text;
    
   
    cout << "Enter String = ";
    getline(cin, text);
    
    cout << "Normal Text: " << text << endl;
    
   
    string encrypted_text = encrypt(text);
    
   
    cout << "Encrypted text: " << encrypted_text << endl;
    
   
    string decrypted_text = decrypt();
    
  
    cout << "Decrypted text: " << decrypted_text << endl;
    
    return 0;
}
