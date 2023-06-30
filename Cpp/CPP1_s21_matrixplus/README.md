# s21_matrix+

Implementation of the s21_matrix_oop.h library.

The russian version of the task can be found in the repository.


## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1](#part-1-implementation-of-the-s21_matrix_ooph-library-functions)


## Chapter I

![s21_matrix](misc/images/s21_matrix.png)

Planet Earth, USA, Texas, Dallas County, 1705 Matthew Street, 20 September, 2000.

*-- Our CEO has such a wonderful country house! There is everything to make ideas come true. A veranda facing a huge swimming pool on the lawn complete the image of a passionate and intelligent person.*

*- Yes, I agree! I’m so glad we were invited here. To tell you the truth, it makes me feel a bit deja vu, like I’ve seen this place before.*

*-- Oh, that’s weird. Believe me, you definitely won’t find a house like this anywhere else in America!* \
*So, what were we talking about? Oh, right! For several days now, in this vibrant place, id Software's main technical team has been discussing a new technology we would like to introduce in our upcoming game Doom 3. And what creates the most sense of reality in a picture? The play of light and shadows, of course, which now takes too long to compute, putting a lot of strain on the CPU.
John is known for his technological and algorithmic ideas and tricks, which made it possible to achieve crazy breakthroughs in speed and code optimisation.*

*- Yeah, feels like I’ve heard about it before.*

*-- Really? I guess Catharina got to you first.* \
*However, on to the interesting part. John Carmack, our chief technician and the founder of the company, presented a theoretical development that would allow to cast shadows on a scene after going through the entire graphics pipeline, using a depth and a stencil buffers.*

*- Oh, that's really.. intriguing.*

*-- We invited you to this party for a reason. The whole team is working on a new method of building shadows in a scene, and your department, in particular, has been appointed by John to implement a very fast and optimised library of all sorts of matrix transformations on which the entire mathematical logic of the algorithm will be based. Vectors and matrices, transpose and SRT conversions, and many other mathematical objects and operations that are used in computer graphics.*
*For a correct and considered transition to the new method, we need a significant and impressive performance changes, and you will be in charge of it! Please remember that the whole work must be done in a modern OOP style to achieve maximum code quality!*

*- Well, I would be… um… happy to help you.*

*-- Perfect! Who knows, maybe……..*

## Introduction

In this project, you will implement the matrix library that you already know from the **s21_matrix** project, but this time you will be using the object-oriented approach (see materials). The object-oriented approach allows to implement a library for matrices as a separate class whose objects have defined operations, that can be represented both as methods and as standard operators +, -, *, etc.


## Chapter II

## Information

### C++ and C

C++ is a programming language based on the C language for implementing programs using an object-oriented approach. This means that the C++ syntax rules are directly derived from C, and so, most of the C code can be copied into programs with C++ and successfully compiled.
For the most part, C++ only adds new opportunities for the programmer or modifies them rather than removes something, so when it comes to C++, it's easier to talk about the differences (see materials) than the similarities.

### An example of a matrix class in C++
```cpp
class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        void SumMatrix(const S21Matrix& other); 
        // Other methods..
}
```

### A reminder of the matrix basics

Matrix is a rectangular table of numbers arranged in m rows and n columns

```
    1 2 3
A = 4 5 6
    7 8 9
```

```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```

You can get the desired element using indices as follows A[1,1] = 1, where the first index is the row number, the second is the column number.

The order of a matrix is the number of its rows or columns. \
The main diagonal of a square matrix is the diagonal from the upper left to the lower right corner. \

A rectangular matrix (B) is a matrix with the number of rows not equal to the number of columns. \
A square matrix (A) is a matrix with the number of rows equal to the number of columns.

## Matrix operations

There is a brief description of the matrix operations below that need to be implemented in the developing library.
They are similar to the operations you performed earlier in «structured programming», so you can see a more detailed description of them there.
Note that some operations have exceptional situations that require special handling using the exception mechanism.

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Checks matrices for equality with each other |  |
| `void SumMatrix(const S21Matrix& other)` | Adds the second matrix to the current one | different matrix dimensions |
| `void SubMatrix(const S21Matrix& other)` | Subtracts another matrix from the current one | different matrix dimensions |
| `void MulNumber(const double num) ` | Multiplies the current matrix by a number |  |
| `void MulMatrix(const S21Matrix& other)` | Multiplies the current matrix by the second matrix | the number of columns of the first matrix is not equal to the number of rows of the second matrix |
| `S21Matrix Transpose()` | Creates a new transposed matrix from the current one and returns it |  |
| `S21Matrix CalcComplements()` | Calculates the algebraic addition matrix of the current one and returns it | the matrix is not square |
| `double Determinant()` | Calculates and returns the determinant of the current matrix | the matrix is not square |
| `S21Matrix InverseMatrix()` | Calculates and returns the inverse matrix | matrix determinant is 0 |

Apart from those operations, you also need to implement constructors and destructors:

| Method | Description |
| ----------- | ----------- |
| `S21Matrix()` | A basic constructor that initialises a matrix of some predefined dimension |  
| `S21Matrix(int rows, int cols) ` | Parametrized constructor with number of rows and columns |
| `S21Matrix(const S21Matrix& other)` | Copy constructor |
| `S21Matrix(S21Matrix&& other)` | Move constructor |
| `~S21Matrix()` | Destructor |

And you also need to overload the following operators, partly corresponding to the operations above:

| Operator | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `+`      | Addition of two matrices | different matrix dimensions |
| `-`   | Subtraction of one matrix from another | different matrix dimensions |
| `*`  | Matrix multiplication and matrix multiplication by a number | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `==`  | Checks for matrices equality (`EqMatrix`) | |
| `=`  | Assignment of values from one matrix to another one | |
| `+=`  | Addition assignment (`SumMatrix`) | different matrix dimensions |
| `-=`  | Difference assignment (`SubMatrix`) | different matrix dimensions |
| `*=`  | Multiplication assignment (`MulMatrix`/`MulNumber`) | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `(int i, int j)`  | Indexation by matrix elements (row, column) | index is outside the matrix |


## Chapter III

## Part 1. Implementation of the s21_matrix_oop.h library functions

- The program must be developed in C++ language of C++17 standard using gcc compiler
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- Implement the matrix as an `S21Matrix` class
- Use only the `matrix_`, `rows_` and `cols_` fields as private.
- Implement the access to private fields `rows_` and `cols_` via accessor and mutator. If the matrix increases in size, it is filled with zeros. If it decreases in size, the excess is simply discarded.
- Make it as a static library (with s21_matrix_oop.h header file)
- Implement the operations described [above](#matrix-operations)
- Overload the operators according to the table in the chapter [above](#matrix-operations)
- Prepare full coverage of library functions code with unit-tests using the GTest library
- Provide a Makefile for building the library and tests (with targets all, clean, test, s21_matrix_oop.a)


💡 [Tap here](https://forms.yandex.ru/cloud/64181a0deb614624afcee6b5/) **to leave your feedback on the project**. Pedago Team really tries to make your educational experience better.
