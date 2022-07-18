/**
  * @file image.h
  * @brief Fichero cabecera para la clase image
  * @authors - Autores
  *             -# Andrés Piqueras Brück
  *             -# José Miguel Feixas Galdeano
  */

#ifndef IMAGE
#define IMAGE

#include <assert.h>
#include <iostream>
#include <cmath>

#define MINVAL 0
#define MAXVAL 255

typedef unsigned char byte;

/**
 * @brief TDA @a image
 * 
 * Una instancia del tipo @a image almacena una matriz de byte,
 * un tipo de dato que almacena un valor entre 0 y 255 y que
 * representa el nivel de gris de cada pixel. También almacena
 * como dos enteros el número de filas y columnas de la imagen.
 * 
 */

class image
{
private:
    /**
     * @page repImage Rep del TDA image.
     * 
     * @section invImage Invatiante de la representación.
     * 
     * Un objeto válido del TDA @a image debe cumplir los
     * siguientes requisitos:
     * - @c rows >= 0.
     * - @c columns >= 0.
     * - @c rows @c columns han de ser de tipo int.
     * - @c img tiene que tener reservada una zona de memoria suficiente.
     * 
     * @section faImage Función de abstracción
     * Un objeto válido del TDA @a image representa una imagen en escala de
     * grises de un tamaño @c rows x @c columns.
     * 
     */
    int rows, columns;
    byte **img;

    // ***** Funciones privadas de la clase ***+*
    /**
     * @brief Reserva memoria para albergar una matriz de @c rows x @c columns.
     * 
     * @param rows Número de filas a reservar.
     * @param columns Número de columnas a reservar.
     * 
     * @pre @c rows y @c columns deben de ser mayores o iguales a cero.
     * @post La instancia de imagen que invoca a la función queda con una
     * zona de memoria reservada.
     */
    void allocateMem(int rows, int columns);

    /**
     * @brief Libera la memoria que estaba reservada.
     * 
     * @post Tras ejecutarse, la zona de memoria que tenía reservada
     * una instancia del tipo @a image para guardar su matriz de bytes queda
     * liberada.
     * 
     */
    void deleteMem();

    /**
     * @brief Copia @c imgc en la instancia de @a image que invoca a la función.
     * 
     * @param imgc Instancia de @a image que se copiará en otra.
     * 
     * @pre @c imgc tiene que estar inicializado.
     * @post La instancia que llama a la función queda como una copia
     * idéntica de @c imgc, además esta última no se modifica.
     * 
     * @see allocateMem
     */
    void copy(const image& imgc);

    /**
     * @brief Modifica el tamaño de una instancia de @a image.
     * 
     * @param newRows Nuevo número de filas que tendrá la instancia que invoca la función.
     * @param newCols Nuevo número de columnas que tendrá la instancia que invoca la función.
     * 
     * @pre @c newRows y @c newCols tienen que ser mayores o iguales que cero.
     * @post Los elementos que contenía la matriz de bytes no varían, si se ha reducido
     * el tamaño de la imagen esta siemplemente se recorta, si se ha ampliado los píxeles 
     * nuevos tendrán el valor cero.
     * 
     * @see allocateMem
     * 
     */
    void resize(int newRows, int newCols); // Sin terminar TODO or !TODO

public:
    /**
     * @brief Constructor por defecto de una instancia de @a image. 
     * 
     * @post Crea una instancia de @a image con @c rows, @c columns 
     * y @c img igual a 0.
     * 
     */
    image();

    /**
     * @brief Constructor de una instancia de @a image por parámetros.
     * 
     * @param rows Número de filas que tendrá el objeto al crearse.
     * @param columns Número de columnas que tendrá el objeto al crearse.
     * 
     * @pre @c rows y @c columns tienen que ser mayores o iguales que cero.
     * @post Crea una instancia de @a image con las filas y columnas especificadas
     * y con los valores de luminosidad a cero
     * 
     * @see allocateMem
     */
    image(int rows, int columns);

