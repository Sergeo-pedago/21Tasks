#include "example.h"

S21Matrix::S21Matrix() {
    _rows = 3;
    _cols = 3;
    // that is how memory allocation works in C++
    _p = new double[_rows * _cols]();
}

/* : <attribute_name>(value) syntax helps to automatically fill attributes with 
values */
S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
    _p = new double[_rows * _cols]();
}

S21Matrix::S21Matrix(const S21Matrix& o) : _rows(o._rows), _cols(o._cols) {
    _p = new double[o._rows * o._cols]();
    /* standard cpp function: copies memory of o._rows * o._cols * sizeof(double) 
    from o.p pointer to _p pointer */
    std::memcpy(_p, o._p, o._rows * o._cols * sizeof(double));
}

S21Matrix::S21Matrix(CMatrix&& o) {
    if (_rows * _cols == o._rows * o._cols) {
        std::memcpy(_p, o._p, o._cols * o._rows * sizeof(double));
    } else {
        delete[] m_ptValues;
        _p = new double[o._rows * o._cols]();
        std::memcpy(_p, o._p, o._cols * o._rows * sizeof(double));
    }
    _rows = o._rows;
    _cols = o._cols;
    delete o._p;
    o._rows = 0;
    o._cpls = 0;
}

S21Matrix::~S21Matrix() {
    if (_p) {
        // free
        delete[] _p;
    }
}

S21Matrix::sum_matrix(const S21Matrix& o) {
    // exception throwing example
    if (_rows != o._rows || _cols != o._cols) {
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < _rows + _cols; i++) {
        _p[i] = _p[i] + o._p[i];
    }
}

// operator overload example
S21Matrix S21Matrix::operator+(const S21Matrix& o) {
    // creating result matrix
    S21Matrix res(_rows, _cols);
    res.sum_matrix(o);
    return res;
}

// index operator overload
int& CMatrix::operator()(int row, int col) {
    if (row >= _rows || col >= _cols) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return _p[row * _cols + col];
}
