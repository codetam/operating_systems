# Consumer Producer - Monitor

## Command to run
```console
$ javac monitor_consumer_producer/*.java
$ java monitor_consumer_producer.Test
Item inserted, current size: 1
Item inserted, current size: 2
Item removed, current size: 1
Item inserted, current size: 2
Item removed, current size: 1
Item inserted, current size: 2
Item inserted, current size: 3
...
```

## Program description
This Java program is a demo of the popular **consumer/producer problem** in multi-threading. Instead of using semaphores, this time a Monitor class is used and it's necessary to prevent threads from accessing the critical region. The static variable *count* in the Monitor class represents the number of items in the list. The Consumer and Producer threads will be decreasing or increasing the *count* amount at random intervals, while the Test class initializes both threads.