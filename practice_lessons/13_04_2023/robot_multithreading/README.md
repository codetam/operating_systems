# Robot multithreading

## Command to run
```console
$ javac robot_multithreading/*.java
$ java robot_multithreading.Test
```

## Program description

This program will create two Deposits (A and B) and two Robot threads (1 and 2). The first step has both robots extracting objects from DepositA, in a random order. The second step has the robots insert objects to DepositB, where Robot1 is the first robot to act and they follow the round-robin scheduling.