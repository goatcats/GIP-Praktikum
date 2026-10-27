#include <iostream>
using namespace std;

void compareDate() {
    int day1, day2, month1, month2, year1, year2;

    cout << "Bitte geben sie den Tag des ersten Datums ein: ";
    cin >> day1; cout << endl;

    cout << "Bitte geben sie den Monat des ersten Datums ein: ";
    cin >> month1; cout << endl;

    cout << "Bitte geben sie das Jahr des ersten Datums ein: ";
    cin >> year1; cout << endl;

    cout << "Bitte geben sie den Tag des zweiten Datums ein: ";
    cin >> day2; cout << endl;

    cout << "Bitte geben sie den Monat des zweiten Datums ein: ";
    cin >> month2; cout << endl;

    cout << "Bitte geben sie das Jahr des zweiten Datums ein: ";
    cin >> year2; cout << endl;

    if (year1 > year2) {
        cout << "Das zweite Datum liegt vor dem ersten Datum."; return;
    } else if (year1 < year2) {
        cout << "Das erste Datum liegt vor dem zweiten Datum."; return;
    }

    if (month1 > month2) {
        cout << "Das zweite Datum liegt vor dem ersten Datum."; return;
    } else if (month1 < month2) {
        cout << "Das erste Datum liegt vor dem zweiten Datum."; return;
    }

    if (day1 > day2) {
        cout << "Das zweite Datum liegt vor dem ersten Datum."; return;
    } else if (day1 < day2) {
        cout << "Das erste Datum liegt vor dem zweiten Datum."; return;
    }
    
    cout << "Beide Datumsangaben sind gleich.";

}

int addChars() {
    char char1, char2;
    int num1, num2;

    cout << "Bitte geben Sie die erste Ziffer ein: ? ";
    cin >> char1;

    cout << "Bitte geben Sie die zweite Ziffer ein: ? ";
    cin >> char2;

    if (char1 == 'q' || char2 == 'q') {
        cout << "Das Programm wurde durch Eingabe von q beendet." << endl;
        system("pause");
        return 1;
    } else {
        num1 = (int) (char1 - '0');
        num2 = (int) (char2 - '0');
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        system("pause");
        return 0;
    }
}

int main() {
    compareDate();
    system("pause");
    return 0;
}