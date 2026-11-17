#include <iostream>
#include <string>
using namespace std;

const size_t sudoku_groesse = 9;
const size_t eingabe_groesse = 11;

int count(int arr[sudoku_groesse], int x) {
    int c = 0;
    for (int i=0; i<sudoku_groesse; i++) {
        if (arr[i] == x) c++;
    }
    return c;
}

bool printErrors(int arr[sudoku_groesse], string category, int pos) {
    bool res = true;
    for (int n=1; n<sudoku_groesse+1; n++) {
        int c = count(arr, n);
        if (c == 0 || c > 1) {
            cout << category << " " << pos << ": Zahl " << n << " kommt " << (!c ? "nicht" : "mehrfach") << " vor." << endl;
            res = false;
        }
    }
    return res;
}

bool pruefe_spalten(int sudoku[][sudoku_groesse]) {
    bool res = true;
    for (int i=0; i<sudoku_groesse; i++) {      // i zählt spalten
        int spalte[sudoku_groesse];
        for (int j=0; j<sudoku_groesse; j++) {
            spalte[j] = sudoku[j][i];
        }
        res = printErrors(spalte, "Spalte", i) && res;
    }
    return res;
}

bool pruefe_zeilen(int sudoku[][sudoku_groesse]) {
    bool res = true;
    for (int i=0; i<sudoku_groesse; i++) {      // i zählt zeilen 
        res = printErrors(sudoku[i], "Zeile", i) && res;
    }
    return res;
}

bool pruefe_bloecke(int sudoku[][sudoku_groesse]) {
    bool res = true;
    for (int i=0; i<sudoku_groesse; i++) {      // i zählt blöcke
        int block[sudoku_groesse];
        int iBlock = 0;
        for (int m=i/3*3; m<i/3*3+3; m++) {
            for(int n=i%3*3; n<i%3*3+3; n++) {
                block[iBlock] = sudoku[m][n];
                iBlock++;
            }
        }
        res = printErrors(block, "Block", i) && res;
    }
    return res;
}

void konvertiere(string eingabe[], int sudoku[][sudoku_groesse])
{
    int currPosY = 0;
    for (int i=0; i<eingabe_groesse; i++) {
        string currLine = eingabe[i];
        if (currLine[0] == '-') continue;
        int currPosX = 0;
        for (size_t j=0; j<currLine.length(); j++) {
            if (currLine[j] > '0' && currLine[j] <= '9') {
                sudoku[currPosY][currPosX] = currLine [j] - '0';
                currPosX++;
            }
        }
        currPosY++;
    }
}

int main() {
    int sudoku[sudoku_groesse][sudoku_groesse] = { 0 };
    string eingabe[eingabe_groesse];

    cout << "Bitte geben Sie das Sudoku ein:" << endl;
    for (size_t i = 0; i < eingabe_groesse; i++)
        getline(cin, eingabe[i]);

    konvertiere(eingabe, sudoku);

    bool ps = pruefe_spalten(sudoku);
    bool pz = pruefe_zeilen(sudoku);
    bool pb = pruefe_bloecke(sudoku); 

    if (ps && pz && pb)
        cout << "Das Sudoku ist gueltig." << endl;

    return 0;
}