# Example 10 – pthread_create() (POSIX Threads)

## Purpose
To demonstrate how to create and manage a basic thread using POSIX threads.

## System Calls / Functions Used
- `pthread_create()` – creates a new thread
- `pthread_join()` – waits for a thread to finish
- `pthread_self()` – returns thread ID
- `printf()` – prints thread info

## How It Works
The program creates a thread using `pthread_create()`.  
The new thread runs the `thread_function()`, which prints its thread ID.  
The main thread waits for the created thread using `pthread_join()`.

## How to Compile and Run
