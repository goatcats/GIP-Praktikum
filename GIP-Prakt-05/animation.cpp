#define CIMGGIP_MAIN
#include "CImgGIP08.h"

int main()
{
    // Für das "blaue Spielfeld" ...
    const int left_border = 100;
    const int right_border = 500;

    // Für Ausdehnung und Position des weißen Quadrats ...
    int x = 200, y = 300;
    const int rectangle_size = 50;
    int delta = 10;

    gip_white_background();

    while (gip_window_not_closed())
    {
        // Blaues "Spielfeld" neu zeichnen
        // (übermalt dann auch das letzte weiße Quadrat) ...
        gip_draw_rectangle(left_border, 100, // linke obere Ecke
            right_border, 500, // rechte untere Ecke
            blue);

        // Weißes Quadrat neu zeichnen an der Position x,y ...
        gip_draw_rectangle(x, y,    // linke obere Ecke
            x + rectangle_size,  // rechte untere Ecke
            y + rectangle_size,
            white);

        // Nächste Position des weißen Quadrats berechnen.
        // Dabei berücksichtigen, dass das Quadrat von den Rändern des
        // blauen "Spielfelds" abprallen muss ...

		// Bewegung auf x-Achse anwenden
        x += delta;

        // Abprallen an den vertikalen Rändern (links/rechts)
        if (x <= left_border || x + rectangle_size >= right_border) {
            delta = -delta; // Richtung umkehren
        }


        gip_wait(100);
    }
    return 0;
}
