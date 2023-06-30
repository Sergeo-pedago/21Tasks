#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <iostream>

class S21Matrix {
private:
    // attributes
    int _rows, _cols;                                           // rows and columns attributes
    double **_p;                                                // pointer to the memory where the matrix will be allocated

public:
    S21Matrix();                                                // default constructor
    S21Matrix(int rows, int cols);                              // parameterized constructor
    S21Matrix(const S21Matrix& o);                              // copy cnstructor
    S21Matrix(S21Matrix&& o);                                   // move cnstructor
    ~S21Matrix();                                               // destructor

    // some operators overloads
    S21Matrix& operator=(const S21Matrix& o);                   // assignment operator overload
    int& operator()(int row, int col);                          // index operator overload
    int& operator()(int row, int col) const;
    S21Matrix& operator+=(const S21Matrix& o);                            
    S21Matrix operator+(const S21Matrix& o);
    S21Matrix& operator-=(const S21Matrix& o);
    S21Matrix operator-(const S21Matrix& o);
    
    // some public methods
    bool eq_matrix(const S21Matrix& o);
    void sum_matrix(const S21Matrix& o); 
    void sub_matrix(const S21Matrix& o);
};

#endif
