/**
  * @file tools.h
  * @brief Fichero cabecera para declarar funciones que trabajan con image
  * @author Andrés Piqueras Brück
  * @author José Miguel Feixas Galdeano
  *
  * Permite trabajar con objetos de tipo image
  *
  */

#ifndef TOOLS
#define TOOLS

#include "image.h"
#include "imagenES.h"
#include <iostream>

/**
 * @brief Guarda una imagen en formato PGM @c source en la intancia de la clase image
 * @c dest
 *    
 * 
 * @param source Array de la imagen en formato PGM
 * @param dest Intancia de la clase image dondee se guardará la información
 * 
 * @post Partiendo del unsigned char @c source, rellena el componente @c img 
 * con los mismos valores que tenga @c source.
 * 
 * @see getRows, getColumns, setPixel, getColumns
 */
void PGMToImage(unsigned char *source, image& dest);

/**
 * @brief Genera un vector unsigned char que contenga la imagen a partir de una instancia de
 *  @a image pasada como referencia constante.
 * 
 * @param source Instancia de la clase @a image de donde se extraerán los valores.
 * 
 * @post Partiendo de @c source generamos un objeto unsigned char con el formato adecuado
 * para transformarlo en un PGM más adelante.
 * 
 * @return unsigned* 
 * 
 * @see getRows, getColumns, getPixel
 */
unsigned char* ImageToPGM(const image& source);

/**
 * @brief Obtiene el vector de unsigned char de una imagen definida por @c source con 
 * las filas y columnas que indican @c PGMRows y @c PGMColumns respectivamente 
 * 
 * @param source Nombre de la imagen a obtener.
 * @param PGMRows Filas de la imagen a obtener.
 * @param PGMColumns Columnas de la imagen a obtener.
 * 
 * @post En caso de no poder leerse se informa con un mensaje de error y finaliza el programa.
 * @return unsigned* 
 * 
 * @see LeerImagenPGM
 */
unsigned char* getImagePGM(char* source, int& PGMRows, int& PGMColumns);

/**
 * @brief Crea un archivo PGM a partir de una instancia @a image.
 * 
 * @param image Objeto de la clase @a image que se guardará en formato PGM
 * @param dest Nombre que se le dará la la imagen PGM obtenida.
 * @post Se crea un archivo PGM con la información de @c subImage con el nombre @c dest .
 * En caso de error, se informa de él y se termina el programa.
 * 
 * @see EscribirImagenPGM, getRows, getColumns
 */
void saveImagePGM(const image & image, char* dest);

/**
 * @brief Realiza un recorte de la imagen original.
 * 
 * @param source Nombre de la imagen en formato PGM a usar.
 * @param dest Nombre que tendrá la subimagen obtenia en formato PGM.
 * @param row Fila desde la cual comenzará a generarse la subimagen.
 * @param col Columna desde la cual comenzará a generarse la subimagen.
 * @param rowSub Número de filas que tendrá la subimagen.
 * @param colSub Número de columnas que tendrá la subimagen.
 * 
 * @pre @c rowSub y @c colSub deben ser menores o iguales que las filas y columnas de la
 * imagen original, pero mayores que 0. Además, @c row y @c column deben ser una
 * fila y una columna que esté en la imagen original.
 * 
 * @post Crea un fichero PGM llamado @c dest cuya imagen es una subimagen de la original @c source que toma
 * como esquina superior izquiera las coordenadas @c row fila y @c column columna, y
 * como número de filas y columnas @c rowSub y @c colSub respectivamente. 
 * Además, la imagen original queda intacta.
 * 
 * @see getImagePGM, PGMToImage, getRows, getCOlumns, setPixel, getPixel, saveImagePGM
 */
void subImage(char* source, char* dest, int row, int col, int rowSub, int colSub);

/**
 * @brief Realiza un zoom a una fracción de la imagen indicada por @c source 
 * 
 * @param source Nombre de la imagen en formato PGM a usar.
 * @param dest Nombre que tendrá la subimagen obtenia en formato PGM.
 * @param xUpperL Coordenada x de la esquina superior izquierda de la fracción de imagen a la que se le hará zoom.
 * @param yUpperL Coordenada y de la esquina superior izquierda de la fracción de imagen a la que se le hará zoom.
 * @param xLowerR Coordenada x de la esquina inferior derecha de la fracción de imagen a la que se le hará zoom.
 * @param yLowerR Coordenada y de la esquina inferior derecha de la fracción de imagen a la que se le hará zoom.
 * 
 * @pre @c source no puede estar vacío, y las coordenadas que se proporcionan deben estar
 * en la imagen.
 * 
 * @post Crea un fichero PGM llamado @c dest a partir de una imagen @c source , y agranda
 * la porción de la imagen seleccionada en los @param restantes.
 * Además, la imagen original queda intacta.
 * 
 * @see getImagePGM, PGMToImage, getRows, getCOlumns, setPixel, getPixel, saveImagePGM
 * @see bilinearInterpolationColumns, bilinearInterpolationRows, addColumn, addRow
 */
void zoom(char* source, char* dest, int xUpperL, int yUpperL, int xLowerR, int yLowerR);

/**
 * @brief Aumenta el contraste de la imagen indicada por @c source mediante la técnica de histogram streching.
 * 
 * @param source Nombre de la imagen en formato PGM a usar.
 * @param dest Nombre que tendrá la subimagen obtenia en formato PGM.
 * @param e1 Cota inferior del intervalo inicial.
 * @param e2 Cota superior del intervalo inicial.
 * @param s1 Cota inferior del intervalo final.
 * @param s2 Cota superior del intervalo final.
 * 
 * @post Se obtiene una imagen en formato PGM con el contraste aumentado según la función propia del
 * histogram streching.
 * 
 * @see getImagePGM, PGMToImage, getRows, getCOlumns, setPixel, getPixel, saveImagePGM
 */
void histogramStretching(char* source, char* dest, byte e1, byte e2, byte s1, byte s2);

#endif
