# Example 08 – Zombie Process

## Purpose
To demonstrate creation of a zombie process.

## System Calls / Functions Used
- `fork()`
- `sleep()`
- `printf()`

## How It Works
The child exits immediately, but the parent does not call `wait()`.  
The child's entry remains in the process table as a zombie until the parent exits.

## How to Compile and Run