    /**
     * @brief Constructor de copia de una instancia @a image.
     * 
     * @param img 
     * @return image& 
     * @post Crea un objeto @a image igual que el pasado por referencia constante.
     * 
     * @see copy
     */
    image(const image& imgc);

    /**
     * @brief Sobrecarga del operador =. Permite asignar a un objeto @a image
     * los valores de otro.
     * 
     * @param img Objeto de la clase image usada como fuente para el la copia.
     * 
     * @pre Los objetos @a image que se igualan no pueden ser iguales.
     * @post El objeto igualado queda con las mismas @c rows y @c columns que el que está
     * a la izquierda del =. Además, todos los componentes de @c img también quedan iguales.
     * @return image& 
     * 
     * @see deleteMem, copy
     */
    image& operator=(const image &img);

    /**
     * @brief Destruye una instancia @a image. Además, @c rows y @c columns se igualan a 0
     * 
     * @post La instancia @a image queda inutilizable, y se libera la memoria que ocuapaba.
     * @see deleteMem
     */
    ~image();

    /**
     * @brief Getter de @c rows
     * 
     * @return int 
     */
    int getRows() const { return rows; };

    /**
     * @brief Getter de @c colums
     * 
     * @return int 
     */
    int getColumns() const { return columns; };

    /**
     * @brief Devuelve el byte que se encuentre en la fila @c row , columna @c column .
     * 
     * @param row Fila donde se encuentra el píxel del cual se quiere obtener el valor.
     * @param column Columna donde se encuentra el píxel del cual se quiere obtener el valor.
     * 
     * @pre @c row debe ser un entero comprendido entre 0 (incluyéndolo) y @c rows (excluyéndolo)
     * y @c column debe ser un entero comprendido entre 0 (incluyéndolo) y @c columns (excluyéndolo).
     * @post Devuelve el byte @c img[row][column]
     * 
     * @return byte 
     */
    byte getPixel(int row, int column) const;

    /**
     * @brief Setter de un componente de @c img .
     * 
     * @param row Fila donde se encuentra el píxel al cual se le quiere asigna @c pixel
     * @param column Columna donde se encuentra el píxel al cual se le quiere asigna @c pixel
     * @param pixel Intancia del tipo byte que se le asignará.
     * 
     * @post El componente @c img[row][column] es sobreescrito con el valor @c pixel .
     */
    void setPixel(int row, int column, byte pixel);

    /**
     * @brief Añade una nueva columna a la matriz @c img de un objeto @a image inmediatamente
     * después de la columna indicada por @c index
     * 
     * @param index Índice a partir de la cual se añadirá una columna.
     * 
     * @see resize
     */
    void addColumn(int index);

    /**
     * @brief Añade una nueva fila a la matriz @c img de un objeto @a image inmediatamente
     * después de la fila indicada por @c index
     * 
     * @param index Índice a partir de la cual se añadirá una fila.
     * 
     * @see resize
     */
    void addRow(int index);

    /**
     * @brief Realiza la interpolación bilineal de la columna inmediatamente anterior e
     * inmediatamente posterior a la que indica @c index y guarda los valores obtenidos
     * en esta. Al trabajar con enteros, en caso de obtener valores decimales se aproxima
     * al próximo entero superior, es decir, se realiza un redondeo por exceso.
     * 
     * @param index Columna en la cual se guardarán los valores resultantes.
     */
    void bilinearInterpolationColumns(int index);

    /**
     * @brief Realiza la interpolación bilineal de la fila inmediatamente anterior e
     * inmediatamente posterior a la que indica @c index y guarda los valores obtenidos
     * en esta. Al trabajar con enteros, en caso de obtener valores decimales se aproxima
     * al próximo entero superior, es decir, se realiza un redondeo por exceso.
     * 
     * @param index Fila en la cual se guardarán los valores resultantes.
     */
    void bilinearInterpolationRows(int index);

};

#endif
