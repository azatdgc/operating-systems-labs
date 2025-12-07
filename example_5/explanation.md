# Example 05 – Creating Child Processes using fork()

## Purpose
To demonstrate how to create a child process using `fork()`.

## System Calls / Functions Used
- `fork()`
- `getpid()`
- `printf()`

## How It Works
`fork()` splits the process into a parent and a child.  
The child process receives 0 as return value, while the parent receives the child PID.

## How to Compile and Run
