#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int caeserCypher() {
    string plaintext;
    string encryptedText = "";
    int shift;

    cout << "Bitte geben sie den zu verschlüsselnden Text ein: ? ";
    getline(cin, plaintext);

    cout << "Bitte geben sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl) : ? ";
    cin >> shift;

    for (int i=0; i<plaintext.length(); i++) {
        char curr = plaintext[i];

        if (curr >= 'A' && curr <= 'Z') {
            int posInAlphabet = ((curr+shift) - 'A') % 26;
            curr = (posInAlphabet + 'A');
        }

        else if (curr >= 'a' && curr <= 'z') {
            int posInAlphabet = ((curr+shift) - 'a') % 26;
            curr = (posInAlphabet + 'a');
        }

        encryptedText += curr;
    }

    cout << encryptedText;

    return 0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    return caeserCypher();
}