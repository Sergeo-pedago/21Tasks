# OOP basics

Object-oriented programming is a programming methodology based on the concept of a program as a set of interacting information objects belonging to specific classes structured in a hierarchical way.

**A class** is a set of some objects that have the same defined properties and methods performed on them.

**An object** is a specific instance of a class.

Almost any part of the real world can be represented by some set of formalised objects describing that part from the perspective of the programmer. This approach of application development is called object-oriented. The place you are currently in is also some object of the class "place". If this place is considered as part of an application that provides reference information on various city establishments, it is sufficient to associate with a given object only the properties corresponding to the address and some type of establishment, range of provided services, etc.
If this place is considered as part of a 2D planar map drawing application, then some different properties will be required, such as geoposition and dimensions. If you need to visualise the place in three dimensions, you will need a list of quite precise descriptions of the visual characteristics of the objects in the place, their position and size in relation to each other, lighting sources, etc. So, the same object of the real or abstract world can be represented or modelled in completely different ways at the programming level, keeping only the necessary properties. This set of properties is what mostly defines the classes themselves.

Main principals of the OOP:

- Abstraction: the selection of that few characteristics of an object that sufficiently define it in terms of the program that is being developed.

- Encapsulation: hiding an implementation within a class and providing an external interface to interact with it.

- Inheritance: the hierarchical generation of new classes based on an existing class, fully or partially reusing the implementation of the parent class.

- Polymorphism: the ability for different classes implementing the same interface to have different implementations.

Based on the principle of abstraction, object-oriented programming leads to a more "natural" decomposition and separation of abstractions. For example, a matrix. In the structured approach, you need to define the matrix structure `struct matrix` and all the necessary functions to work with it.
The OOP methodology, on the other hand, solves this problem differently: it creates a new object class, a matrix, with which some fields and functions, called methods, are associated. With this approach, all the characteristics of a matrix are encapsulated in some implementation of the class and can be used through the matrix object itself while it exists in the program.

# Exception handling

The way exceptions are handled in the OOP is also different. In structured programming, the key strategy for handling exceptions was the return of the function error codes. They gradually floated to the main function, which for the most part had to consist of error handlers in the form of conditional statements of varying nesting.
The OOP, however, offers to use an exception system. Exception is a special class that can be " thrown" when an error occurs in a program.
The thrown exception will automatically terminate the execution of the current method and start "floating" the call stack until it is in the same scope as the special try-catch block.

For example, we have the following code:

```cpp
#include <iostream>
#include <exception>
 
// division funtion
double divide(double x, double y)
{
    // check division by zero
    if (y == 0)
        // throw standard exception object
        // this will be thrown only if y == 0
        // divide function stops here if y == 0 and returns nothing, but exception
        throw std::exception();
    // perform division
    return x / y;
}
 
int main()
{
    // try block
    // it tries the operation and immediately jumps to the catch block if any exception occurs
    try
    {
        // trying division by zero
        double result = divide(1, 0);
        // this will never happen because y == 0
        std::cout << result << std::endl;
    }
    // catch block
    catch (const std::exception& err)
    {
        // some exception handling here...
    }
    return 0;
}
```

It is possible to create custom classes from the base exception class in order to distinguish between exception types or to pass additional information along with the exception object. To do this, you can create your own exception class and inherit it from `std::exception`.

# Class structure

In C++, classes look like structures:

```cpp
class <class name> 
{
  <access modifier>:
      <attribute or method>
};
```

However, instead of fields, there are attributes defined as simple variables. You can also define methods within a class - functions that have access to all attributes of the class. Methods and attributes are inextricably linked to the class. Access modifiers (public, protected and private) govern external access to class methods and attributes: private attributes and methods are only accessible from within the class, while public ones are accessible from any external function or other class. Private attributes allow you to hide the implementation of internal fields from the user and provide secure public methods of access (accessor) and modification (mutator). Usually, to access the private attribute `x`, the public methods `getX()` - accessor and `setX()` - mutator are defined.

