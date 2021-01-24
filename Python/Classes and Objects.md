## Data Types :

Refers to a classification that determines:
• The possible values for that type
• The meaning of those values
• The operations that can be done on them
• The way those values are implemented

> Eg. int, float, string, array, etc.

## Data Structure :

A particular way in which data is physically organised (so that certain operation can be performed efficiently)

> Eg. array, linked nodes.

## Abstract Data Types (ADTs) :

They can be describes as Data Structures with operations where there is no need to know how types are implemented.Just to know the possible values, it's meaning and operations.

> Container ADTs Eg. list, stack, queue.

## Objects :

Blocks of memory containing some data. It consists of data & methods.These data and methods can be accessed by (.) “dot” notation

> Eg. the_stack.push()

## Classes :

A class is a blueprint for objects, defines attributes: data + methods.
Every object is created by instantiating a class, that's why object is an instance of class.

## Methods :

Define operations that can be performed by any object created as an instance of the class.
The `__init__` method is by convention the first method in a class.
Instance variables start with ` self`:
Their value is specific to each instance.
• Their name is global to all methods in the class. You can access it from every method in the class.
• If a variable does not start with self it is local to the method that binds it. Local variables can’t be seen by other methods.
