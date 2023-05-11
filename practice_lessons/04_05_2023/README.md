# Workers and farm

## Command to run
'''console
$ javac *.java
$ java Test
'''

## Program description

WorkerA, WorkerB and WorkerC execute their activity 8 times each in the order A, B, C. They fill up a matrix "farm" turning 0's into 1's. WorkerA works on the first row, B on the second and C on the third.

The program creates two workers per class and starts each thread.

Every time the matrix changes, the first column should fill up first, then the second and finally the third (we cannot have the combinations "101", "011", ...).