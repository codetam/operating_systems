# Pipe send int

## Command to run
```console
$ ./pipe_sendint 2
I am the child, insert an integer: 1
I have written the integer in the pipe.
I am the child, insert an integer: 2
I have written the integer in the pipe.
I am the parent, I have read: 1
I am the parent, I have read: 2
```

## Program description
To run this program, you must input the number of integers you want to move into the pipe. The child process will take some integers as input and will move them to the parent through the pipe.