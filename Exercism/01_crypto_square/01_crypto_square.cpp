#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

class CryptoSquare {
public:
    static string cipher(const string& text) {
        // 1. Normalización: eliminar espacios/puntuación y pasar a minúsculas
        string normalized = "";
        for (char c : text) {
            if (isalnum(c)) {
                normalized += tolower(c);
            }
        }

        if (normalized.empty()) {
            return "";
        }

        int length = normalized.length();

        // 2. Determinar filas (r) y columnas (c)
        int c = ceil(sqrt(length));
        int r = (c * (c - 1) >= length) ? c - 1 : c;

        // 3. Rellenar con espacios si hace falta para completar el rectángulo (r x c)
        while ((int)normalized.length() < r * c) {
            normalized += " ";
        }

        // 4. Leer por columnas codificando el mensaje
        string ciphertext = "";
        for (int col = 0; col < c; ++col) {
            if (col > 0) {
                ciphertext += " ";
            }
            for (int row = 0; row < r; ++row) {
                ciphertext += normalized[row * c + col];
            }
        }

        return ciphertext;
    }
};

int main() {
    string message = "If man was meant to stay on the ground, god would have given us roots.";
    
    cout << "==========================================" << endl;
    cout << "          EJERCICIO 01: CRYPTO SQUARE      " << endl;
    cout << "==========================================" << endl;
    cout << "Mensaje original:\n\"" << message << "\"\n" << endl;
    
    string result = CryptoSquare::cipher(message);
    
    cout << "Mensaje cifrado:\n\"" << result << "\"" << endl;
    cout << "==========================================" << endl;

    return 0;
}