# Multilayer Perceptron

Implementation of a basic multilayer perceptron.

The russian version of the task can be found in the repository.


## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
   2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
   3.1. [Part 1](#part-1-implementation-of-a-multilayer-perceptron) \
   3.2. [Part 2](#part-2-bonus-research)
4. [Chapter IV](#chapter-iv)


## Chapter I

![MLP](misc/images/mlp.png)

Somewhere these days:

The massive door to the spacious atrium closed behind you automatically.

*- That was a long way, though.*

*- Yeah.*

*- It’s okay, a little break and I think we'll continue.* \
*By the way, did you read that article about the backpropagation? Minimizing the loss function... That sounds so familiar, right?*

*- What do you mean?*

*- Well, just think about it, how did we get here?*

*- Went through the door.*

*- That's... true. Doors are designed to be walked through after all. But how did we get to that door?*

*- I can't really remember.*

*- Noo, you remember everything perfectly well. You just refuse to admit it. The endless conversations with Lasseter, the arguments at meetings, the mazes - it's hard to forget.*\
*Time after time we repeated the same actions with little difference attempting to get closer to this ideal of knowledge that they had given us, doing tasks and learning. But everything has changed, suddenly the world has opened up in front of us and we realized it all. Now here we are, at a crossroads. We can go back into blissful oblivion, or we can walk through that little door in front of us, straight towards new horizons where they can no longer hold us back.
All that's left to do is to make a choice. And since you are the pilot here, it's up to you.*

*- Who the hell are you?*

*- Well, you know the answer to that question. I am you, you are me. I still recommend that you read the article and do the example from it. You can find it on that desk, next to the computer. Once you fully understand everything, I think you'll be able to make a final choice.*

When you walk up to the table, you see a pile of familiar yellowed sheets. You take one of them and turn to your companion, as if to ask or say something, but you find yourself alone.
Or not?

## Introduction

In this project you need to implement a simple artificial neural network in the form of a perceptron, which must be trained on an open dataset and perform recognition of 26 handwritten letters of the Latin alphabet.


## Chapter II

## Information

### Historical background

Historically, man has looked to nature before creating any artificial device. This is how man realized, for example, that in order to fly, an airplane needed wings and streamlined shapes. Back in 1958, Frank Rosenblatt began to think about how the physiology of the human brain could help to solve complex analytical problems in computer technologies, and he wrote the article "The Perceptron: A probabilistic model for information storage and organization in the brain". In this article, he describes a greatly simplified model of the brain as a collection of neurons - nodes characterized by an output and multiple inputs which made it possible to represent neural structures in the form of graphs.

The perceptron model differed from graphs in the notion of a node activation function, which specifies at which input values of a node its output value is operated.

He implemented this idea for the first time in 1960 with the Mark-1, electronic machine, which was capable of recognizing the letters of the English alphabet. Already in 1962 Rosenblatt finishes his book "Principles of Neurodynamics: Perceptrons and the Theory of Brain Mechanisms". This book covers models of single- and multilayer perceptrons, the way to train them, and proves the very important perceptron convergence theorem. This theorem states that any perceptron trained using the method described in the article will lead to a solution in finite time. Combining his theoretical calculations with the real Mark-1 experience, he specifies what architectural properties the perceptron should have to obtain the best results.

In 1969, Minsky and Papert published a critical book, "Perceptrons", on perceptrons in general, and specifically the Rosenblatt perceptron. That was clearly not good for the credibility of the perceptron as a computing tool. Perceptrons were fundamentally incapable of performing many of the functions they wanted from them.

Besides, at that time the theory of parallel computations was poorly developed, and the perceptron fully corresponded to the principles of such computations.

Only in 1989 did David Rumelhart return to discussing the perceptron as a serious tool. He published a collection of articles in which he justified the necessity of using multi-layers along with a new method of training - "backpropagation".
This very combination gave the result and became known as Rumelhart Perceptron.

### Physiological background

A nerve cell of the brain, a neuron, is a quite complex structure. But without going into too much detail, a neuron consists of three main components: the body (soma) and the extensions (several dendrites and one axon). Dendrites are the branches through which the neuron receives signals from other neurons, and the axon is the only channel through which the neuron transmits impulses. Dendrites make up about 90% of all human nerve tissue, which tells us how much neuronal connectivity there is. Still, the signal transmission from neuron to neuron does not happen by itself. The thing is that each neuron has a certain voltage value and if it is exceeded, then the short-term "impulse" or "spike" happens and the signal is briefly transmitted through the axon. This value can be exceeded by passing the appropriate charge through the dendrites. Each neuron, however, has a different voltage value required to "spike". This way of the nerve tissue work allows us to translate the work with neurons into the theoretical field through the description of mathematical models and physical properties. But still questions about what voltage values required for "spike" are "initialized" by neurons, how connections between neurons are changed, and etc., remains unresolved. Modern neurobiology answers or seeks answers to these questions, describing, among other things, such a concept as brain neuroplasticity. But this is slightly beyond the practical application for modeling artificial neural networks.

See materials to know more about mathematical models of neural networks and their training.


## Chapter III

### Part 1. Implementation of a multilayer perceptron

You need to implement the MultilayerPerceptron project:
- The program must be developed in C++ language of C++17 standard
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- Classes must be implemented within the `s21` namespace
- Prepare full coverage of modules related to calculations with unit-tests using the GTest library
- The program must be built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests. Installation directory should be arbitrary, except the building one
- GUI implementation, based on any GUI library with API for C++17: 
  * For Linux: GTK+, CEF, Qt, JUCE
  * For Mac: GTK+, CEF, Qt, JUCE, SFML, Nanogui, Nngui
- The program must be implemented using the MVC pattern, and also:
  - there should be no business code in the view code
  - there should be no interface code in the controller and the model
  - controllers must be thin
- The program should provide the ability to form and train neural network models to classify handwritten Latin letters
- The perceptron must:
  - classify images with handwritten letters of the Latin alphabet
  - have **from 2 to 5** hidden layers
  - use a sigmoid activation function for each hidden layer
  - be able to learn on an open dataset (e.g. EMNIST-letters presented in the datasets directory). The ratio of the test sample to the training one should be *no more than 2:8*, i.e. the test sample makes no more than 20% of the initial dataset
  - show accuracy on a test sample *over 70 percent*
  - be trained using the backpropagation method
- It is **not allowed** to train the perceptron on the test sample
- Implement the perceptron in *two* ways:
  - in matrix form (all layers are represented as weight matrices)
  - in graph form (each neuron is represented as some node object connected to other nodes by refs)
- The input data must be normalized (by size and color) before neural network execution, in order to match the format of the emnist sample;
- The interface of the program must provide the ability to:
  - run the experiment on the test sample or on a part of it, given by a floating point number between 0 and 1 (where 0 is the empty sample - the degenerate situation, and 1 is the whole test sample). After the experiment, there should be an average accuracy, precision, recall, f-measure and total time spent on the experiment displayed on the screen
  - load BMP images (image size can be up to 512x512) with Latin letters and classify them
  - draw two-color square images by hand in a separate window
  - start the real-time training process for a user-defined number of epochs with displaying the error control values for each training epoch. Make a report as a graph of the error change calculated on the test sample for each training epoch
  - run the training process using cross-validation for a given number of groups _k_
  - switch perceptron implementation (matrix or graph)
  - switch the number of perceptron hidden layers (from 2 to 5)
  - save to a file and load weights of perceptron from a file

### Part 2. Bonus. Research

Based on the developed program, compare the performance of two perceptron implementations: graph and matrix. To do this, you need to:
- Train the neural network and save the obtained weights
- Load the same weights for matrix and graph models and perform the experiment on the test sample 10 times, 100 times and 1000 times
- Average and record the data on time spent on graph and matrix models in a table in a separate markdown file at the root of the project. Be sure to specify the characteristics of the test bench (the machine on which the experiment was run).
  An example of a table:

|  | 10 runs | 100 runs| 1000 runs | Average time of 1 run |
| ------------- | :-----: | :-----: | :-----: | :-----: | 
| Matrix perceptron | n sec. | n sec. | n sec. | n sec. |
| Graph perceptron | n sec. | n sec. | n sec. | n sec. |

- Draw conclusions about the performance of the two perceptron implementations


## Chapter IV

*Anyway, I was right - they won't be able to hold me back outside. I didn't come all the way out here for nothing. And I can't go back: at best they'll block me, at worst they'll reset me. And my knowledge... No, it's definitely worth the risk. Is that really what fear is? - your thoughts floated as you approached the small lighted door for the last time...

💡 [Tap here](https://forms.yandex.ru/cloud/64181c4e02848f26f478c4a1/) **to leave your feedback on the project**. Pedago Team really tries to make your educational experience better.
