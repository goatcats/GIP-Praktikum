#include <iostream>
#include <string>
using namespace std;

int diagramm() {
    int arr[5];
    for (int i=0; i<size(arr); i++) {
        do {
            cout << "Bitte geben Sie die " << i+1 << ". Zahl ein: ? ";
            cin >> arr[i];
        } while (arr[i] <= 0 || arr[i] > 9);
    }

    for (int i=9; i>=1; i--) {
        cout << i;
        for (int j=0; j<size(arr); j++) {
            if (arr[j] > i) {
                cout << "+";
            }
            else if (arr[j] == i) {
                cout << "*";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }

    cout << " ";
    
    for (int i=0; i<size(arr); i++) {
        cout << i+1;
    }

    cout << endl;

    return 0;
}

int sudoku() {
    unsigned int sudoku[9][9];
    string eingabe [11];

    cout << "Bitte geben Sie das Sudoku ein:" << endl;

    int currPosY = 0;
    for (int i=0; i<size(eingabe); i++) {
        getline(cin, eingabe[i]);
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

    cout << endl << "Das Sudoku lautet:" << endl;

    for (int i=0; i<9; i++) {
        if (!(i%3) && i>0) {cout << "=======//=======//=======" << endl;}
        for (int j=0; j<9; j++) {
            if (!(j%3) && j>0) {cout << ";//";}
            cout << ";" << sudoku[i][j];
        }
        cout << endl;
    }

    return 0;
}

/*
.5.1.4.|.8.6.9.|.7.2.3
.8.7.2.|.3.4.5.|.6.1.9
.9.6.3.|.2.1.7.|.5.4.8
-------|-------|-------
.6.2.8.|.1.3.4.|.9.5.7
.1.9.7.|.6.5.2.|.8.3.4
.4.3.5.|.7.9.8.|.1.6.2
-------|-------|-------
.2.4.6.|.9.7.1.|.3.8.5
.7.5.1.|.4.8.3.|.2.9.6
.3.8.9.|.5.2.6.|.4.7.1
*/

int main () {
   return sudoku();
}