For direct access to attributes or methods, a syntax similar to the one for accessing the fields of a structure is used.
For example, `myObject.myArgument` will return the value of `myArgument` attribute from the object `myObject`, and `myObject.myMethod()` will execute `myMethod()` of `myObject`.
If a pointer to an object is used, a similar pointer to structure syntax is used for addressing arguments and methods.  For example, `myObjectPointer->myMethod()` will call the `myMethod()` of the object pointed to by `myObjectPointer`.

A class can also have defined special methods, called constructors and destructors that are called automatically when an object of that class is created or deleted. They are used to select and fill the required fields or, alternatively, to empty them.

In order to declare a constructor, you need to specify a method with a class name without a return value type, for example:

```cpp
Matrix();
```

The destructor is declared in a similar way, but starts with a tilde:

```cpp
~Matrix();
```

C++ allows you to create multiple constructors for the same class with different sets of arguments. When creating objects of a given class, either the constructor corresponding to the passed arguments or, if no arguments have been passed, the default constructor will be called:

```cpp
Matrix();               // default constructor
Matrix(int n);          // constructor with one argument, e.g. it creates a square matrix of size n by n
Matrix(int n, int m);   // constructor with two arguments, e.g. it creates a matrix of size n by m
```

Calling these constructors in the program code:

```cpp
int n = 4, m = 5;
Matrix m1;               // default constructor 
Matrix m2(n);            // constructor with one argument, e.g. it creates a square matrix of size n by n
Matrix m3(n, m);        // constructor with two arguments, e.g. it creates a matrix of size n by m

```

Do not try to re-call the constructor method as a regular method of the created object. Constructors are only used to create a new object.

Use `new` to create a pointer to an object:

```cpp
Matrix* pM = new Matrix(4,5);
```

Note that brackets with passed arguments are now placed after the class name, not the variable. To manually delete an object pointed to by `pM` you can use `delete`:

```cpp
delete pM;              // here the destructor ~Matrix() is automatically called 
```

If the object was not created via new, but by simple declaration, the destructor will be called when it leaves the scope in which the variable was created:

```cpp
int main() {
    Matrix m(4);

    // Some operations on the matrix, function and method calls...

    return 0;           // here the destructor is automatically called 
}
```

Besides the default constructor (a constructor with an empty set of input parameters), there are two special constructors: the copy constructor and the move constructor. The copy constructor is for initialising an object by copying all the attributes of another object of the same class into the new object. As an argument, it contains a reference to the object being copied. The move constructor looks very similar to the copy one, but it is expected to clear the attributes of the moved object. As a parameter, it contains a double reference to the object being moved. The move constructor is usually executed in cases where the moved object will soon be destroyed. For details, see the example in the `code-samples'. The copy and move constructors look as follows:

```cpp
Matrix (Matrix&);       // copy constructor
Matrix (Matrix&&);      // move constructor
```

In C++, as in C, apart from the usual code files (.cpp/.cc) there are also header files (.h ). Remember that the code from header files is automatically copied into the source code at the preprocessing stage whenever the compiler encounters the `#include` directive.
Like before, header files are used to declare names to which other parts of the code will refer. In concept of the object-oriented paradigm, in the most common cases a header file declares a class and its methods. The header file must not contain the implementation of the class methods or any separate functions.

In contrast to C, the namespace definition is also related to C++. The namespace is an area within which various identifiers (names of types, functions, variables, etc.) associated with each other are defined. Namespaces are used to logically combine code into a subject group and avoid conflicts of identical names with different contextual meaning. It is much easier to understand this with an example. For instance, in some vast program it was required to describe two different classes for trees: one class describes some botanical characteristics of trees as plants, and another one is a hierarchical representation of a family tree. It is quite clear that you can come up with different names for these classes, but it is not necessary. We can see from the context that the classes refer to different entities and implement different logics. Two different namespaces can be created, for example, `Botany` and `Family`, which could potentially include a huge number of other different classes associated with these concepts. This would look like this:

```cpp
namespace Botany
{
    class Tree
    {
        // a class representing a tree as a plant
    }
}
```

```cpp
namespace Family
{
    class Tree
    {
        // a class representing a family tree
    }
}
```

Now it is enough to use the following syntax to refer to these classes outside the corresponding namespace `<Namespace name>::<name>`. For example, to refer to a family tree, we get `Family::Tree`. Namespaces can have a complex hierarchical structure, i.e. some of the namespaces may be defined within others and then, when referenced, they must be listed in the nesting order. To avoid writing the namespace name every time in cases when conflicts are not worth worrying about, you can use the `using` keyword.

