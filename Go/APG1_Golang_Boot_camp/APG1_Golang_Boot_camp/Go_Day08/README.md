# Day 08 - Go Boot camp

## Adventure, Danger and Cocoa

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) \
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) \
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) \
    4.1. [Exercise 00: Arithmetic](#exercise-00-arithmetic)
5. [Chapter V](#chapter-v) \
    5.1. [Exercise 01: Botany](#exercise-01-botany)
6. [Chapter VI](#chapter-vi) \
    6.1. [Exercise 02: Hot Chocolate](#exercise-02-hot-chocolate)


<h2 id="chapter-i" >Chapter I</h2>
<h2 id="general-rules" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id="chapter-ii" >Chapter II</h2>
<h2 id="rules-of-the-day" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`

<h2 id="chapter-iii" >Chapter III</h2>
<h2 id="intro" >Intro</h2>

People tend to say that one of the main differences between Go and C is a pointer safety. That's partially true, and Go will try really hard to not let you shoot yourself in a foot when tangoing with pointers. But we are already far enough in a jungle to be able to play with danger just a bit, don't you think?

<h2 id="chapter-iv" >Chapter IV</h2>
<h3 id="ex00">Exercise 00: Arithmetic</h3>

Here in a jungle you can find some weird creatures that you need to treat in an unusual way. For this task you need to write a function `getElement(arr []int, idx int) (int, error)` that accepts and an index and gives you back the element with this index. Seems easy enough, eh? But here's one condition - you can't use lookup by this index (like `arr[idx]`), the only lookup allowed is a first element (`arr[0]`). You may need to remember some C to complete this exercise.

In case of any non-valid input (empty slice, negative index, index is out of bounds) the function should return an error with a text explanation of a problem.

<h2 id="chapter-v" >Chapter V</h2>
<h3 id="ex01">Exercise 01: Botany</h3>

You're in luck! You've found some pretty rare plants:

```
type UnknownPlant struct {
    FlowerType  string
    LeafType    string
    Color       int `color_scheme:"rgb"`
}

type AnotherUnknownPlant struct {
    FlowerColor int
    LeafType    string
    Height      int `unit:"inches"`
}
```

Well, yeah, current representation is a bit of a mess. Your goal would be to write a single function `describePlant` that will accept any kind of plant (yes, it should work with structures of different types) and then print all fields as key-value pairs, separated by comma (mind the tags), like this:

```
FlowerColor:10
LeafType:lanceolate
Height(unit=inches):15
```

<h2 id="chapter-vi" >Chapter VI</h2>
<h3 id="ex02">Exercise 02: Hot Chocolate</h3>

Okay, now it's time to relax and have some cocoa. Cocoa usually comes in packages (see provided zip archive). You don't need to modify the code in packaged files in any way, the only thing you need to do is write a code (including cocoa files as part of your project) that will create default empty Mac OS GUI window (size 300x200) with title "School 21". It's easier than you think!


