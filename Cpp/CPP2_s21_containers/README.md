# s21_containers

Implementation of the s21_containers.h. library.

The russian version of the task can be found in the repository.


## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
   2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
   3.1. [Part 1](#part-1-implementation-of-the-s21_containersh-library)  
   3.2. [Part 2](#part-2-bonus-implementation-of-the-s21_containersplush-library)  
   3.3. [Part 3](#part-3-bonus-implementation-of-the-insert_many-method)


## Chapter I

![s21_containers](misc/images/s21_containers.png)

Planet Earth, USA, California, somewhere among the massive containers of the Port of Oakland, 29 October 1993.

*- Do you really think Bjarne will agree to add this to the standard?*

*-- Sure. Especially since he was already interested in templates a couple of years ago, but then they couldn't get enough reliability of the developing library.* - said a middle-aged man wearing a white shirt and an HP Labs nametag that said "A. Stepanov".

*- I saw your presentation on generalized programming. The idea is really impressive, but they wanted to release the new standard by the end of the year. This one will need a lot of adjustments...*

*-- I think that's exactly what they were missing to fully complete the new standard. Especially, as you said, the idea is impressive. However, it needs some adjustments, indeed. To be fully confident in the success of the presentation, we need to provide some examples of how to use the approach and the templates in general. You are familiar with the structure of singly linked lists, right?*

*- Yeah, I think I'm starting to get your idea. You want to implement generalized lists as an example? One template class for all types?*

*-- Not only that. Imagine if any container could be described once and then used with different data types and classes. How much time, effort and resources it would save! Lists, maps, sets!"* - the walk along the Embarcadero promenade was clearly getting more interesting.

*- Queues and stacks... Damn, that's genius.*

*-- Exactly. Who, after such examples, would refuse to add a library to their language standard?*

*- I'm in. We could even put together a small team of guys who are interested. How much time do we have to implement these examples?*

*-- About two weeks before the presentation meeting in San Jose, then..*

### Introduction

As part of the project you need to write your own library that implements the basic standard C++ container classes: `list`, `map`, `queue`, `set`, `stack` and `vector`. Implementations should provide a full set of standard methods and attributes for element handling, container capacity checking and iteration. As a bonus, you can also implement several other container classes from the C++ container library that are not as commonly used, but differ in their implementation details.


## Chapter II

### Information

For most people, the word «container» is self-explanatory and comes from the English word: contain. Same in programming: containers are used to contain sets of objects of the same type i.e elements. However, there are a huge number of container classes. This is because container classes differ in the organisation of stored object sets and in the methods provided to interact with them. So, for example, lists (`list`) store any object, while sets (`set`) store only some unique objects.

The very need to separate containers, rather than using the same one for different tasks, stems not only from obvious functional differences. In some cases, it is more efficient to use lists, e.g. when the task at hand requires frequent insertion of elements in the middle of the container, but when adding new elements at the end only, it is better to use a queue.

Each type of containers should provide the user with the following methods:

- standard constructors (default constructor, copy constructor, move constructor, constructor with initialization list, see materials);

- methods for accessing container elements (e.g. accessing an element with the index i);

- methods for checking if a container is full (e.g. the number of elements in the container, check if the container is empty);

- methods for changing the container (removing and adding new elements, cleaning the container);

- methods for dealing with the container iterator.

Iterators provide an access to container elements. The specific type of iterator will be different for each container. This is because of the different kind of object set organisation in container classes, as well as the actual implementation of the container. Iterators are implemented to work in a similar way that a pointer to an array element in C does. So, this approach with iterators allows interaction with any containers in the same way. Containers provide iterators via the `begin()` and `end()` methods, which point to the first and next after the last elements of the container respectively.

Iterator `iter` has the following operations:

- `*iter`: gets the element pointed to by the iterator;

- `++iter`: moves the iterator forward to the next element

- `--iter`: moves the iterator backwards to the previous element;

- `iter1 == iter2`: two iterators are equal if they point to the same element

- `iter1 != iter2`: two iterators are not equal if they point to different elements

Besides the special organisation of objects and the provision of necessary methods, the implementation of container classes requires the templating of objects.

Template classes or class templates are used when you want to create a class that depends on additional external parameters, which can be other classes or data types. For example, if you need to create a list class, you’ll want to avoid rewriting the list implementation for all possible element types. It would be nice to write one class with a parameter and get several specific list classes at once (character, integer, floating-point, user-defined types lists, etc.).
In C++, containers, along with iterators and some algorithms, are part of the Standard Template Library (STL) for this very reason.

There are two main types of containers: sequence and associative containers. To find an element in sequence containers (`list`, `vector`, `array`, `stack`, `queue`), you have to look through the container one by one, while in associative containers (`map`, `set`, `multiset`) you just need to look through the key associated with the value.


## Chapter III

- The program must be developed in C++ language of C++17 standard using gcc compiler
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- Make sure to use iterators
- Classes must be template
- Classes must be implemented within the `s21` namespace
- Prepare full coverage of container classes methods with unit-tests using the GTest library
- Copying of the Standard Template Library (STL) implementation is not allowed
- The logic of the Standard Template Library (STL) must be followed (in terms of checks, memory handling and behaviour in abnormal situations)

### Part 1. Implementation of the s21_containers.h library

You need to implement the `s21_containers.h` library classes (specifications are given in the relevant material sections, see **"Main containers"**). \
List of classes: `list`, `map`, `queue`, `set`, `stack`, `vector`.
- Make it as a header file `s21_containers.h` which includes different header files with implementations of the specified containers (`s21_list.h`, `s21_map.h` and etc.) 
- Provide a Makefile for testing the library (with targets clean, test)
- The classical implementation of containers should be considered as a basis, but the final choice of implementations remains free. Except for the list - it should be implemented via the list structure rather than the array

*Tip*: You can move the same implementation of container methods to base classes. For example, for a queue and a stack, or for a list and a vector. There is a UML diagram of the STL library in materials as *one possible example* of hierarchical construction. However, your implementation does not have to be strictly tied to this UML diagram.

### Part 2. Bonus. Implementation of the s21_containersplus.h library.

You need to implement the `s21_containersplus.h` library functions (see **"Additional containers"** for specifications). \
List of classes to be implemented additionally: `array`, `multiset`.
- Make it as a header file `s21_containersplus.h` which includes different header files with implementations of the specified containers (`s21_array.h`, `s21_multiset.h`) 
- Provide a Makefile for testing the library (with targets clean, test)
- The classical implementation of containers should be considered as a basis, but the final choice of the algorithm remains free.

### Part 3. Bonus. Implementation of the `insert_many` method.

You need to complete the classes with the appropriate methods, according to the table:

| Modifiers      | Definition                                      | Containers |
|----------------|-------------------------------------------------| -------------------------------------------|
| `iterator insert_many(const_iterator pos, Args&&... args)`          | inserts new elements into the container directly before `pos`  | List, Vector |
| `void insert_many_back(Args&&... args)`          | appends new elements to the end of the container  | List, Vector, Queue |
| `void insert_many_front(Args&&... args)`          | appends new elements to the top of the container  | List, Stack |
| `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`          | inserts new elements into the container  | Map, Set, Multiset |

Note: the arguments are the already created elements of the appropriate container that should be inserted into this container.

*Tip 1*: notice that each of these methods uses an Args&&... args - Parameter pack construct. This construct allows a variable number of parameters to be passed to a function or method. So, when calling a method defined as `iterator insert_many(const_iterator pos, Args&&... args)`, you can write either `insert_many(pos, arg1, arg2)` or `insert_many(pos, arg1, arg2, arg3)`.

*Tip 2*: remember to test methods for different cases, including boundary ones.

💡 [Tap here](https://forms.yandex.ru/cloud/64181a7dc09c02252de7a4f3/) **to leave your feedback on the project**. Pedago Team really tries to make your educational experience better.
