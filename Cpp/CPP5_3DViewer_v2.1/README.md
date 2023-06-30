# 3DViewer v2.1

Implementation of 3DViewer v2.1

The russian version of the task can be found in the repository.


## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
   2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
   3.1. [Part 1](#part-1-3dviewer-v21) \
   3.2. [Part 2](#part-2-bonus-settings) \
   3.3. [Part 3](#part-3-bonus-record) \
   3.4. [Part 4](#part-4-bonus-texturing)


## Chapter I

![3dviewer2.1](misc/images/3DViewer_v2.1.PNG)

*-- Ah, yes. I also remember when we created the first computer-generated image that looked exactly like a real physical Volkswagen Beetle! The hardest part, however, was not making the computer model look realistic, no. Bui's algorithm handled that perfectly. The most complicated thing was to create the model itself.* \
*We were lucky, Ivan's wife, Marsha, had a beautiful white '71 Beetle. And so the four of us faced the challenge: to fully measure every millimeter of this global culture icon of its time and transfer it to the computer. There are no modern scanners, no cameras. And do you know what we used?*

*-- Hard to imagine.*

*-- Regular yardsticks. We marked points and polygons with the yardsticks on the machine itself. Fortunately, the Beetle is symmetrical so we only had to measure the half of it. Since Jim and I were taller, we did the roof, trunk and hood. Bui and Raphael were in charge of the lower parts of the car. It was a long and painstaking process. Oh, and can you believe, Marsha's been driving around with our markings the whole time?*

*-- That's funny.*

*-- It is. But even after so much trouble, when we transferred the points to the computer and combined the different parts of the machine, there were still some inconsistencies, gaps, and errors. Well, you'd expect that when you work with a simple yardstick on such a complex object.*

*-- So it also took a while to put everything together on the computer?*

*-- A few months, actually. It even turned out that creating an image of the Beetle was more expensive than the car itself. But...*

To continue watching the video, you need to watch a 5-minute ad. Continue?

## Introduction

In this project you’ll need to modify the application developed in the 3D Viewer v2.0 project. The new version should render a three-dimensional object not only in a wireframe form, but also with surface shading.


## Chapter II

## Information

### Historical background

In 1960, William Fetter, an engineer at Boeing who designs airplanes, first coined the term "computer graphics" to refer to his work in technical documentation. His work consisted of creating graphic images using a computer, and already in 1964 William created the first well-known frame model of a person, which was later used in television commercials in the 70s.

Henri Gouraud in 1971, Jim Blinn in 1972, and Bui Tuong Phong in 1973 developed models for shading the flat faces of a wireframe model - polygons. These algorithms have made it possible to go beyond wireframe representations of three-dimensional objects to a more realistic rendering of "solid objects". (solid modeling).  However, these approaches have naturally led to new challenges that require solutions. The main problem was the removal of hidden surfaces when projecting a 3D scene onto the screen plane.
Shaded objects in most cases are not transparent, so the edges of polygonal models should be shaded according to their visibility relative to the viewpoint. This means that when rendering a three-dimensional model, hidden polygons should not be eventually visible. The problem is not so trivial, and there have been plenty solutions proposed for it. We can highlight two main approaches that use different concept:

- *Z-buffer*, an approach first described in 1974 by Wolfgang Strasser, the main idea of which is to buffer the depth of each pixel.

- *Ray casting*, first described in 1982, inspired by the actual process of image synthesis in the human eye and using the concept of rays.

### Visualization of "solids"

The simplified solids imaging pipelines include two steps:

- Obtaining two-dimensional polygon projections of a three-dimensional object.

- Shading of intensities pixel by pixel according to visible or non-overlapping object polygons.

Besides intensity, the surface of each object can also have a whole set of visual properties that require additional calculations. For example, textures that can be overlaid on the surface of an object according to its UV-mapping.


## Chapter III

## Part 1. 3DViewer v2.1

Develop a program to visualize the 3D model.

- The program must be developed in C++ language of C++17 standard
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- The program must be built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests. Installation directory could be arbitrary, except the building one
- The program should be developed according to the principles of object-oriented programming; the structured programming approach is not allowed
- Prepare full coverage of modules related to model loading and affine transformations with unit-tests
- There should be only one model on the screen at a time
- The program must provide the ability to:
    - Load a model from an obj file (vertices, surfaces and normal list support).
    - Translate the model by a given distance in relation to the X, Y, Z axes.
    - Rotate the model by a given angle in relation to its X, Y, Z axes.
    - Scale the model by a given value.
    - Toggle the type of object display: wireframe model, flat shading and smooth shading (by Gouraud or Phong methods)
    - Set the light source, its base intensity (via the three components: R, G, B) and position.
- GUI implementation, based on any GUI library with API for C++ 
  * For Linux: GTK+, CEF, Qt, JUCE
  * For Mac: GTK+, CEF, Qt, JUCE, SFML, Nanogui, Nngui
  The graphical user interface must contain:
    - A button to select the model file and a field to output its name.
    - A visualization area for the model.
    - Button/buttons and input fields for translating the model.
    - Button/buttons and input fields for rotating the model.
    - Button/buttons and input fields for scaling the model.
    - Information about the uploaded model - file name, number of vertices and edges.
- The program must correctly processes and allows user to view models with details up to 100, 1000, 10,000, 100,000, 1,000,000  vertices without freezing (a freeze is an interface inactivity of more than 0.5 seconds)
- The program must be implemented using the MVC pattern, and also:
    - there should be no business code in the view code
    - there should be no interface code in the controller and the model
    - controllers must be thin
- There should be at least three different design patterns (e.g. facade, strategy and command)
- Classes must be implemented within the `s21` namespace
- To perform affine transformations, you can use the matrices from the library of the previous s21_matrix+ project

## Part 2. Bonus. Settings

- The program must allow customizing the type of projection (parallel and central)
- The program must allow setting up the type (solid, dashed), color and thickness of the edges, display method (none, circle, square), color and size of the vertices
- The program must allow choosing the background color
- The program must allow selecting the base color of the object
- Settings must be saved between program restarts

## Part 3. Bonus. Record

- The program must allow saving the captured (rendered) images as bmp and jpeg files.
- The program must allow recording small screencasts - the current custom affine transformation of the loaded object into gif-animation (640x480, 10fps, 5s) by a special button
- The program must allow saving a short preview of the model - gif-animation (640x480, 10fps, 5s) with rotation of the object around one axis by a special button.

## Part 4. Bonus. Texturing

- The program must allow applying a texture to an object (texture mapping) that has a UV-map
- When rendering, the polygons of the model must be shaded according to the UV-mapping
- When you load a model with UV-mapping, the "Apply Texture" button should appear, which allows you to select a texture file
- The resolution of a texture file cannot be more than 1024x1024 pixels
- The texture file has a BMP extension
- The texture can only be square, and the coordinates are always normalized to values between 0 and 1
- The texture must not be displayed in the wireframe mode
- After the texture is loaded, the "Unload texture" button should appear in the program interface, which makes the texture unloaded from the program memory and no longer displayed on the model
- Read the UV-map of the model from the obj-file
- The program must allow saving a UV-map of the model over the selected texture into a separate BMP-file; the texture must show the specified color of the model's map

💡 [Tap here](https://forms.yandex.ru/cloud/64181b936938722405a1286e/) **to leave your feedback on the project**. Pedago Team really tries to make your educational experience better.
