--------------- Day 00 - Go Boot camp ---------------

## Statistics being handy

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Anscombe](#exercise-00-anscombe)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your program should accept a sequence of numbers separated by newlines to its standard input. One number is also a sequence.
- You may assume it should only work with integers (the output can be floats though, rounded to 2 decimal places).
- Nevertheless it should print a meaningful error message without runtime panic if fed some unexpected input, say, number out of bounds, letter characters or empty string.
- Your code for this task should be buildable with just `go build`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

Go isn't generally considered a language of Data Science. But it doesn't mean that it can't crunch
numbers. In fact, it's comparable to C on basic tasks. Besides, it can be a lot easier to write, 
partially because GC handles memory management and also Go's standard library is pretty good.
We're constantly taught that it can be a bad idea to just trust the gut when dealing with 
important data. To make heads or tails of a sample of numbers it's usually better to use
statistical approach. Data sometimes be can be deceptive, too, like, for example,
[Anscombe's quartet](https://en.wikipedia.org/wiki/Anscombe%27s_quartet), but the more metrics
we get - the more weighted decision we will able to make at the end, isn't it?


<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Anscombe</h3>


So, let's say we have a bunch of integer numbers, strictly between -100000 and 100000. It may 
probably be a large set, so let's assume our application will read it from a standard input, 
separated by newlines. Right now let's think of four major statistical metrics that we can derive
from this data, so by default we can print all of them as a result, for example, like this:

```
Mean: 8.2
Median: 9.0
Mode: 3
SD: 4.35
```

The order and actual format doesn't really matter as long as we can understand which is which. 
A couple of notes, though:

1) Input data may or may not be sorted. You don't need to write your own sorting algorithm,
luckily, Go already has one in standard library and it works for integers.
2) Median is a middle number of a sorted sequence if its size is odd, and an average between
two middle ones if their count is even.
3) Mode is a number which is occurring most frequently, and if there are several, the smallest one
among those is returned. You may think of using some structure for storing number counts, and some
Go standard container may help.
4) You can use both population and regular standard deviation, whichever you prefer.
5) Calling someone \"average\" can be mean.

It will also make sense for user to be able to choose specifically, which of these four parameters
to print, so need to implement this as well. By default it's all of them, but there should be 
a way to specify whether print just one, two or three specific metrics out of four when running
the program (without recompilation). There is a built-in module in standard library that allows you 
to parse additional parameters.







--------------- Day 01 - Go Boot camp ---------------

## Comparing Incomparable

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Reading](#exercise-00-reading)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Assessing Damage](#exercise-01-assessing-damage)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Afterparty](#exercise-02-afterparty)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

There are many popular data formats in the world of programming and Go in particular. But it's highly likely that you'll meet one of these to on the way - XML or JSON. 
Lots and lots of APIs are using JSON and/or XML to encode structured data.

And...sometimes even bakeries use them to store recipes. So the old famous bakery in Villariba was always using good old XML to store the list of cake recipes. If we take a look at the piece of that database, it looks kinda like this:

```xml
<recipes>
    <cake>
        <name>Red Velvet Strawberry Cake</name>
        <stovetime>40 min</stovetime>
        <ingredients>
            <item>
                <itemname>Flour</itemname>
                <itemcount>3</itemcount>
                <itemunit>cups</itemunit>
            </item>
            <item>
                <itemname>Vanilla extract</itemname>
                <itemcount>1.5</itemcount>
                <itemunit>tablespoons</itemunit>
            </item>
            <item>
                <itemname>Strawberries</itemname>
                <itemcount>7</itemcount>
                <itemunit></itemunit> <!-- itemunit may be empty  -->
            </item>
            <item>
                <itemname>Cinnamon</itemname>
                <itemcount>1</itemcount>
                <itemunit>pieces</itemunit>
            </item>
            <!-- Here can be more ingredients  -->
        </ingredients>
    </cake>
    <cake>
        <name>Blueberry Muffin Cake</name>
        <stovetime>30 min</stovetime>
        <ingredients>
            <item>
                <itemname>Baking powder</itemname>
                <itemcount>3</itemcount>
                <itemunit>teaspoons</itemunit>
            </item>
            <item>
                <itemname>Brown sugar</itemname>
                <itemcount>0.5</itemcount>
                <itemunit>cup</itemunit>
            </item>
            <item>
                <itemname>Blueberries</itemname>
                <itemcount>1</itemcount>
                <itemunit>cup</itemunit>
            </item>
            <!-- Here can be more ingredients  -->
        </ingredients>
    </cake>
    <!-- Here can be more cakes  -->
</recipes>
```

Life was great and simple until the owner of the bakery found out that in the next village, Villabajo, now lives a filthy impostor that managed to steal his recipes! To get away with his trickery, he even used a different data format to store it and hide from justice!

```json
{
  \"cake\": [
    {
      \"name\": \"Red Velvet Strawberry Cake\",
      \"time\": \"45 min\",
      \"ingredients\": [
        {
          \"ingredient_name\": \"Flour\",
          \"ingredient_count\": \"2\",
          \"ingredient_unit\": \"mugs\"
        },
        {
          \"ingredient_name\": \"Strawberries\",
          \"ingredient_count\": \"8\"  // ingredient_unit is not even here!
        },
        {
          \"ingredient_name\": \"Coffee Beans\",
          \"ingredient_count\": \"2.5\",
          \"ingredient_unit\": \"tablespoons\"
        },
        {
          \"ingredient_name\": \"Cinnamon\",
          \"ingredient_count\": \"1\"
        }
      ]
    },
    {
      \"name\": \"Moonshine Muffin\",
      \"time\": \"30 min\",
      \"ingredients\": [
        {
          \"ingredient_name\": \"Brown sugar\",
          \"ingredient_count\": \"1\",
          \"ingredient_unit\": \"mug\"
        },
        {
          \"ingredient_name\": \"Blueberries\",
          \"ingredient_count\": \"1\",
          \"ingredient_unit\": \"mug\"
        }
      ]
    }
  ]
}
```

He couldn't help but notice that not only the thief stole his recipes, but he also changed some of them. Some ingredients were missing, counts changed, units renamed. So, he prepared for revenge!


<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Reading</h3>

First things first, he had to learn how to read the database. The owner already had a CLI, so he decided that reading the file should be straightforward, so both these should work (files can be distinguished by an extension, for simplicity):

`~$ ./readDB -f original_database.xml`
`~$ ./readDB -f stolen_database.json`

Not only that, he also decided that reading both files shouldn't be that difficult to do through the same interface, which he called `DBReader`. That means, reading different formats means that we have different *implementations* of the same interface `DBReader`, which should spit out the same object types as a result, whether it's reading from the original database or the stolen one. Right, his idea is to choose the appropriate implementation based on a file extension.

So, you'll need to help him with that. Think of which kinds of objects are there in these databases and how they can be represented in code. Then, write an interface `DBReader` and two implementations of it - one for reading JSON and one for reading XML. Both of them should return the object of the same type as a result.

To check that his idea works, make the code print JSON version of the database when it's reading from XML and vice versa. Both XML and JSON fields should be indented with 4 spaces (\"pretty-printing\").

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Assessing Damage</h3>

Okay, so now the owner decided to compare the databases. You've seen that the stolen database has modified versions of the same recipes, meaning there are several possible cases:

1) New cake is added or old one removed
2) Cooking time is different for the same cake
3) New ingredient is added or removed for the same cake. *Important:* the order of ingredients doesn't matter. Only the names are.
4) The count of units for the same ingredient has changed.
5) The unit itself for measuring the ingredient has changed.
6) Ingredient unit is missing or added

Quickly looking through the database, the owner also noticed that nobody bothered renaming the cakes or the ingredients (possibly, only added some new ones), so you may assume names are the same across both databases.

Your application should be runnable like this:

`~$ ./compareDB --old original_database.xml --new stolen_database.json`

It should work with both formats (JSON and XML) for original AND new database, reusing the code from Exercise 00.

The output should look like this (the same cases explained above):

```
ADDED cake \"Moonshine Muffin\"
REMOVED cake \"Blueberry Muffin Cake\"
CHANGED cooking time for cake \"Red Velvet Strawberry Cake\" - \"45 min\" instead of \"40 min\"
ADDED ingredient \"Coffee beans\" for cake  \"Red Velvet Strawberry Cake\"
REMOVED ingredient \"Vanilla extract\" for cake  \"Red Velvet Strawberry Cake\"
CHANGED unit for ingredient \"Flour\" for cake  \"Red Velvet Strawberry Cake\" - \"mugs\" instead of \"cups\"
CHANGED unit count for ingredient \"Strawberries\" for cake  \"Red Velvet Strawberry Cake\" - \"8\" instead of \"7\"
REMOVED unit \"pieces\" for ingredient \"Cinnamon\" for cake  \"Red Velvet Strawberry Cake\"
```

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Afterparty</h3>

Digging through the database, the Villariba bakery owner suddenly realized - this guy is brilliant! Some recipes were improved a lot comparing to the old version, and these new ideas were really creative! He rushed into Villabajo and found the guy who, as he first thought, stole his most precious legacy.

...The same evening in the tavern two old bakers were hugging, drinking and laughing so hard that it was heard in both villages. They became best friends during the last couple of hours, and each of them was really happy to finally find the person who could blabber all night about cakes! Also turns out, the guy did't steal the database, he was just trying to guess by the taste and tried to improvise around a bit.

After this whole mess they both agreed to use your code, but asked you to do one last task for them. They were quite impressed by how you've managed to do the comparison between the databases, so they've also asked you to do the same thing with their server filesystem backups, so neither bakery would run into any technical issues in the future.

So, your program should take two filesystem dumps.

