#include <iostream>

#include "imagenES.h"
#include "image.h"
#include "tools.h"
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    int option = 0;
    const int TERMINADOR = 4;
    char *sourceName;

    if (argc != 2) {
        cerr << "Error: Inicialización incorrecta." << endl;
        cerr << "Ejemplo ejecución: ./ProgramaImagen (ImagenPGMOriginal)" << endl;
        exit(1);
    }

    sourceName = argv[1];

    cout << "*******************************************" << endl;
    cout << "** Programa de procesamiento de imágenes **" << endl;
    cout << "*******************************************" << endl;
    
    do
    {
        cout << "Elija una opción:" << endl;
        cout << "1 - Ejercicio 1" << endl;
        cout << "2 - Ejercicio 2" << endl;
        cout << "3 - Ejercicio 3" << endl;
        cout << "4 - Salir" << endl;
        cin >> option;
        
        switch (option) {
            case 1:
            {
                int rowImg, colImg, rowSub, colSub;
                string destStr;
                char* newDestName;

                cout << "*********************************" << endl;
                cout << "** Extracción de una subimagen **" << endl;
                cout << "*********************************" << endl;
                
                cout << "Nombre para la subimagen:" << endl;
                cout << "Formato: [nombre].pgm" << endl;
                cin >> destStr;

                newDestName = new char [destStr.length()+1];
                strcpy (newDestName, destStr.c_str());

                do
                {
                    cout << "Punto en la imagen original y tamaño de la subimagen:" << endl;
                    cout << "Formato: xImgOriginal yImagenOriginal numFilasSubImg numColSubImg" << endl;
                    cin >> rowImg >> colImg >> rowSub >> colSub;
                } while ((rowImg < 0 || colImg < 0) || (rowSub <= 0 || colSub <= 0));

                subImage(sourceName, newDestName, rowImg, colImg, rowSub, colSub);
                break;
            }

            case 2:
            {
                int xUpperL, yUpperL, xLowerR, yLowerR;
                string destStr;
                char* newDestName;

                cout << "*********************************" << endl;
                cout << "******* Zoom a una imagen *******" << endl;
                cout << "*********************************" << endl;

                cout << "Nombre para la imagen ampliada:" << endl;
                cout << "Formato: [nombre].pgm" << endl;
                cin >> destStr;

                newDestName = new char [destStr.length()+1];
                strcpy (newDestName, destStr.c_str());

                cout << "Esquina superior izquierda e inferior derecha de la imagen original: " << endl;
                cout << "Formato: coord. X esquina superior coord. Y esquina superior coord. X esquina inferior coord. Y esquina inferior " << endl; // Esto es una mierda
                cin >> xUpperL >> yUpperL >> xLowerR >> yLowerR;

                zoom(sourceName, newDestName, xUpperL, yUpperL, xLowerR, yLowerR);

                break;
            }
            case 3:
            {
                int e1, e2, s1, s2;
                string destStr;
                char* newDestName;

                cout << "*********************************" << endl;
                cout << "***** Histogram stretching ******" << endl;
                cout << "*********************************" << endl;

                cout << "Nombre para la imagen ampliada:" << endl;
                cout << "Formato: [nombre].pgm" << endl;
                cin >> destStr;

                newDestName = new char [destStr.length()+1];
                strcpy (newDestName, destStr.c_str());

                cout << "Parámetros para los intervalos: " << endl;
                cout << "Formato: e1 e2 s1 s2" << endl;
                cin >> e1 >> e2 >> s1 >> s2;

                histogramStretching(sourceName, newDestName, e1, e2, s1, s2);

                break;
            }

            default:
                break;
        }
    } while (option != TERMINADOR);
}
