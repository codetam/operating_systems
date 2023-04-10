# Consumer Producer

## Command to run
```console
$ javac .\consumer_producer\*.java
$ java consumer_producer.Test
Producer has added an item! Number: 1
Consumer has purchased an item! Number: 0
Producer has added an item! Number: 1
Consumer has purchased an item! Number: 0
Producer has added an item! Number: 1
Producer has added an item! Number: 2
Consumer has purchased an item! Number: 1
...
```

## Program description
This Java program is a demo of the popular **consumer/producer problem** in multi-threading. The Semaphore class is necessary to prevent threads from accessing the critical region. The static variable *currentSize* in the Test class represents the number of items in the list. The Consumer and Producer threads will be decreasing or increasing the *currentSize* amount at random intervals, while the Test class initializes both threads.