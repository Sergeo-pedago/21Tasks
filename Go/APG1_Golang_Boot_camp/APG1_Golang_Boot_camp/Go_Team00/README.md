# Team 00 - Go Boot camp

## Randomaliens

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [General rules](#general-rules)
2. [Chapter II](#chapter-ii) \
    2.1. [Rules of the day](#rules-of-the-day)
3. [Chapter III](#chapter-iii) \
    3.1. [Intro](#intro)
4. [Chapter IV](#chapter-iv) \
    4.1. [Task 00: Transmitter](#exercise-00-transmitter)
5. [Chapter V](#chapter-v) \
    5.1. [Task 01: Anomaly Detection](#exercise-01-anomaly-detection)
6. [Chapter VI](#chapter-vi) \
    6.1. [Task 02: Report](#exercise-02-report)
7. [Chapter VII](#chapter-vii) \
    7.1. [Task 03: All Together](#exercise-03-all-together)
8. [Chapter VIII](#chapter-viii) \
    8.1. [Reading](#reading)

<h2 id="chapter-i" >Chapter I</h2>
<h2 id="general-rules" >General rules</h2>

- Your programs should not quit unexpectedly (giving an error on a valid input). If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded.
- If your code is using external dependencies, it should use [Go Modules](https://go.dev/blog/using-go-modules) for managing them

<h2 id="chapter-ii" >Chapter II</h2>
<h2 id="rules-of-the-day" >Rules of the day</h2>

- You should only turn ink `\*.go`, `\*_test.go` files and (in case of external dependencies) `go.mod` + `go.sum`
- Your code for this task should be buildable with just `go build`
- All your tests should be runnable by calling standard `go test ./...`

<h2 id="chapter-iii" >Chapter III</h2>
<h2 id="intro" >Intro</h2>

"We have no idea how to do it!" - Louise was almost desperate. - "The ship keeps changing frequencies!"

It was a second sleepless night in a row for her. All pointed that aliens have been trying to communicate with earthlings, but the main issue was undestanding each other.

Radio on the table suddenly woke up: "Halpern reporting. Our agents have attached an encoding device to the ship. It collects the generated frequencies and can send them in binary over the network."

Louise immediately rushed to the nearest screen, but apparently the device was transmitting only inside an encrypted military network, where nobody from the science crew had access.

A brilliant linguist was a pity to look at. But after a couple of minutes she shook her head, as if driving away some thoughts, and started angrily negotiating with the military over the radio. Simultaneously, her hand was furiously making notes on a piece of paper.

About half an hour after, she wearily sank into a chair and threw the radio on the table. Then looked up at the team.

"Does anyone here know how to do programming?" - she asked. - "These dimwits won't give us access to their device. So we'll have to recreate something similar and then they agreed to put our analyzer into their network. But only if we test it first!"

Two or three hands raised uncertainly.

"Okay, so it uses something called gRPC, whatever that means. Our analyzer should connect to it an receive a stream of frequencies to look at and generate some kind of report in PostgreSQL. They gave me a data format."

She stood up and walked back and forth a little.

"I get that analyzing completely random signal is a tough task. I wish we had more intel."

And then the radio turned on one more time. And the thing Louise heard made her eyes light up with enthusiasm. She glanced at the team and said one more thing in a loud, triumphant whisper:

"I think I know what to do! IT'S NORMALLY DISTRIBUTED!"

<h2 id="chapter-iv" >Chapter IV</h2>
<h3 id="ex00">Task 00: Transmitter</h3>

"So, we have to reimplement this military device's protocol on our own." - Louise said. - "I've already mentioned that it uses gRPC, so let's do that."

She showed a basic schema of data types. Looks like each message consists of just three fields - 'session_id' as a string, 'frequency' as a double and also a current timestamp in UTC.

We don't know much about distribution here, so let's implement it in such way that whenever new client connects [expected value](https://en.wikipedia.org/wiki/Expected_value) and [standard deviation](https://en.wikipedia.org/wiki/Standard_deviation)" are picked at random. For this experiment, let's pick mean from [-10, 10] interval and standard deviation from [0.3, 1.5].

On each new connection server should generate a random UUID (sent as session_id) and new random values for mean and STD. All generated values should be written to a server log (stdout or file). After that it should send a stream of entries with fields explained above, where for each message 'frequency' would be a value picked at random (sampled) from a normal distribution with these standard deviation and expected value.

It is required to describe the schema in a *.proto* file and generate the code itself from it. Also, you shouldn't modify generated code manually, just import it.

<h2 id="chapter-v" >Chapter V</h2>
<h3 id="ex01">Task 01: Anomaly Detection</h3>

"Now to the interesting part! While others are working on gRPC server, let's think of a client. I expect that gRPC client should be handled by the same guys writing the server to test it, so let's focus on a different thing. We need to detect anomalies in a frequency distribution!"

So, you know you're getting a stream of values. With each new incoming entry from a stream your code should be able to approximate mean and STD from the random distribution generated on a server. Of course it's not really possible to predict it looking only on 3-5 values, but after 50-100 it should be precise enough. Keep in mind that mean and STD are generated for each new connection, so you shouldn't restart the client during the process. Also, values shouldn't keep piling up in memory, so you may consider using sync.Pool for easy reuse.

While working on this task, you can temporarily forget about gRPC and test the code by just sending it a sequence of values to stdin.

Your client code should write into a log periodically, how many values are processed so far as well as predicted values of mean and STD.

After some time, when your client decides that the predicted distribution parameters are good enough (feel free to choose this moment by yourself), it should switch automatically into an Anomaly Detection stage. Here there is one more parameter which comes into play - an *STD anomaly coefficient*. So, your client should accept a command-line parameter (let it be '-k') with a float-typed coefficient.

An incoming frequency is considered an anomaly, if it differs from the expected value by more than *k \* STD* to any side (to the left or to the right, as the distribution is symmetric). You can read more about how it works by following links from Chapter 4.

For now you should just write found anomalies into a log.

<h2 id="chapter-vi" >Chapter VI</h2>
<h3 id="ex02">Task 02: Report</h3>

"As general knows nothing about our *sciency gizmo*, let's store all anomalies that we encounter in a database and then he'll be able to look at it through some interface they have" - Louise seems to be a lot more concerned about the data rather than the general.

So, let's learn how to write data entries to PostgreSQL. Usually it is considered a bad practice to just write plain SQL queries in code when dealing with highly secure environments (you can read about SQL Injections by following links from Chapter 4). Let's use an ORM. In case of PostgreSQL there are two most obvious choices (these links are below as well), but you can choose any other. The main idea here is to not have any strings with SQL code in your sources.

You'll have to describe your entry (session_id, frequency and a timestamp) as a structure in Go and then use it together with ORM to map it into database columns.

<h2 id="chapter-vii" >Chapter VII</h2>
<h3 id="ex03">Task 03: All Together</h3>

Okay, so when we have a transmitter, receiver, anomaly detection and ORM, we can plug things into one another and merge them into a full project.

So, if you start a server and a client (PostgreSQL should be already running on your machine), your client will connect to a server and get a stream of entries which it will then:

- First, use for a distribution reconstruction (mean/STD)
- Second, after some time start detecting anomalies based on supplied STD anomaly coefficient (I suggest you pick it big enough for this experiment, so anomalies wouldn't happen too frequently)
- Third, all anomalies should be written into a database in PostgreSQL using ORM

If Louise is right, these anomalies could be the key to a first contact with the aliens. But it is also a pretty direct approach for cases when you need to detect anomalies on a stream of data, which Go can be efficiently used for.

<h2 id="chapter-viii" >Chapter VIII</h2>
<h3 id="reading">Reading</h3>

[Normal distribution](https://en.wikipedia.org/wiki/Normal_distribution)
[68-95-99.7 rule](https://en.wikipedia.org/wiki/68%E2%80%9395%E2%80%9399.7_rule)
[SQL Injections](https://en.wikipedia.org/wiki/SQL_injection)
[go-pg](https://github.com/go-pg/pg)
[GORM](https://gorm.io/index.html)