`~$ ./compareFS --old snapshot1.txt --new snapshot2.txt`

They are both plain text files, unsorted, and each of them includes a filepath on every like, like this:

```
/etc/stove/config.xml
/Users/baker/recipes/database.xml
/Users/baker/recipes/database_version3.yaml
/var/log/orders.log
/Users/baker/pokemon.avi
```

Your tool should output the very similar thing to a previous code (without CHANGED case though):

```
ADDED /etc/systemd/system/very_important/stash_location.jpg
REMOVED /var/log/browser_history.txt
```

There is one issue though - the files can be really big, so you can assume both of them won't fit into RAM on the same time. There are two possible ways to overcome this - either to compress the file in memory somehow, or just read one of them and then avoid reading the other. **Side note:** this is actually a very popular interview question.







--------------- Day 02 - Go Boot camp ---------------

## Not Invented Here Syndrome

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Finding Things](#exercise-00-finding-things)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Counting Things](#exercise-01-counting-things)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Running Things](#exercise-02-running-things)
7. [Chapter VII](#chapter-vii) 
    
    7.1. [Exercise 03: Archiving Things](#exercise-03-archiving-things)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

It's really amazing how much you can do just using command line utilities! Pretty much any OS, including embedded ones, has its own CLI and a set of small programs to do magical things. As an example, you can read about [BusyBox](https://en.wikipedia.org/wiki/BusyBox), which is basically a swiss army knife for a variety of systems, starting with Linux-powered routers on OpenWRT and going to Android phones.

We're not trying to reinvent the wheel here, but knowing how to work with FS and perform basic CLI things in Golang can be really helpful, so let's spend some time on this.

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Finding Things</h3>

As a first step, let's implement `find`-like utility using Go. It has to accept some path and a set of command-line options to be able to locate different types of entries. We are interested in three types of entries, which are directories, regular files and symbolic links. So, we should be able to run our program like this:

```
# Finding all files/directories/symlinks recursively in directory /foo
~$ ./myFind /foo
/foo/bar
/foo/bar/baz
/foo/bar/baz/deep/directory
/foo/bar/test.txt
/foo/bar/buzz -> /foo/bar/baz
/foo/bar/broken_sl -> [broken]
```

or specifying `-sl`, `-d` or `-f` to print only symlinks, only directories or only files. Keep in mind that user should be able to specify one, two or all three of them explicitly, like `./myFind -f -sl /path/to/dir` or `./myFind -d /path/to/other/dir`.

You should also implement one more option - `-ext` (works ONLY when -f is specified) for user to be able to print only files with a certain extension. An extension in this task can be thought of the last part of filename if we split it by a dot. So,

```
# Finding only *.go files ignoring all the rest.
~$ ./myFind -f -ext 'go' /go
/go/src/github.com/mycoolproject/main.go
/go/src/github.com/mycoolproject/magic.go
```

You'll also need to resolve symlinks. So, if `/foo/bar/buzz` is a symlink pointing to some other place in FS, like `/foo/bar/baz`, print both paths separated by `->`, like in example above. 

Another thing about symlinks is that they may be broken (pointing to a non-existing file node). In this case your code should print `[broken]` instead of the path of a symlink destination.

Files and directories that current user doesn't have access to (permission errors) should be skipped in output and not lead to a runtime error.

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Counting Things</h3>

Now we are able to find our files, but we might need more meta information about what is in those files. Let's implement a `wc`-like utility to gather basic statistics about our files.

First things first, let's assume our files are utf-8 encoded text files, so your code should work with texts in Russian, too (forget about special cases like Arabic for now, only English and Russian are required). Also, you may ignore punctuation and just consider spaces as the only word delimiters.

You'll need to implement three mutually exclusive (only one can be specified at a time, otherwise an error message is printed) flags for your code: `-l` for counting lines, `-m` for counting characters and `-w` for counting words. Your program should be runnable like this:

```
# Counting words in file input.txt
~$ ./myWc -w input.txt
777 input.txt
# Counting lines in files input2.txt and input3.txt
~$ ./myWc -l input2.txt input3.txt
42 input2.txt
53 input3.txt
# Counting characters in files input4.txt, input5.txt and input6.txt
~$ ./myWc -m input4.txt input5.txt input6.txt
1337 input4.txt
2664 input5.txt
3991 input6.txt
```

As you may see, the answer is always a calculated number and a filename separated by tab (`\	`). If no flags are specified, `-w` behaviour should be used.

**Important**: as all files are independent, you should utilize goroutines to process them concurrently. You can start as many goroutines as there are input files specified for the program.

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Running Things</h3>

Do you know what `xargs` is? You can read about it [here](https://shapeshed.com/unix-xargs/), for example. Let's implement a similar tool - in this exercise you'll need to write a utility that will:

1) treat all parameters as a command, like 'wc -l' or 'ls -la'
2) build a command by appending all lines that are fed to program's stdin as this command's arguments, then execute it. So if we run

```
~$ echo -e \"/a\
/b\
/c\" | ./myXargs ls -la
```

it should be an equivalent to running

```
~$ ls -la /a /b /c
```

You can test this tool together with those from previous Exercises, so

```
~$ ./myFind -f -ext 'log' /path/to/some/logs | ./myXargs ./myWc -l
```

will calculate line counts for all \".log\" files in `/path/to/some/logs` directory recursively.

<h2 id=\"chapter-vii\" >Chapter VII</h2>
<h3 id=\"ex03\">Exercise 03: Archiving Things</h3>

The last tool that we'll implement for this day is log rotation tool. \"Log rotation\" is a process when the old log file is archived and put away for storage so logs wouldn't pile up in a single file indefinitely. It should work like this:

```
# Will create file /path/to/logs/some_application_1600785299.tag.gz
# where 1600785299 is a UNIX timestamp made from `some_application.log`'s [MTIME](https://linuxize.com/post/linux-touch-command/)
~$ ./myRotate /path/to/logs/some_application.log
```

```
# Will create two tar.gz files with timestamps (one for every log) 
# and put them into /data/archive directory
~$ ./myRotate -a /data/archive /path/to/logs/some_application.log /path/to/logs/other_application.log
```

As in Exercise 01, you should use goroutines to parallelize archiving of several files simultaneously.







--------------- Day 03 - Go Boot camp ---------------

## Tasty Discoveries

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Loading Data](#exercise-00-loading-data)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Simplest Interface](#exercise-01-simplest-interface)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Proper API](#exercise-02-proper-api)
7. [Chapter VII](#chapter-vii) 
    
    7.1. [Exercise 03: Closest Restaurants](#exercise-03-closest-restaurants)
8. [Chapter VIII](#chapter-viii) 
    
    8.1. [Exercise 04: JWT](#exercise-04-jwt)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- All inputs ('page'/'lat'/'long') should be thouroughly validated and never cause HTTP 500 (only HTTP 400/401 is acceptable, with a meaningful error message, as explained in EX02)

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

People tend to love some recommending apps. It helps to avoid thinking too much about what to buy, where to go and what to eat.

Also, pretty much everyone has a phone with a geolocation. How often did you try finding some restaurants in your area for dinner?

Let's think a bit about how these services work and build one of our own, really simple one, shall we?

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Loading Data</h3>

There are lots and lots of various databases on the market. But, because we're trying to provide the ability to search for things, let's use [Elasticsearch](https://www.elastic.co/downloads/elasticsearch). All examples provided have been tested on version 7.9.2.

Elasticsearch is a full text search engine built on top of [Lucene](https://en.wikipedia.org/wiki/Apache_Lucene). It provides an HTTP API that we will be using in this task.

Our provided dataset of restaurants (taken from an Open Data portal) consists of more than 13 thousands of restaurants in the area of Moscow, Russia (you can put together another similar dataset for any other location you want). Every entry has:

- ID
- Name
- Address
- Phone
- Longitude
- Latitude

Before uploading all entries into the database, let's create an index and a mapping (explicitly specifying data types). Without it Elasticsearch will try to guess field types based on documents provided, and sometimes it won't recognize geopoints.

Here are a couple links to help you get started on things:
- https://www.elastic.co/guide/en/elasticsearch/reference/7.9/indices-create-index.html
- https://www.elastic.co/guide/en/elasticsearch/reference/7.9/geo-point.html

Start the database by running `~$ /path/to/elasticsearch/dir/bin/elasticsearch` and let's experiment around.

For simplicity, let's use \"places\" as a name for an index and \"place\" as a name for an entry. You can create an index using cURL like this:

```
~$ curl -XPUT \"http://localhost:9200/places\"
```

but in this task you should use Go Elasticsearch bindings to do the same thing. Next thing you have to do is to provide type mappings for our data. With cURL it will look like this:

```
~$ curl -XPUT http://localhost:9200/places/place/_mapping?include_type_name=true -H \"Content-Type: application/json\" -d @\"schema.json\"
```

where `schema.json` looks like this:

```
{
  \"properties\": {
    \"name\": {
        \"type\":  \"text\"
    },
    \"address\": {
        \"type\":  \"text\"
    },
    \"phone\": {
        \"type\":  \"text\"
    },
    \"location\": {
      \"type\": \"geo_point\"
    }
  }
}
```

Once again, provided cURL commands are just a reference for self-testing, this action should be performed by the Go program you write.

Now you have a dataset to upload. You should use [Bulk API](https://www.elastic.co/guide/en/elasticsearch/reference/7.9/docs-bulk.html) to perform that. All existing Elasticsearch bindings provide wrappers for it, for example, [here is a good example](https://github.com/elastic/go-elasticsearch/blob/master/_examples/bulk/indexer.go) for an official client (keep in mind that you'll need to use client v7 for ES version 7.9, not v8). There are also a couple of third-party clients, choose whichever you prefer.

To check yourself, you may use cURL. So,

```
~$ curl -s -XGET \"http://localhost:9200/places\"
```

should give you something like this:

```
{
  \"places\": {
    \"aliases\": {},
    \"mappings\": {
      \"properties\": {
        \"address\": {
          \"type\": \"text\"
        },
        \"id\": {
          \"type\": \"long\"
        },
        \"location\": {
          \"type\": \"geo_point\"
        },
        \"name\": {
          \"type\": \"text\"
        },
        \"phone\": {
          \"type\": \"text\"
        }
      }
    },
    \"settings\": {
      \"index\": {
        \"creation_date\": \"1601810777906\",
        \"number_of_shards\": \"1\",
        \"number_of_replicas\": \"1\",
        \"uuid\": \"4JKa9fgISd6-N130rpNYtQ\",
        \"version\": {
          \"created\": \"7090299\"
        },
        \"provided_name\": \"places\"
      }
    }
  }
}
```

and querying entry by its ID will look like this:

```
~$ curl -s -XGET \"http://localhost:9200/places/place/1\"
```

```
{
  \"_index\": \"places\",
  \"_type\": \"place\",
  \"_id\": \"1\",
  \"_version\": 1,
  \"_seq_no\": 0,
  \"_primary_term\": 1,
  \"found\": true,
  \"_source\": {
    \"id\": 1,
    \"name\": \"SMETANA\",
    \"address\": \"gorod Moskva, ulitsa Egora Abakumova, dom 9\",
    \"phone\": \"(499) 183-14-10\",
    \"location\": {
      \"lat\": 55.879001531303366,
      \"lon\": 37.71456500043604
    }
  }
}
```

Please note, that the entry with ID=1 may be different from the one in dataset if you decided to use goroutines to speed up the process (that's not a requirement in this task though).

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Simplest Interface</h3>

Now let's create an HTML UI for our database. Not much, we just need to render a page with a list of names, addresses and phones so user could see it in a browser.

You should abstract your database behind an interface. To just return the list of entries and be able to [paginate](https://www.elastic.co/guide/en/elasticsearch/reference/current/paginate-search-results.html) through them, this interface is enough:

```
type Store interface {
    // returns a list of items, a total number of hits and (or) an error in case of one
    GetPlaces(limit int, offset int) ([]types.Place, int, error)
}
```

There should be to Elasticsearch-related imports in `main` package, as all database-related stuff should rest in `db` package inside your project, and you should only use this interface above to interact with it.

Your HTTP application should run on port 8888, responding with a list of restaurants and providing a simple pagination over it. So. when querying \"http://127.0.0.1:8888/?page=2\" (mind the 'page' GET param) you should be getting a page like this:

```
<!doctype html>
<html>
<head>
    <meta charset=\"utf-8\">
    <title>Places</title>
    <meta name=\"description\" content=\"\">
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">
</head>

<body>
<h5>Total: 13649</h5>
<ul>
    <li>
        <div>Sushi Wok</div>
        <div>gorod Moskva, prospekt Andropova, dom 30</div>
        <div>(499) 754-44-44</div>
    </li>
    <li>
        <div>Ryba i mjaso na ugljah</div>
        <div>gorod Moskva, prospekt Andropova, dom 35A</div>
        <div>(499) 612-82-69</div>
    </li>
    <li>
        <div>Hleb nasuschnyj</div>
        <div>gorod Moskva, ulitsa Arbat, dom 6/2</div>
        <div>(495) 984-91-82</div>
    </li>
    <li>
        <div>TAJJ MAHAL</div>
        <div>gorod Moskva, ulitsa Arbat, dom 6/2</div>
        <div>(495) 107-91-06</div>
    </li>
    <li>
        <div>Balalaechnaja</div>
        <div>gorod Moskva, ulitsa Arbat, dom 23, stroenie 1</div>
        <div>(905) 752-88-62</div>
    </li>
    <li>
        <div>IL Pizzaiolo</div>
        <div>gorod Moskva, ulitsa Arbat, dom 31</div>
        <div>(495) 933-28-34</div>
    </li>
    <li>
        <div>Bufet pri Astrahanskih banjah</div>
        <div>gorod Moskva, Astrahanskij pereulok, dom 5/9</div>
        <div>(495) 344-11-68</div>
    </li>
    <li>
        <div>MU-MU</div>
        <div>gorod Moskva, Baumanskaja ulitsa, dom 35/1</div>
        <div>(499) 261-33-58</div>
    </li>
    <li>
        <div>Bek tu Blek</div>
        <div>gorod Moskva, Tatarskaja ulitsa, dom 14</div>
        <div>(495) 916-90-55</div>
    </li>
    <li>
        <div>Glav Pirog</div>
        <div>gorod Moskva, Begovaja ulitsa, dom 17, korpus 1</div>
        <div>(926) 554-54-08</div>
    </li>
</ul>
<a href=\"/?page=1\">Previous</a>
<a href=\"/?page=3\">Next</a>
<a href=\"/?page=1364\">Last</a>
</body>
</html>
```

A \"Previous\" link should disappear on page 1 and \"Next\" link should disappear on last page.

IMPORTANT NOTE: You may notice that by default Elasticsearch doesn't allow you to deal with pagination for more than 10000 entries. There are two ways to othercome this - either use a Scroll API (refer to the same link on pagination above) or just raise the limit in index settings specifically for this task. The latter is acceptable for this task, but is not the recommended way to do it in production. The query that will help you to set it is below:

```
~$ curl -XPUT -H \"Content-Type: application/json\" \"http://localhost:9200/places/_settings\" -d '
{
  \"index\" : {
    \"max_result_window\" : 20000
  }
}'
```

Also, in case 'page' param is specified with a wrong value (outside [0..last_page] or not numeric) your page should return HTTP 400 error and plain text with an error description:

```
Invalid 'page' value: 'foo'
```

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Proper API</h3>

In modern world most applications prefer APIs over just plain HTML. So, in this exercise all you have to do is implement another handler which responds with `Content-Type: application/json` and JSON version of the same thing as in Ex01 (example for http://127.0.0.1:8888/api/places?page=3):

```
{
  \"name\": \"Places\",
  \"total\": 13649,
  \"places\": [
    {
      \"id\": 65,
      \"name\": \"AZERBAJDZhAN\",
      \"address\": \"gorod Moskva, ulitsa Dem'jana Bednogo, dom 4\",
      \"phone\": \"(495) 946-34-30\",
      \"location\": {
        \"lat\": 55.769830485601204,
        \"lon\": 37.486914061171504
      }
    },
    {
      \"id\": 69,
      \"name\": \"Vojazh\",
      \"address\": \"gorod Moskva, Beskudnikovskij bul'var, dom 57, korpus 1\",
      \"phone\": \"(499) 485-20-00\",
      \"location\": {
        \"lat\": 55.872553383512496,
        \"lon\": 37.538326789741
      }
    },
    {
      \"id\": 70,
      \"name\": \"GBOU Shkola № 1411 (267)\",
      \"address\": \"gorod Moskva, ulitsa Bestuzhevyh, dom 23\",
      \"phone\": \"(499) 404-15-09\",
      \"location\": {
        \"lat\": 55.87213179130298,
        \"lon\": 37.609625999999984
      }
    },
    {
      \"id\": 71,
      \"name\": \"Zhigulevskoe\",
      \"address\": \"gorod Moskva, Bibirevskaja ulitsa, dom 7, korpus 1\",
      \"phone\": \"(964) 565-61-28\",
      \"location\": {
        \"lat\": 55.88024342230735,
        \"lon\": 37.59308635976602
      }
    },
    {
      \"id\": 75,
      \"name\": \"Hinkal'naja\",
      \"address\": \"gorod Moskva, ulitsa Marshala Birjuzova, dom 16\",
      \"phone\": \"(499) 728-47-01\",
      \"location\": {
        \"lat\": 55.79476126986192,
        \"lon\": 37.491709793339744
      }
    },
    {
      \"id\": 76,
      \"name\": \"ShAURMA ZhI\",
      \"address\": \"gorod Moskva, ulitsa Marshala Birjuzova, dom 19\",
      \"phone\": \"(903) 018-74-64\",
      \"location\": {
        \"lat\": 55.794378830665885,
        \"lon\": 37.49112002224252
      }
    },
    {
      \"id\": 80,
      \"name\": \"Bufet Shkola № 554\",
      \"address\": \"gorod Moskva, Bolotnikovskaja ulitsa, dom 47, korpus 1\",
      \"phone\": \"(929) 623-03-21\",
      \"location\": {
        \"lat\": 55.66186417434049,
        \"lon\": 37.58323602169326
      }
    },
    {
      \"id\": 83,
      \"name\": \"Kafe\",
      \"address\": \"gorod Moskva, 1-j Botkinskij proezd, dom 2/6\",
      \"phone\": \"(495) 945-22-34\",
      \"location\": {
        \"lat\": 55.781141341601696,
        \"lon\": 37.55643137063551
      }
    },
    {
      \"id\": 84,
      \"name\": \"STARYJ BATUM'\",
      \"address\": \"gorod Moskva, ulitsa Akademika Bochvara, dom 7, korpus 1\",
      \"phone\": \"(495) 942-44-85\",
      \"location\": {
        \"lat\": 55.8060307318284,
        \"lon\": 37.461669109923506
      }
    },
    {
      \"id\": 89,
      \"name\": \"Cheburechnaja SSSR\",
      \"address\": \"gorod Moskva, Bol'shaja Bronnaja ulitsa, dom 27/4\",
      \"phone\": \"(495) 694-54-76\",
      \"location\": {
        \"lat\": 55.764134959774346,
        \"lon\": 37.60256453956346
      }
    }
  ],
  \"prev_page\": 2,
  \"next_page\": 4,
  \"last_page\": 1364
}
```

Also, in case 'page' param is specified with a wrong value (outside [0..last_page] or not numeric) your API should respond with a corresponding HTTP 400 error and similar JSON:

```
{
    \"error\": \"Invalid 'page' value: 'foo'\"
}
```

<h2 id=\"chapter-vii\" >Chapter VII</h2>
<h3 id=\"ex03\">Exercise 03: Closest Restaurants</h3>

Now let's implement our main piece of functionality - searching for *three* closest restaurants! In order to do that, you'll have to configure sorting for your query:

```
\"sort\": [
    {
      \"_geo_distance\": {
        \"location\": {
          \"lat\": 55.674,
          \"lon\": 37.666
        },
        \"order\": \"asc\",
        \"unit\": \"km\",
        \"mode\": \"min\",
        \"distance_type\": \"arc\",
        \"ignore_unmapped\": true
      }
    }
]
```

where \"lat\" and \"lon\" are your current coordinates. So, for an URL http://127.0.0.1:8888/api/recommend?lat=55.674&lon=37.666 your application should return JSON like this:

```
{
  \"name\": \"Recommendation\",
  \"places\": [
    {
      \"id\": 30,
      \"name\": \"Ryba i mjaso na ugljah\",
      \"address\": \"gorod Moskva, prospekt Andropova, dom 35A\",
      \"phone\": \"(499) 612-82-69\",
      \"location\": {
        \"lat\": 55.67396575768212,
        \"lon\": 37.66626689310591
      }
    },
    {
      \"id\": 3348,
      \"name\": \"Pizzamento\",
      \"address\": \"gorod Moskva, prospekt Andropova, dom 37\",
      \"phone\": \"(499) 612-33-88\",
      \"location\": {
        \"lat\": 55.673075576456,
        \"lon\": 37.664533747576
      }
    },
    {
      \"id\": 3347,
      \"name\": \"KOFEJNJa «KAPUChINOFF»\",
      \"address\": \"gorod Moskva, prospekt Andropova, dom 37\",
      \"phone\": \"(499) 612-33-88\",
      \"location\": {
        \"lat\": 55.672865251005106,
        \"lon\": 37.6645689561318
      }
    }
  ]
}
```

<h2 id=\"chapter-viii\" >Chapter VIII</h2>
<h3 id=\"ex04\">Exercise 04: JWT</h3>

So, the last (but not least) thing that we have to do is to provide some simple form of authentication. Currently the one of the most popular ways of implementing that for an API is by using [JWT](https://jwt.io/introduction/). Luckily, Go has a pretty good set of tooling to deal with it.

First, you have to implement an API endpoint http://127.0.0.1:8888/api/get_token which sole purpose will be to generate a token and return it, like this (this is an example, your token will likely be different):

```
{
  \"token\": \"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhZG1pbiI6dHJ1ZSwiZXhwIjoxNjAxOTc1ODI5LCJuYW1lIjoiTmlrb2xheSJ9.FqsRe0t9YhvEC3hK1pCWumGvrJgz9k9WvhJgO8HsIa8\"
}
```

Don't forget to set header 'Content-Type: application/json'.

Second, you have to protect your `/api/recommend` endpoint with a JWT middleware, that will check the validity of this token.

So by default when querying this API from the browser it should now fail with an HTTP 401 error, but work when `Authorization: Bearer <token>` header is specified by the client (you may check this using cURL or Postman).

This is a simplest way to provide authentication, no need to go deeper in details for now.







--------------- Day 04 - Go Boot camp ---------------

## Candy!

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Catching the Fortune](#exercise-00-catching-the-fortune)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Law and Order](#exercise-01-law-and-order)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Old Cow](#exercise-02-old-cow)
7. [Chapter VII](#chapter-vii) 
    
    7.1. [Reading](#reading)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- Even though it is required to not modify the C code, you'll still have to comment out `main()` function in it, otherwise the program won't compile (two entry points)

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

Mister Rogers is very sad. He's sitting at your office and mumbles \"My whole business...How am I supposed to make people happy now?\".

The story is as old as the world itself. This new client of yours started a new business selling candy all across this muddy town. At first, everything was perfect - several vending machines, 5 delicious kinds of candy and lines of children begging their parents to buy some for them. And then it was like a thunder, when someone broke into a data center and stole a server responsible for handling candy orders. Not only that, an old developer has gone missing, too! Coincidence? You don't think so.

You pour mister Rogers a glass of good old bourbon and start asking questions trying to get more details.

\"Well, I don't know much. All our vending machines were selling the same set of candy, you know, here they are on the brochure\" - he gives you the piece of colorful paper advertising five new amazing tastes:

```
Cool Eskimo: 10 cents
Apricot Aardvark: 15 cents
Natural Tiger: 17 cents
Dazzling 	Elderberry: 21 cents
Yellow Rambutan: 23 cents
```

\"That's some weird sounding names\" - you say - \"How do people even remember these things?\"
\"Oh, that one's easy\" - said Rogers - \"We've been using abbreviations everywhere, including our source code, so it's CE, AA, NT and so on\"

He sobs.

\"But does this even matter now? My business is ruined anyway, all this is just nonsense now!\"

\"Please focus, mister Rogers\" - you've seen guys behaving like this many times, this place isn't called \"Gopher PI\" for nothing - \"Is there any detail you didn't mention yet?\"

\"You're right! I've almost forgot!\" - he pulls a piece of paper out of the pocket and hands it over. - \"The thief left a note!\"

You look at the text written with marker on one side: \"I can't eat any more candy!\". This doesn't give you much. Then you turn over the sheet and...

\"Okay, mister Rogers. The good news is, I now know for sure it was your ex-employee who stole the server. But not only that! Something tells me I can help you restore your business, too.\"

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Catching the Fortune</h3>

Turns out, the thief used the first piece of paper he had on his desk, and by a happy coincidence it was a specification for a protocol between vending machine and a server. It looked like this:

```yaml
---
swagger: '2.0'
info:
  version: 1.0.0
  title: Candy Server
paths:
  /buy_candy:
    post:
      consumes:
        - application/json
      produces:
        - application/json
      parameters:
        - in: body
          name: order
          description: summary of the candy order
          schema:
            type: object
            required:
              - money
              - candyType
              - candyCount
            properties:
              money:
                description: amount of money put into vending machine
                type: integer
              candyType:
                description: kind of candy
                type: string
              candyCount:
                description: number of candy
                type: integer
      operationId: buyCandy
      responses:
        201:
          description: purchase succesful
          schema:
              type: object
              properties:
                thanks:
                  type: string
                change:
                  type: integer
        400:
          description: some error in input data
          schema:
              type: object
              properties:
                error:
                  type: string
        402:
          description: not enough money
          schema:
              type: object
              properties:
                error:
                  type: string
```

In next hours, mister Rogers told you all the details. In order to recreate the server, you have to use this spec to produce a bunch of Go code which will actually implement the backend part. It's possible to rewrite the whole thing manually, but in this case the thief may get away before you do it, so you have to generate the code ASAP.

Every candy buyer puts in money, chooses which kind of candy to purchase and how many. This data is being sent over to the server via HTTP and JSON and then:

1) If the sum of candy prices (see Chapter 1) is smaller or equal to the amount of money the buyer gave to a machine, the server responds with HTTP 201 and returns a JSON with two fields - \"thanks\" saying \"Thank you!\" and \"change\" being the amount of change the machine has to give back the customer.
2) If the sum is larger that the amount of money provided, the server responds with HTTP 402 and an error message in JSON saying \"You need {amount} more money!\", where {amount} is the difference between the provided and expected.
3) If the client provided a negative candyCount or wrong candyType (remember - all five candy types are encoded by two letters, so it's one of \"CE\", \"AA\", \"NT\", \"DE\" or \"YR\", all other cases are considered non-valid) then the server should respond with 400 and an error inside JSON describing what had gone wrong. You can actually do it in two different ways - it's either write the code manually with these checks or modify the Swagger spec above so it would cover these cases.

Remember - all data from both client and server should be in JSON, so you can test your server like this, for example:

```
curl -XPOST -H \"Content-Type: application/json\" -d '{\"money\": 20, \"candyType\": \"AA\", \"candyCount\": 1}' http://127.0.0.1:3333/buy_candy

{\"change\":5,\"thanks\":\"Thank you!\"}
```

or

```
curl -XPOST -H \"Content-Type: application/json\" -d '{\"money\": 46, \"candyType\": \"YR\", \"candyCount\": 2}' http://127.0.0.1:3333/buy_candy

{\"change\":0,\"thanks\":\"Thank you!\"}
```

Also, you don't need to keep track of stock of different types of candy yourself, just consider this being done by machines themselves. Just validate user input and calculate the change.

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Law and Order</h3>

You lay back and smile feeling something that seemed to be the case well cooked. Mister Rogers seems to relax a little, too. But then his face changes again.

\"I know we've already paid for increased security at our datacenter\" - he said a bit thoughtfully. - \"...but what if this criminal desides to perform some [Man-in-the-middle](https://en.wikipedia.org/wiki/Man-in-the-middle_attack) trickery? My business will be destroyed again! People will lose their jobs abd I'll get bankrupt!\"

\"Easy there, good sir\" - you say with a smirk. - \"I think I've got just what you need here.\"

So, you need to implement a certificate authentication for the server as well as a test client which will be able to query your API using a self-signed certificate and a local security authority to \"verify\" it on both sides.

You already have a server which supports TLS, but it is possible that you'll have to re-generate the code specifying an additional parameter, so it will be using use secure URLs.

Also, you'll need a local \"certificate authority\" to manage certificates. For our task [minica](https://github.com/jsha/minica) seems like a good enough solution. There is a link to a really helpful video in last Chapter if you want to know more details about how Go works with secure connections.

So, because we're talking a full-blown mutual TLS authentication, you'll have to generate two cert/key pairs - one for the server and one for the client. Minica will also generate a CA file called `minica.pem` for you which you'll need to plug into your client somehow (your auto-generated server should already support specifying CA file as well as `key.pem` and `cert.pem` through command line parameters). Also, generating certificate may require you to use a domain instead of an IP address, so in examples below we will use \"candy.tld\". For it to work on a local machine you can put it into '/etc/hosts' file.

Keep in mind, that because you're using a custom local CA you likely won't be able to query your API using cURL, web browser or tool like [Postman](https://www.postman.com/) anymore without tuning.

Your test client should support flags '-k' (accepts two-letter abbreviation for the candy type), '-c' (count of candy to buy) and '-m' (amount of money you \"gave to machine\"). So, the \"buying request\" should look like this:

```
~$ ./candy-client -k AA -c 2 -m 50
Thank you! Your change is 20
```

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Old Cow</h3>

In a few days mister Rogers finally calls you with some great news - the thief was apprehended and immediately confessed! But candy businessman also had a small request.

\"You seem like you really do know your way around machines, don't ya? There is one last thing I'd ask you to do, basically nothing. Our customers prefer something funny instead of just plain 'thank you', so my nephew Patrick wrote a program that generates some weird animal saying things. I think it's written in C, but that's not a problem for you, isn't it? Please don't change the code, Patrick is still improving it!\"

Oh boy. You look through your emails and notice one from mister Rogers with a code attached to it:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int i;
unsigned int argscharcount = 0;

char *ask_cow(char phrase[]) {
  int phrase_len = strlen(phrase);
  char *buf = (char *)malloc(sizeof(char) * (160 + (phrase_len + 2) * 3));
  strcpy(buf, \" \");

  for (i = 0; i < phrase_len + 2; ++i) {
    strcat(buf, \"_\");
  }

  strcat(buf, \"\
< \");
  strcat(buf, phrase);
  strcat(buf, \" \");
  strcat(buf, \">\
 \");

  for (i = 0; i < phrase_len + 2; ++i) {
    strcat(buf, \"-\");
  }
  strcat(buf, \"\
\");
  strcat(buf, \"        
    
       ^__^\
\");
  strcat(buf, \"         
    
      (oo)
    
    _______\
\");
  strcat(buf, \"            (__)
    
           )
    
    /
    
    \
\");
  strcat(buf, \"                ||----w |\
\");
  strcat(buf, \"                ||     ||\
\");
  return buf;
}

int main(int argc, char *argv[]) {
  for (i = 1; i < argc; ++i) {
    argscharcount += (strlen(argv[i]) + 1);
  }
  argscharcount = argscharcount + 1;

  char *phrase = (char *)malloc(sizeof(char) * argscharcount);
  strcpy(phrase, argv[1]);

  for (i = 2; i < argc; ++i) {
    strcat(phrase, \" \");
    strcat(phrase, argv[i]);
  }
  char *cow = ask_cow(phrase);
  printf(\"%s\", cow);
  free(phrase);
  free(cow);
  return 0;
}
```

Looks like you'll have to return an ASCII-powered cow as a text in \"thanks\" field in response. When querying by cURL it will look like this:

```
~$ curl -s --key cert/client/key.pem --cert cert/client/cert.pem --cacert cert/minica.pem -XPOST -H \"Content-Type: application/json\" -d '{\"candyType\": \"NT\", \"candyCount\": 2, \"money\": 34}' \"https://candy.tld:3333/buy_candy\"
{\"change\":0,\"thanks\":\" ____________\
< Thank you! >\
 ------------\
        
    
       ^__^\
         
    
      (oo)
    
    _______\
            (__)
    
           )
    
    /
    
    \
                ||----w |\
                ||     ||\
\"}

```

Apparently, all you need is to reuse this `ask_cow()` C function without rewriting it in your Go code.

\"Sometimes I think I have to drop this detective work and just go work as a Senior Engineer\" - you grumble.

At least you should probably have as much candy as you want in return. Like, for the rest of your life.

<h2 id=\"chapter-vii\" >Chapter VII</h2>
<h3 id=\"reading\">Reading</h3>

[Using the spec](https://goswagger.io/tutorial/custom-server.html)
[Secure connections](https://www.youtube.com/watch?v=kxKLYDLzuHA)
[Original cowsay](https://en.wikipedia.org/wiki/Cowsay)







--------------- Day 05 - Go Boot camp ---------------

## Santa is back in town 

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Toys on a Tree](#exercise-00-toys-on-a-tree)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Decorating](#exercise-01-decorating)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Heap of Presents](#exercise-02-heap-of-presents)
7. [Chapter VII](#chapter-vii) 
    
    7.1. [Exercise 03: Knapsack](#exercise-03-knapsack)
8. [Chapter VIII](#chapter-viii) 
    
    8.1. [Reading](#reading)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

&mdash; I don't know - said Lily. - The only thing I read about this thing ancient dudes called \"Christmas\" is that you are supposed to have, like, a tree, something called \"a garland\", and, finally, a \"heap of presents\", whatever that means.

You move neuralink visor down to your neck.

&mdash; Come on, girl, it's just an urban legend! Why do you think a combination of such basic things should lead to something interesting?

She looked up to the ceiling, dreaming.

&mdash; There used to be this, like, old guy in red hoodie or something... Do you think he was one of the first rebellion hackers? You know, sharing quickhacks with everybody? So if script kiddies were thrilled about freedom and fighting the corpos, they could use their \"presents\" to breach enterprise firewalls?

&mdash; Yeah, seems legit. Urban legends of the underground tend to have this mystical aura, you know. Most likely it was just some bearded open source enthusiast. Crazy as people are nowadays, at least nobody says something like \"he was riding an antigravity sleigh pulled by robo reindeers\". It's more likely that he had a botnet of portable [ELF](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) binaries on enterprise servers collecting secret stuff to give it to people for free.

Lily leaned back on the couch and pulled up a bunch of holograms.

&mdash; Okay, so everyone knows how trees look like - a bunch of 3d graphs without cycles were floating above her head - Which of them do we need?

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Toys on a Tree</h3>

After some time, you two put together a structure for a [Binary tree](https://en.wikipedia.org/wiki/Binary_tree) node:

```go
type TreeNode struct {
    HasToy bool
    Left *TreeNode
    Right *TreeNode
}
```

&mdash; Looks like you are supposed to... \"hang toys\" on trees? - Lily looked a bit confused. - Okay, anyway, let's hope just a boolean value will suffice. But they say it's also wrong to put more toys on one side, should it be uniform?

&mdash; Okay, I get it - you said. - Let's write a function `areToysBalanced` which will receive a pointer to a tree root as an argument. The point is to spit out a true/false boolean value depending on if left subtree has the same amount of toys as the right one. The value on the root itself can be ignored.

So, your function should return `true` for such trees (0/1 represent false/true, equal amount of 1's on both subtrees):

```
    0
   / 
    
  0   1
 / 
    
0   1
```

```
    1
   /  
    
  1     0
 / 
       / 
    
1   0 1   1
```

and `false` for such trees (non-equal amount of 1's on both subtrees):

```
  1
 / 
    
1   0
```

```
  0
 / 
    
1   0
 
       
    
  1   1
```

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Decorating</h3>

&mdash; So, now about this \"garland\"... It is supposed to be \"reeled up\" on a tree.

Lily rotated hologram back and forth, trying to think of something. Then suddenly she lights up with enthusiasm.

&mdash; I get it! Let's do it like this... - she draws something that resembles a 3d snake on top of the tree.

So, now you have to write another function called `unrollGarland()`, which also receives a pointer to a root node. The idea is to go top down, layer by layer, going right on even horisontal layers and going left on every odd. The returned value of this function should be a slice of bools. So, for this tree:

```
    1
   /  
    
  1     0
 / 
       / 
    
1   0 1   1
```

The answer will be [true, true, false, true, true, false, true] (root is true, then on second level we go from left to right, and then on third from right to left, like a zig-zag).

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Heap of Presents</h3>

&mdash; Perfect! I have no idea what those old dudes meant by \"Christmas tree\", but I think we've met the general requirements.

&mdash; So, about those \"presents\"...

&mdash; Presents, right! - Lily raises her elegant finger with a very long purple nail. It was specifically reinforced to fight enemies and (a lot more frequently) to unscrew various devices. - So, let's think of it as a pile. Every such \"present\" may look like this:

```go
type Present struct {
    Value int
    Size int
}
```

&mdash; Hmm, what's \"Value\"?

&mdash; Well, some things you tend to value more than the others, right? So they should be comparable.

&mdash; Okay, and \"Size\" is about how long will it take me to download it, right?

&mdash; Exactly! So, the the coolest things should be on top.

You need to implement a PresentHeap data structure (using built-in library \"container/heap\" is recommended, but is not strictly required). Presents are compared by Value first (most valuable present goes on top of the heap). *Only* in case two presents have an equal Value, the smaller one is considered to be \"cooler\" than the other one (wins in comparison).

Apart from the structure itself, you should implement a function `getNCoolestPresents()`, that, given an unsorted slice of Presents and an integer `n`, will return a sorted slice (desc) of the \"coolest\" ones from the list. It should use the PresentHeap data structure inside and return an error if `n` is larger than the size of the slice or is negative.

So, if we represent each Present by a tuple of two numbers (Value, Size), then for this input:

```
(5, 1)
(4, 5)
(3, 1)
(5, 2)
```

the two \"coolest\" Presents would be [(5, 1), (5, 2)], because the first one has the smaller size of those two with Value = 5.

<h2 id=\"chapter-vii\" >Chapter VII</h2>
<h3 id=\"ex03\">Exercise 03: Knapsack</h3>

&mdash; Wait! - you said. - But how do I know that all these amazing presents won't eat up all the space on my hard drive?

Lily thought for a moment, but then proposed:

&mdash; For this case, let's only download the most valuable presents!

&mdash; But the Heap is using a different ordering and won't help us here...

&mdash; True, true. Anyway, there should be some argument to figure out how to get the most value out of the space you have, right?

...It's been a great winter night in CyberCity. Even though traditions changed a lot in last centuries, you two had a feeling you did everything right. Also, Lily didn't know yet about a cool new portable cyberdeck you've prepared as a gift to her this evening. And you had no idea what's in that small mysterious box on her table.

As a last task, you have to implement a classic dynamic programming algorithm, also known as \"Knapsack Problem\". Input is almost the same, as in the last task - you have a slice of Presents, each with Value and Size, but this time you also have a hard drive with a limited capacity. So, you have to pick only those presents, that fit into that capacity and maximize the resulting value.

Please write a function `grabPresents()`, that receives a slice of Present instances and a capacity of your hard drive. As an output, this function should give out another slice of Presents, which should have a maximum cumulative Value that you can get with such capacity.

<h2 id=\"chapter-viii\" >Chapter VIII</h2>
<h3 id=\"reading\">Reading</h3>

[Binary Tree](https://en.wikipedia.org/wiki/Binary_tree)
[Breadth-First Search](https://en.wikipedia.org/wiki/Breadth-first_search)
[Depth-First Search](https://en.wikipedia.org/wiki/Depth-first_search)
[Recursion in Go](https://www.tutorialspoint.com/go/go_recursion.htm)
[Heap](https://en.wikipedia.org/wiki/Heap_(data_structure))
[Heap implementation in Go](https://golang.org/pkg/container/heap/)
[Knapsack Problem](https://en.wikipedia.org/wiki/Knapsack_problem)
[Multi-Dimensional arrays and slices in Go](https://golangbyexample.com/two-dimensional-array-slice-golang/)







--------------- Day 06 - Go Boot camp ---------------

## Fortress of Solitude

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Amazing Logo](#exercise-00-amazing-logo)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Place for Your Thoughts](#exercise-01-place-for-your-thoughts)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Haters Gonna Hate](#exercise-02-haters-gonna-hate)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- Additional steps, e.g. for creating tables in a database, should be included in *admin_credentials.txt*

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

So - this is it! You've just got superpowers! And, as a new superhero, you definitely need to think about your street cred and overall recognition, don't you think?

Fireballs - check!
Almost indecently tight leotard - check!
Secret base - oh yeah, baby!

Anything else you forgot? Any other shenanigans to perform? OH WAIT~

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Amazing Logo</h3>

The only requirement here is to generate an awesome logo! It should be a 300x300px PNG file named 'amazing_logo.png'. Make it as cool as you can!

Image should appear in the same directory as the launched binary executable after compiling.

NOTE: you shouldn't cheat and download anything from the internet in your code. Just don't rely on any external sources and unleash your fantasy in programming! Also, just plain single color or transparent logo doesn't count!

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Place for Your Thoughts</h3>

Okay, so what else do you need now? A website, of course! It should be a blog where everybody will be able to read your ideas on the world improvement. Here is a list of features it should have:

- Database (you should use PostgreSQL)

- Admin panel (on '/admin' endpoint) where only you can login with just a form for posting new articles (let's forget about editing old ones for now, superheroes don't ever look back)

- Basic markdown support (so it can at least show \"###\" headers and links in generated HTML)

- Pagination (show no more than 3 thoughts on one page for people to not get too much of your awesomeness)

- Application UI should use port 8888

All additional files (images, css, js if you decide to use any of those) should be submitted as a *zip* file to be unpacked in the same directory as binary itself, resulting into something like this:

.
├── css
│   └── main.css
├── images
│   └── my_cat.png
├── js
│   └── scripts.js
└── myblog-binary

Admin credentials for posting access (login and password) and database credentials (database name and user) should be submitted separately as well in a file called *admin_credentials.txt*. If there are additional commands to be run to create tables in a database, put them into the same file.

Main page should include your logo from EX00, links to articles and (optionally) some short preview of their content, as well as pagination (if there are more than 3 articles in a database).

When clicking a link to article, user should get to a page with a rendered markdown text and a single \"Back\" link which brings him/her back to main page.

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Haters Gonna Hate</h3>

Now, when you already have a cool website, let's update it a little and protect ourselves from the villains trying to bring it down! All you need to do is implement rate limiting, so if ther are more than a hundred clients per second trying to access it, they should get a \"429 Too Many Requests\" response. Of course when you're getting more famous we'll raise that limit! It's just for testing for now.








--------------- Day 07 - Go Boot camp ---------------

## Moneybag

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: King's Bounty](#exercise-00-kings-bounty)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Need for Speed](#exercise-01-need-for-speed)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Elder Scrolls](#exercise-02-elder-scrolls)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- All your tests should be runnable by calling standard `go test ./...`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

\"There are several areas where we consider reliability and speed critical. Areas that directly affect people's lives - medicine, aircraft safety, finance. Of course that means that we thoroughly look through every detail of our product before releasing it to the public. Ladies and gentlemen, I present you...the Moneybag!\"

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: King's Bounty</h3>

You keep listening to CEO's voice, but your eyes are looking at the code on your laptop.

Sometimes it seems like people will always use coins to pay for stuff. In laundromats, vending machines or music boxes it is still normal to accept only pieces of metal as payment. But people sometimes hate staying in lines and waiting for someone else collecting coins and putting them in one by one. Why can't people just always use a minimal amount of coins to avoid slowing everyone else down?

This is a pretty well-known problem and your colleague already wrote a code and uploaded it to you for a review:

```
func minCoins(val int, coins []int) []int {
    res := make([]int, 0)
    i := len(coins) - 1
    for i >= 0 {
        for val >= coins[i] {
            val -= coins[i]
            res = append(res, coins[i])
        }
        i -= 1
    }
    return res
}
```

It accepts a necessary amount and a sorted slice of unique denominations of coins. It may be something like [1,5,10,50,100,500,1000] or something exotic, like [1,3,4,7,13,15]. The output is supposed to be a slice of coins of minimal size that can be used to express the value (e.g. for 13 and [1,5,10] it should give you [10,1,1,1]).

The issue is, you have a gut feeling there is something wrong with this code. Your goal here is to write several tests (in `*_test.go` files) for this code, that will show it producing wrong results. Also, you need to write a separate function (you should call it `minCoins2`) which will have the same parameters, but will handle those cases successfully. In case duplicates are present in a slice of denominations or it is not sorted, the function should still give a correct result. In case it is empty, an empty slice should be returned. 

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Need for Speed</h3>

Now as you have new version of code from EX00, let's test it for performance. Your goals here are:

 - get a list of top 10 functions in your code (calling your function with some test data) that your CPU spends the most time executing (you should use Go's builtin tools for that). Submit that list as file `top10.txt`
 
 - write a benchmark version of your tests that will compare the performance of your new code vs. the old one, especially while using relatively big denomination slice. If you find any more optimizations during this phase, feel free to submit newer version of your `minCoins2` function calling it `minCoins2Optimized` (not a required step)

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Elder Scrolls</h3>

Now, as you've fixed the bug and wrote some tests for your code, it's time to generate some documentation for it. Describe in comments in your code how is your solution different from the default one and what optimizations did you use. Then, use any tool that you'll manage to find to generate the HTML documentation based on those comments.

Directions on how to reproduce documentation generation should also be included in comments. Saving HTML pages from the web browser is considered cheating (even though not strictly prohibited, so if you couldn't do it any other way just write it explicitly in the comments).

Submit generated documentation (HTML files + static, like images, js and css) packed into a `docs.zip` archive.








--------------- Day 08 - Go Boot camp ---------------

## Adventure, Danger and Cocoa

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Arithmetic](#exercise-00-arithmetic)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Botany](#exercise-01-botany)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Hot Chocolate](#exercise-02-hot-chocolate)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn in `*.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

People tend to say that one of the main differences between Go and C is a pointer safety. That's partially true, and Go will try really hard to not let you shoot yourself in a foot when tangoing with pointers. But we are already far enough in a jungle to be able to play with danger just a bit, don't you think?

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Arithmetic</h3>

Here in a jungle you can find some weird creatures that you need to treat in an unusual way. For this task you need to write a function `getElement(arr []int, idx int) (int, error)` that accepts and an index and gives you back the element with this index. Seems easy enough, eh? But here's one condition - you can't use lookup by this index (like `arr[idx]`), the only lookup allowed is a first element (`arr[0]`). You may need to remember some C to complete this exercise.

In case of any non-valid input (empty slice, negative index, index is out of bounds) the function should return an error with a text explanation of a problem.

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Botany</h3>

You're in luck! You've found some pretty rare plants:

```
type UnknownPlant struct {
    FlowerType  string
    LeafType    string
    Color       int `color_scheme:\"rgb\"`
}

type AnotherUnknownPlant struct {
    FlowerColor int
    LeafType    string
    Height      int `unit:\"inches\"`
}
```

Well, yeah, current representation is a bit of a mess. Your goal would be to write a single function `describePlant` that will accept any kind of plant (yes, it should work with structures of different types) and then print all fields as key-value pairs, separated by comma (mind the tags), like this:

```
FlowerColor:10
LeafType:lanceolate
Height(unit=inches):15
```

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Hot Chocolate</h3>

Okay, now it's time to relax and have some cocoa. Cocoa usually comes in packages (see provided zip archive). You don't need to modify the code in packaged files in any way, the only thing you need to do is write a code (including cocoa files as part of your project) that will create default empty Mac OS GUI window (size 300x200) with title \"School 21\". It's easier than you think!








--------------- Day 09 - Go Boot camp ---------------

## Daily Routine

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Exercise 00: Sleepsort](#exercise-00-sleepsort)
5. [Chapter V](#chapter-v) 
    
    5.1. [Exercise 01: Spider-Sens](#exercise-01-spider-sense)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Exercise 02: Dr. Octopus](#exercise-02-dr-octopus)


<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn ink `
    *.go`, `
    *_test.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- All your tests should be runnable by calling standard `go test ./...`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

Sometimes we hear that there are some people who \"can do several things in parallel\". Even though that may be theoretically possible to do completely different things (say, with different hands), this phrase usually refers to people handling several tasks at the same time, but NOT in parallel. What do I mean by that?

\"Parallel\" in computer science usually means that progress is made on more than one task at the same time. But with people it is a bit different - the real trick is to keep the context and switch over from one task to another quickly. From the side it may even look like \"parallelism\", but it's not - it is *concurrency*, which is a bit more wide concept. And yes, it means concurrency can be inplemented using parallelism, but it can also work without it (like most people do).

When programming things to run in parallel, we are generally thinking of explicitly creating several separate threads and giving each of them a target function. But it is not how it works in case of Golang - it operates in terms of *concurrency*, which means we don't really need to think if and how actual parallelization is happening under the hood.

That gives us a lot of power, but with great power comes great responsibility...

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Exercise 00: Sleepsort</h3>

So, let's write a toy algorithm as an example. It is pretty much useless for production, but it helps to grasp the concept.

You need to write a function called `sleepSort` that accepts an unsorted slice of integers and returns an integer channel, where these numbers will be written one by one in sorted order. To test it, in main goroutine you should read and print output values from a returned channel and gracefully stop the application in the end.

The idea of Sleepsort (what makes it a \"toy\") is that we're spawning a number of goroutines equal to the size of an input slice. Then, each goroutine sleeps for amount of seconds equal to the received number. After that it wakes up and this number to the output channel. It's easy to notice that this way numbers will be returned in a sorted order.

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Exercise 01: Spider-Sense</h3>

You probably remember how Peter Parker realised he now has superpowers when he woke up in the morning. Well, let's write our own spider (or crawler) for parsing the web. You need to implement a function `crawlWeb` which will accept an input channel (for sending in URLs) and return another channel for crawling results (pointers to web page body as a string). Also, at any moment in time there shouldn't be more than 8 goroutines querying pages in parallel.

But we want to be quick and flexible, so another requirement is to be able to stop the crawling process at any time by pressing Ctrl+C (and your code should perform a graceful shutdown). For that you may add more input arguments to `crawlWeb` function, which should be either `context.Context` for cancellation or `done` channel. If not interrupted, the program should gracefully stop after all given URLs are processed.

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Exercise 02: Dr. Octopus</h3>

Okay, so now we have to slain the villain! The main problem with Dr.Octopus is that he has a lot of tech tentacles, and it's hard to keep track of them all. Let's tie them together!

For this exercise, you need to write a function called `multiplex` which should be *variadic* (accepts a variable number of arguments). It should accept channels (`chan interface{}`) for arguments and return a single channel of the same type. The idea is to redirect any incoming messages from these input channels into just one single output channel, effectively implementing \"fan-in\" pattern.

As a proof of work, you should write a test on sample data which will explicitly show that all values randomly sent to any input channels are received further on the same output channel.

And...you've just defeated a villain!









--------------- Team 00 - Go Boot camp ---------------

## Randomaliens

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Task 00: Transmitter](#exercise-00-transmitter)
5. [Chapter V](#chapter-v) 
    
    5.1. [Task 01: Anomaly Detection](#exercise-01-anomaly-detection)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Task 02: Report](#exercise-02-report)
7. [Chapter VII](#chapter-vii) 
    
    7.1. [Task 03: All Together](#exercise-03-all-together)
8. [Chapter VIII](#chapter-viii) 
    
    8.1. [Reading](#reading)

<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn ink `
    *.go`, `
    *_test.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- All your tests should be runnable by calling standard `go test ./...`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

\"We have no idea how to do it!\" - Louise was almost desperate. - \"The ship keeps changing frequencies!\"

It was a second sleepless night in a row for her. All pointed that aliens have been trying to communicate with earthlings, but the main issue was undestanding each other.

Radio on the table suddenly woke up: \"Halpern reporting. Our agents have attached an encoding device to the ship. It collects the generated frequencies and can send them in binary over the network.\"

Louise immediately rushed to the nearest screen, but apparently the device was transmitting only inside an encrypted military network, where nobody from the science crew had access.

A brilliant linguist was a pity to look at. But after a couple of minutes she shook her head, as if driving away some thoughts, and started angrily negotiating with the military over the radio. Simultaneously, her hand was furiously making notes on a piece of paper.

About half an hour after, she wearily sank into a chair and threw the radio on the table. Then looked up at the team.

\"Does anyone here know how to do programming?\" - she asked. - \"These dimwits won't give us access to their device. So we'll have to recreate something similar and then they agreed to put our analyzer into their network. But only if we test it first!\"

Two or three hands raised uncertainly.

\"Okay, so it uses something called gRPC, whatever that means. Our analyzer should connect to it an receive a stream of frequencies to look at and generate some kind of report in PostgreSQL. They gave me a data format.\"

She stood up and walked back and forth a little.

\"I get that analyzing completely random signal is a tough task. I wish we had more intel.\"

And then the radio turned on one more time. And the thing Louise heard made her eyes light up with enthusiasm. She glanced at the team and said one more thing in a loud, triumphant whisper:

\"I think I know what to do! IT'S NORMALLY DISTRIBUTED!\"

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Task 00: Transmitter</h3>

\"So, we have to reimplement this military device's protocol on our own.\" - Louise said. - \"I've already mentioned that it uses gRPC, so let's do that.\"

She showed a basic schema of data types. Looks like each message consists of just three fields - 'session_id' as a string, 'frequency' as a double and also a current timestamp in UTC.

We don't know much about distribution here, so let's implement it in such way that whenever new client connects [expected value](https://en.wikipedia.org/wiki/Expected_value) and [standard deviation](https://en.wikipedia.org/wiki/Standard_deviation)\" are picked at random. For this experiment, let's pick mean from [-10, 10] interval and standard deviation from [0.3, 1.5].

On each new connection server should generate a random UUID (sent as session_id) and new random values for mean and STD. All generated values should be written to a server log (stdout or file). After that it should send a stream of entries with fields explained above, where for each message 'frequency' would be a value picked at random (sampled) from a normal distribution with these standard deviation and expected value.

It is required to describe the schema in a *.proto* file and generate the code itself from it. Also, you shouldn't modify generated code manually, just import it.

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Task 01: Anomaly Detection</h3>

\"Now to the interesting part! While others are working on gRPC server, let's think of a client. I expect that gRPC client should be handled by the same guys writing the server to test it, so let's focus on a different thing. We need to detect anomalies in a frequency distribution!\"

So, you know you're getting a stream of values. With each new incoming entry from a stream your code should be able to approximate mean and STD from the random distribution generated on a server. Of course it's not really possible to predict it looking only on 3-5 values, but after 50-100 it should be precise enough. Keep in mind that mean and STD are generated for each new connection, so you shouldn't restart the client during the process. Also, values shouldn't keep piling up in memory, so you may consider using sync.Pool for easy reuse.

While working on this task, you can temporarily forget about gRPC and test the code by just sending it a sequence of values to stdin.

Your client code should write into a log periodically, how many values are processed so far as well as predicted values of mean and STD.

After some time, when your client decides that the predicted distribution parameters are good enough (feel free to choose this moment by yourself), it should switch automatically into an Anomaly Detection stage. Here there is one more parameter which comes into play - an *STD anomaly coefficient*. So, your client should accept a command-line parameter (let it be '-k') with a float-typed coefficient.

An incoming frequency is considered an anomaly, if it differs from the expected value by more than *k 
    * STD* to any side (to the left or to the right, as the distribution is symmetric). You can read more about how it works by following links from Chapter 4.

For now you should just write found anomalies into a log.

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Task 02: Report</h3>

\"As general knows nothing about our *sciency gizmo*, let's store all anomalies that we encounter in a database and then he'll be able to look at it through some interface they have\" - Louise seems to be a lot more concerned about the data rather than the general.

So, let's learn how to write data entries to PostgreSQL. Usually it is considered a bad practice to just write plain SQL queries in code when dealing with highly secure environments (you can read about SQL Injections by following links from Chapter 4). Let's use an ORM. In case of PostgreSQL there are two most obvious choices (these links are below as well), but you can choose any other. The main idea here is to not have any strings with SQL code in your sources.

You'll have to describe your entry (session_id, frequency and a timestamp) as a structure in Go and then use it together with ORM to map it into database columns.

<h2 id=\"chapter-vii\" >Chapter VII</h2>
<h3 id=\"ex03\">Task 03: All Together</h3>

Okay, so when we have a transmitter, receiver, anomaly detection and ORM, we can plug things into one another and merge them into a full project.

So, if you start a server and a client (PostgreSQL should be already running on your machine), your client will connect to a server and get a stream of entries which it will then:

- First, use for a distribution reconstruction (mean/STD)
- Second, after some time start detecting anomalies based on supplied STD anomaly coefficient (I suggest you pick it big enough for this experiment, so anomalies wouldn't happen too frequently)
- Third, all anomalies should be written into a database in PostgreSQL using ORM

If Louise is right, these anomalies could be the key to a first contact with the aliens. But it is also a pretty direct approach for cases when you need to detect anomalies on a stream of data, which Go can be efficiently used for.

<h2 id=\"chapter-viii\" >Chapter VIII</h2>
<h3 id=\"reading\">Reading</h3>

[Normal distribution](https://en.wikipedia.org/wiki/Normal_distribution)
[68-95-99.7 rule](https://en.wikipedia.org/wiki/68%E2%80%9395%E2%80%9399.7_rule)
[SQL Injections](https://en.wikipedia.org/wiki/SQL_injection)
[go-pg](https://github.com/go-pg/pg)
[GORM](https://gorm.io/index.html)







--------------- Team 01 - Go Boot camp ---------------

## Warehouse 13

## Contents

1. [Chapter I](#chapter-i) 
    
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) 
    
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) 
    
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) 
    
    4.1. [Task 00: Scalability](#exercise-00-scalability)
5. [Chapter V](#chapter-v) 
    
    5.1. [Task 01: Balancing and Queries](#exercise-01-anomaly-balancing-and-queries)
6. [Chapter VI](#chapter-vi) 
    
    6.1. [Task 02: Long Live the King](#exercise-02-long-live-the-king)
7. [Chapter VII](#chapter-vii) 
    
    7.1. [Task 03: Consensus](#exercise-03-consensus)
8. [Chapter VIII](#chapter-viii) 
    
    8.1. [Reading](#reading)

<h2 id=\"chapter-i\" >Chapter I</h2>
<h2 id=\"general-rules\" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id=\"chapter-ii\" >Chapter II</h2>
<h2 id=\"rules-of-the-day\" >Rules of the day</h2>

- You should only turn ink `
    *.go`, `
    *_test.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- All your tests should be runnable by calling standard `go test ./...`

<h2 id=\"chapter-iii\" >Chapter III</h2>
<h2 id=\"intro\" >Intro</h2>

&mdash; Oh come one, Artie, this is ancient! - Lattimer was about to pull his own hair. - It's a 21st century, nobody uses pen and paper to catalogue stuff anymore!

&mdash; What do you want me to do, Pete? It's been like that since forever!

&mdash; Well, we have a computer, don't we? It's pretty ancient, but we can install...

&mdash; No, we can't! You know that Warehouse has to remain top secret, don't you? We don't download or install any software here.

&mdash; Okay, so you want us to write our own database implementation? Will that work?

&mdash; Hmm, it MAY work...

&mdash; Perfect! So, I'll ask Myka to implement one for us!

&mdash; Wait, I thought you were talking about implementing it yourself...

&mdash; Nah, I'm no good with coding. Anyway, let's design it! What information should we store?

&mdash; Every artifact is assigned its own unique ID and then we have to store some metadata about it in a structured format. Also, everything should be accessible through a command line interface, as I don't get these modern GUIs...

An hour later...

&mdash; What? You want me to write a fully functional key-value storage for working with JSON documents? From scratch?

&mdash; I know, I know! But you're not alone! Here, I've made you some coffee in an Andy Warhol's coffee mug, so it's pretty much and unlimited resource of caffeine superpower. 

&mdash; But, Pete! We have to solve multiple issues! What if the data is corrupted? What if we can't access some artifact data when we need it the most?

&mdash; Don't worry, Myka, you can do it! I'll also sit here and help. Let's just go through the issues one by one.

<h2 id=\"chapter-iv\" >Chapter IV</h2>
<h3 id=\"ex00\">Task 00: Scalability</h3>

After some time, the blackboard was covered in writings.

\"Access through a command line - there should be a separate application that will provide REPL and will connect to a running instance via network, even if it's just local host and port\".

\"We should be able to kill any instance (process) of the database and it should keep running and providing responses to queries. That means, one of the configurable parameters for instance should be a replication factor, meaning how many copies of the same document do we store. For testing purposes 2 is probably enough\"

\"Client should perform heartbeats checking if current database instance is accessible. If it stops responding, it should automatically switch over to another instance\"

\"Also, for simplicity, let's assume for now being scalable means client should be aware of all other nodes. Every heartbeat response from a current node should include all currently known instances' addresses and ports along with current replication factor\"

So, here we need to implement two programs - one being the client and one being an instance of a database. Whenever you are starting a new instance, you should be able to point it to an existing instance, so after receiving a heartbeat it will send over its host and port to all other running nodes, and everybody will know the new guy.

If the instance node is started with a replication factor different from existing nodes, it should detect that and fail automatically without joining the cluster. This means replication factor should probably be included in heartbeat as well.

You can use any network protocol you like for this - HTTP, gRPC, etc.

Whenever replication factor is more than a number of running nodes, information about this problem should be included in a heartbeat and shown in every connected client explicitly. You can see an example of a user session in Task 01.

Actual working with documents will be implemented in next task.

<h2 id=\"chapter-v\" >Chapter V</h2>
<h3 id=\"ex01\">Task 01: Balancing and Queries</h3>

&mdash; Okay, so let's use UUID4 strings as artifact keys. We also need to implement some balancing to provide fault tolerance...

Our simple database should only support three operations - GET, SET and DELETE. 

Here's how a typical session should look like, with comments (starting with #):

```
~$ ./warehouse-cli -H 127.0.0.1 -P 8765
Connected to a database of Warehouse 13 at 127.0.0.1:8765
Known nodes:
127.0.0.1:8765
127.0.0.1:9876
127.0.0.1:8697
> SET 12345 '{\"name\": \"Chapayev's Mustache comb\"}'
Error: Key is not a proper UUID4
> SET 0d5d3807-5fbf-4228-a657-5a091c4e497f '{\"name\": \"Chapayev's Mustache comb\"}'
Created (2 replicas)
> GET 0d5d3807-5fbf-4228-a657-5a091c4e497f
'{\"name\": \"Chapayev's Mustache comb\"}'
> DELETE 0d5d3807-5fbf-4228-a657-5a091c4e497f
Deleted (2 replicas)
> GET 0d5d3807-5fbf-4228-a657-5a091c4e497f
Not found
>
# if current instance is stopped in the background
Reconnected to a database of Warehouse 13 at 127.0.0.1:8697
Known nodes:
127.0.0.1:9876
127.0.0.1:8697
> 
# if another current instance is stopped in the background
Reconnected to a database of Warehouse 13 at 127.0.0.1:9876
Known nodes:
127.0.0.1:9876
WARNING: cluster size (1) is smaller than a replication factor (2)!
>
```

If a key specified in SET already exists in a database the value should be overwritten. If it doesn't, then SET operation should provide read-after-write consistency, meaning immediate reading should give you proper value.

When updating an existing value or deleting it, an eventual consistency should be implemented, meaning immediate (dirty) reads can (but not \"should\"!) give you old results, but after a couple of seconds the data should be updated to a proper new state.

You can implement key-hash-based balancing so your client could explicitly calculate for every entry the list of nodes where it should be stored according to a replication factor. This will also come in handy for deletion.

If a current node is killed during writing, your client should automatically perform another request to another available node. The only case when user should see the error like \"Failed to write/read an entry\" is when ALL instances are dead.

<h2 id=\"chapter-vi\" >Chapter VI</h2>
<h3 id=\"ex02\">Task 02: Long Live the King</h3>

Let's upgrade the logic from Tasks 00/01. Now, we introduce concepts of a Leader and a Follower nodes. This leads us to a list of important changes:

* from now on, client ONLY interacts with a Leader node. The hashing function to determine where to write replicas is now *on Leader*, *not* in client
* all nodes (Leader and Followers) keep sending each other heartbeats with a full list of nodes. If node doesn't respond to heartbeats for some specific configurable timeout (for testing purposes you should set it to 10 seconds by default)
* if the Leader is stopped, remaining Followers should be able to choose a new Leader among them. For simplicity, each of them can just order the list of nodes by some other unique identifier (numeric id, port etc.) and pick the topmost one. From that moment all heartbeats will include a new elected Leader
* if not able to connect to a known Leader, a client should try and connect to Followers to receive a heartbeat from them. If a Leader is killed, this heartbeat will include a new elected Leader

<h2 id=\"chapter-vii\" >Chapter VII</h2>
<h3 id=\"ex03\">Task 03: Consensus</h3>

**NOTE: this task is completely optional. It is only graded as a bonus part**

You may have noticed that a lot of things could go wrong in a schema provided above, specifically race conditions and ability to lose some data due to replicas not being re-synced automatically between instances after some of them die.

You can try and solve that for some extra credit by either using an existing solution or writing some workaround yourself. Here are some options:

* Using existing Raft implementation (https://github.com/hashicorp/raft) or writing minimal implementation by yourself (https://www.youtube.com/watch?v=64Zp3tzNbpE)
* Utilizing external tools, like Zookeeper (https://zookeeper.apache.org/) or Etcd (https://etcd.io/)
* Choosing some other way, like Paxos (https://github.com/kkdai/paxos), some blockchain implementation (like https://tendermint.com/) or your own hacks

...Hopefully, now Pete and Myka won't be looking through a mess of paperwork everytime they need to find something. Probably Artie will do it anyway, because sometimes it's really hard to challenge the force of habit.

But I think it was an interesting journey, during which we've found some cool artifacts on the way. Do you?

<h2 id=\"chapter-viii\" >Chapter VIII</h2>
<h3 id=\"reading\">Reading</h3>

[MIT Distributed Systems - RaftIntro](https://www.youtube.com/watch?v=UzzcUS2OHqo)
[MIT Distributed Systems - Raft1](https://www.youtube.com/watch?v=64Zp3tzNbpE)
[MIT Distributed Systems - Raft2](https://www.youtube.com/watch?v=4r8Mz3MMivY)
