// Datei: suchen_rekursiv.cpp

#include <string>
#include "aufruf_visualisieren.h"
#include "suchen_rekursiv.h"

int zeichenkette_suchen_rekursiv(
	std::string text,  			// text
	std::string zkette, 		// sub
	size_t text_pos,  			// current index in text
	size_t text_such_pos, 		// ??
	size_t zkette_such_pos)		// current index in sub
{
	// Die folgende Zeile "aktivieren", wenn Sie zusaetzliche Programmausgaben
	// haben moechten, die das Verstaendnis der rekursiven Aufrufe ggfs.
	// unterstuetzen ...
	// aufruf_visualisieren(text, zkette, text_pos, text_such_pos, zkette_such_pos);

	// Ihr Code ab hier ...

	if (text.length() == 0) {
		return -1;
	}


	if (text[text_pos] == zkette[zkette_such_pos]) {
		if (zkette_such_pos == zkette.length()-1) {
			return text_pos - zkette_such_pos;
		}
		return zeichenkette_suchen_rekursiv(text, zkette, text_pos+1, 0, zkette_such_pos+1);
	}
	else {
		if (text_pos == text.length()-1) {
			return -1;
		}
		return zeichenkette_suchen_rekursiv(text, zkette, text_pos+1, 0, 0);
	}


}
