// Datei: suchen_rekursiv_main.cpp

#define CATCH_CONFIG_RUNNER
#include "gip_mini_catch.h"

#include <iostream>
using namespace std;

#include "suchen_rekursiv.h"

int main()
{
    Catch::Session().run();

    string text, zkette;
    cout << "Bitte geben Sie den Text ein: ? ";
    getline(cin, text);

    cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ? ";
    getline(cin, zkette);
	
    int res = zeichenkette_suchen_rekursiv(text, zkette, 0, 0, 0);

    if (res < 0) {
        cout << "Die Zeichenkette " << "'" << zkette << "'" << " ist NICHT in dem Text " << "'" << text << "'" << " enthalten." << endl;
        return 0;
    }

    cout << "Die Zeichenkette " << "'" << zkette << "'" << " ist in dem Text " << "'" << text << "'" << " enthalten." << endl
        <<  "Sie startet ab Zeichen " << res << " (bei Zaehlung ab 0)." << endl;

    return 0;
}