# Overloading

Overloading is the ability to create several **different** functions and methods with the same name, but with different arguments and return value types. You may need to do this if you want to create a universal function. For example, we want to create a function for adding two numbers. Its prototype could be the following function:

```cpp
int sum(int a, int b);
```

In C, you had to create separate implementations of functions for different types, for example:

```c
int sum_integer(int a, int b);
double sum_double(double a, double b);
```

But in C++ it is possible to overload functions, i.e. to define different functions with the same name:

```cpp
int sum(int a, int b);              // will be called if two values of int type are passed
double sum(double a, double b)    // will be called if two values of double type are passed
```

It is also possible to define a `sum` function for more parameters:

```cpp
int sum(int a, int b, int c);        // will be called if three values of int type are passed
```

# Operator overloading

Object-oriented programming has also made operator overloading possible. Any standard operator (binary or unary) can be defined for any new class. For example, multiplication. There is a need to define an object multiplication by a matrix, not through the `mult(Matrix, Matrix)` function, but through the `*` operator. It is a binary operator whose left and right parts are represented by matrices:

```cpp
Matrix operator*(Matrix& x);
``` 

Multiplication of a matrix by a number can also be defined through the same operator, but in a method with a different signature, e.g:

```cpp
Matrix operator*(double x);
``` 

Warning! This method will only work if the matrix is multiplied by a number (in that order). This is because any binary operator in C++ is exposed as an operator between the first and the second operand, and the implementation of the operator that is declared with the first operand is executed. A variable of the double type "doesn't know" how multiplication by a matrix is done. This can be solved as follows. Use an operator with two arguments, but define it **outside the class**. Then the arguments will be treated as corresponding operands. In that case, you will have to make two copies of the overloaded operator with a different order of arguments, e.g:

```cpp
Matrix operator*(double, Matrix&);
Matrix operator*(Matrix&, double);
```

To associate these functions with the Matrix class, simply define the specified operators as **friendly** already **inside the class** as follows:

```cpp
friend Matrix operator*(double, Matrix&);
friend Matrix operator*(Matrix&, double);
```

When overloading operators, it is always worth remembering the following rules:

- You cannot overload operators that do not exist in C++.

- You cannot overload operators if none of the operands involved is a user type variable;

- When operators are overloaded, the priority set in C++ for that operation remains and cannot be affected;

- You cannot change the number of operands provided by the operator.

So, that’s what the operator overloading is: using several different implementations of an operator depending on the given signature. 

# The rule of five

`The rule of five` says that in general, if there is a need to independently determine one of the operations of copying, moving or destroying an object, then most likely for correct operation it will be necessary to implement:

- Destructor
- Copy Constructor
- Copy assignment operator
- Move constructor
- Move assignment operator

Example of the rule of five:

```
#include <cstring>

class RFive
{
private:
    char* cstring;

public:
    // Constructor with initialization list and body
    RFive(const char* arg)
    : cstring(new char[std::strlen(arg)+1])
    {
        std::strcpy(cstring, arg);
    }

    // Destructor
    ~RFive()
    {
        delete[] cstring;
    }

    // Copy Constructor
    RFive(const RFive& other)
    {
        cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(cstring, other.cstring);
    }

    // Move Constructor, noexcept - for optimization when using standard containers
    RFive(RFive&& other) noexcept 
    {
        cstring = other.cstring;
        other.cstring = nullptr;
    }

    // Copy assignment operator
    RFive& operator=(const RFive& other) 
    {
        if (this == &other)
            return *this;

        char* tmp_cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(tmp_cstring, other.cstring);
        delete[] cstring;
        cstring = tmp_cstring;
        return *this;
    }

    // Move assignment operator
    RFive& operator=(RFive&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete[] cstring;
        cstring = other.cstring;
        other.cstring = nullptr;
        return *this;
    }

//  You can also replace both assignment operators with the following operator
//  RFive& operator=(RFive other)
//  {
//      std::swap(cstring, other.cstring);
//      return *this;
//  }
};
```
