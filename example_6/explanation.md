# Example 06 – wait() System Call

## Purpose
To demonstrate how a parent process waits for a child process to complete.

## System Calls / Functions Used
- `fork()`
- `wait()`
- `sleep()`
- `printf()`

## How It Works
The parent process calls `wait()`, which blocks until the child terminates.  
The child sleeps for 2 seconds and then finishes.

## How to Compile and Run
