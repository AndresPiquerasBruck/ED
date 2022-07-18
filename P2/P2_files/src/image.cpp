#include "image.h"

using namespace std;

void image::allocateMem(int nrows, int ncolumns) {
    img = new byte*[nrows];
    for (int i = 0; i < nrows; ++i)
        img[i] = new byte[ncolumns];
}

void image::deleteMem() {
    for (int i = 0; i < rows; ++i)
        delete [] img[i];
    delete [] img;
}

void image::copy(const image& imgc) {
    allocateMem(imgc.rows, imgc.columns);
    rows = imgc.rows;
    columns = imgc.columns;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            this->img[i][j] = imgc.img[i][j];   
    }
}

void image::resize(int newRows, int newCols) {
    image aux(newRows, newCols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            aux.setPixel(i, j, this->getPixel(i, j));
    }
    *this = aux;
}

image::image() {
    rows = columns = 0;
    img = 0;
}

image::image(int nrows, int ncolumns) {
    assert(nrows >= 0 && ncolumns >= 0);
    this->rows = nrows;
    this->columns = ncolumns;
    allocateMem(nrows, ncolumns);
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncolumns; ++j) 
            img[i][j] = 0;
    }
}

image::image(const image& imgc) {
    copy(imgc);
}

image& image::operator=(const image &img) {
    if (&img != this) {
        deleteMem();
        copy(img);
    }

    return *this;
}

image::~image() {
    deleteMem();
    rows = columns = 0;
}

byte image::getPixel(int row, int column) const {
    assert(0 <= row < rows && 0 <= column < columns);

    return img[row][column];
}

void image::setPixel(int row, int column, byte pixel) {
    img[row][column] = pixel;
}

void image::addColumn(int index) {
    resize(rows, columns+1);

    for (int i = 0; i < rows; ++i) {
        for (int j = columns - 1; j > index; --j) {
            img[i][j] = img[i][j - 1];
        }
    }
}

void image::addRow(int index) {
    resize(rows+1, columns);

    for (int i = rows - 1; i > index; --i) {
        for (int j = 0; j < columns; ++j) {
            img[i][j] = img[i - 1][j];
        }
    }
}

void image::bilinearInterpolationColumns(int index) {
    for (int i = 0; i < rows; ++i)
        img[i][index] = ceil((img[i][index - 1] + img[i][index + 1]) / 2);
}

void image::bilinearInterpolationRows(int index) {
    for (int i = 0; i < columns; ++i)
        img[index][i] = ceil((img[index-1][i] + img[index+1][i]) / 2);
}
