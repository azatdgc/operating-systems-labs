# Example 07 – Orphan Process

## Purpose
To demonstrate how a process becomes an orphan when its parent exits.

## System Calls / Functions Used
- `fork()`
- `sleep()`
- `getppid()`
- `printf()`

## How It Works
The parent exits immediately.  
The child waits 3 seconds and then prints its new parent PID (usually init).

## How to Compile and Run
