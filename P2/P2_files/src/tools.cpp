#include "tools.h"

using namespace std;

void PGMToImage(unsigned char *source, image& dest) {
    for (int i = 0; i < dest.getRows(); ++i) {
        for (int j = 0; j < dest.getColumns(); ++j)
            dest.setPixel(i, j, source[i * dest.getColumns() + j]);   
    }
}

unsigned char* ImageToPGM(const image& source) {
    unsigned char* PGMImage = new unsigned char[source.getRows() * source.getColumns()];

    for (int i = 0; i < source.getRows(); ++i) {
        for (int j = 0; j < source.getColumns(); ++j)
            PGMImage[i * source.getColumns() + j] = source.getPixel(i, j);
    }

    return PGMImage;
}

unsigned char* getImagePGM(char* source, int& PGMRows, int& PGMColumns) {
    unsigned char* PGMPixelMap = LeerImagenPGM(source, PGMRows, PGMColumns);

    if (!PGMPixelMap){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit(1);
    }

    return PGMPixelMap;
}

void saveImagePGM(const image & image, char* dest) {
    unsigned char* subImgPGM = ImageToPGM(image);
    
    if (EscribirImagenPGM (dest, subImgPGM, image.getRows(), image.getColumns()))
        cout  << "La imagen se guardo en " << dest << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (2);
    }
}

void subImage(char* source, char* dest, int row, int col, int rowSub, int colSub) {
    int newRows, newCols, PGMRows, PGMColumns;
    unsigned char* PGMPixelMap;

    PGMPixelMap = getImagePGM(source, PGMRows, PGMColumns);

    image originalImg(PGMRows, PGMColumns);
    PGMToImage(PGMPixelMap, originalImg);

    newRows = row + rowSub - 1 <= originalImg.getRows() ? rowSub : (rowSub - ((row + rowSub) - originalImg.getRows()));
    newCols = col + colSub - 1 <= originalImg.getColumns() ? colSub : (colSub - ((col + colSub) - originalImg.getColumns()));
    
    image newSubImage(newRows, newCols);

    for (int i = row; i < row + newRows; ++i) {
        for (int j = col; j < col + newCols; ++j)
            newSubImage.setPixel(i-row, j-col, originalImg.getPixel(i, j));  
    }

    saveImagePGM(newSubImage, dest);
}

void zoom(char* source, char* dest, int xUpperL, int yUpperL, int xLowerR, int yLowerR) {
    int rowsZoom, columnsZoom, PGMRows, PGMColumns;
    unsigned char* PGMPixelMap;

    PGMPixelMap = getImagePGM(source, PGMRows, PGMColumns);

    image originalImg(PGMRows, PGMColumns);
    PGMToImage(PGMPixelMap, originalImg);

    rowsZoom = xLowerR - xUpperL + 1;
    columnsZoom = yLowerR - yUpperL + 1;

    image zoomedImage(rowsZoom, columnsZoom);

    for (int i = xUpperL; i <= xLowerR; ++i) {
        for (int j = yUpperL; j <= yLowerR; ++j)
            zoomedImage.setPixel(i - xUpperL, j-yUpperL, originalImg.getPixel(i, j));
    }

    for (int i = 0; i < zoomedImage.getColumns()-1; ++i) {
        if (i % 2 == 0)
            zoomedImage.addColumn(i);
        else
            zoomedImage.bilinearInterpolationColumns(i);
    }

    for (int i = 0; i < zoomedImage.getRows()-1; ++i) {
        if (i % 2 == 0)
            zoomedImage.addRow(i);
        else
            zoomedImage.bilinearInterpolationRows(i);
    }
    
    saveImagePGM(zoomedImage, dest);
}

void histogramStretching(char* source, char* dest, byte e1, byte e2, byte s1, byte s2) {
    int PGMRows, PGMColumns;
    unsigned char* PGMPixelMap;

    PGMPixelMap = getImagePGM(source, PGMRows, PGMColumns);

    image increasedContrastImg(PGMRows, PGMColumns);
    PGMToImage(PGMPixelMap, increasedContrastImg);

    for (int i = 0; i < increasedContrastImg.getRows(); ++i) {
        for (int j = 0; j < increasedContrastImg.getColumns(); ++j) {
            if (increasedContrastImg.getPixel(i, j) < e1)
                increasedContrastImg.setPixel(i, j, round((double) (s1 / s2 * increasedContrastImg.getPixel(i,j))));
            else if (increasedContrastImg.getPixel(i, j) > e2)
                increasedContrastImg.setPixel(i, j, round((double) (s2 + ((MAXVAL - s2) / (MAXVAL - e2) * (increasedContrastImg.getPixel(i,j) - e2)))));
            else
                increasedContrastImg.setPixel(i, j, round((double) (s1 + ((s2 - s1) / (e2 - e1) * (increasedContrastImg.getPixel(i,j) - e1)))));
        } 
    }

    saveImagePGM(increasedContrastImg, dest);
}
