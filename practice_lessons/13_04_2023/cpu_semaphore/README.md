# Busy waiting

## Command to run
```shell
$ javac cpu_semaphore/*.java
$ java cpu_semaphore.Test
```

## Program description
This program creates a CPU, a shared resource used by multiple Processo objects, which will call the access function. Once they're done they will call the release function. All functions are called with the help of semaphores, the number of accesses must not exceed the number of Threads the CPU object has.