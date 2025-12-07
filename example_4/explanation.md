# Example 04 – dup() System Call

## Purpose
To demonstrate how `dup()` duplicates an existing file descriptor.

## System Calls / Functions Used
- `open()`
- `dup()`
- `write()`
- `close()`

## How It Works
The program opens a file and duplicates its file descriptor using `dup()`.  
Both file descriptors now point to the same file and share the same file offset.

## How to Compile and Run
