# Design patterns

Design patterns are usually divided into three groups: creational, structural and behavioral patterns. In reality, there are a huge number of different patterns and here are just the main ones that have become established in the developers’ community. They are also called the patterns of Gang of Four.

**Creational patterns** are responsible for creating new objects.

| Name                | Brief description |
|------------------------|----------------------------------------------------------------------------------------|
| Singleton             | Ensures that the class has only one instance, and provides a global access point to it.    |
| Builder                          | Separates the construction of a complex object from its representation, so that the same construction process can result in different representations.    |
| Factory method                       | Provides an interface to create an object, but leaves it up to the subclasses to decide which instances of the class should be created. The factory method allows the class to delegate the creation of instances to subclasses.    |
| Abstract factory             | Provides an interface for creating families of related or dependent objects, without specifying their particular classes.    |
| Prototype                      | Specifies the types of objects to be created using a prototype instance and creates new objects by copying this prototype.    |

**Structural patterns** are responsible for structuring classes and objects.

| Name                | Brief description |
|------------------------|----------------------------------------------------------------------------------------|
| Facade                | Provides a unified interface rather than a set of interfaces of some subsystem. The facade defines a higher-level interface that simplifies the use of the subsystem.            |
| Decorator             | Dynamically adds new responsibilities to an object. A flexible alternative to subclassing for extending functionality.    |
| Adapter                | Turns an interface of one class into another interface that clients require. An adapter allows classes with incompatible interfaces to work together, which would not be possible without it.    |
| Bridge                  | Allows separating abstraction from its implementation so that both can be changed independently.|
| Composite         | Composes objects into tree structures to represent part-whole hierarchies. Allows clients to treat individual and composite objects uniformly. |
| Proxy                                                  | Is a substitute for another object and controls the access to it. |
| Flyweight                               |  Applies sharing for effective support of multiple small objects. |

**Behavioral patterns** are responsible for object communication.

| Name                | Brief description |
|------------------------|----------------------------------------------------------------------------------------|
| State                        | Allows the object to change its behavior depending on its internal state. From the outside it looks like the object's class has changed. |
| Iterator                      | Provides a way to access the elements of an aggregate object sequentially without exposing its internal representation. |
| Visitor                         | Describes the operation performed on each object from some structure. The visitor pattern allows you to define a new operation without changing the classes of these objects.   |
| Strategy                           | Defines a family of algorithms, encapsulates each of them and makes them interchangeable. The strategy pattern allows you to change the algorithms independently from the clients that use them.
| Observer                               | Defines a one-to-many dependency between objects so that when the state of one object changes, all objects that depend on it are notified and updated automatically.
| Command                             | Encapsulates the request as an object, allowing to set parameters for processing the corresponding requests, to queue or log the requests, and to support the cancellation of operations. |
| Chain of responsibility                | Allows you to avoid coupling the sender of a request to its recipient by letting multiple objects handle the request. Binds recipient objects into a chain and passes the request along this chain until it is processed. |
| Mediator                            | A mediator defines an object that encapsulates the way multiple objects interact.  It provides loose coupling by keeping objects from referring to each other explicitly, and allows their interaction to be varied independently.
| Memento                          | Without violating encapsulation, captures and saves internal state of the object externally, so that the object can be restored to this state later.
| Template method                    | A template method defines the basis of an algorithm and allows subclasses to override some steps of the algorithm without changing the structure of the it as a whole. |
| Interpreter                               | Defines a grammar for a given language, as well as an interpreter of the sentences of that language. |
