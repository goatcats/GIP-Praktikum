#include <iostream>
#include <string>
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

    cout << encryptedText << endl;

    return 0;
}

int busfahrplan() {
    int h, m, t;

    do {
        cout << "Bitte geben Sie die Stunden der Startuhrzeit ein: ? ";
        cin >> h;
    } while (h < 0 || h >= 24);

    do {
        cout << "Bitte geben Sie die Minuten der Startuhrzeit ein: ? ";
        cin >> m;
    } while (m < 0 || m >= 60);

    cout << "Der erste Bus fährt also um " << h << ":" << m << " Uhr." << endl;

    do {
        cout << "Bitte geben Sie die Taktzeit in Minuten ein: ? ";
        cin >> t;
    } while (t <= 0 || t > 180);

    while (h < 24) {
        while (m < 60) {
            cout << h << ":" << m << " ";
            m += t;
        }
        h += m/60;
        m %= 60;
        cout << endl;
    }

    return 0;
}

int main() {
    return busfahrplan();
}