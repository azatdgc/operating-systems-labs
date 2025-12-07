# Example 10 – POSIX Threads (pthreads) Creation and Synchronization

## Purpose
The final objective of this laboratory exercise is to demonstrate the fundamental concepts of **multithreading** in Unix-like environments. Specifically, it illustrates how to create a concurrent execution flow (a thread) using the **POSIX Threads (pthreads)** standard and manage thread termination using synchronization primitives.

---

## System Calls / Functions Used
This application relies on the standard POSIX threads library (`pthread`):

* **`pthread_create()`**: The primary function used to create a new thread of execution within the calling process. The function is supplied with the address of the routine (function) that the new thread should begin executing. 
* **`pthread_join()`**: A crucial synchronization function. The calling thread (in this case, the `main` thread) blocks its own execution until the target thread (the one created by `pthread_create`) terminates its execution.
* **`pthread_self()`**: A utility function that returns the unique **Thread ID (TID)** of the thread from which it is called.
* **`printf()`**: Used to print information about the execution status and TIDs of both the main thread and the newly created thread.

---

## Operational Mechanics
The program establishes and manages a simple concurrent relationship between the main thread and a worker thread:

1.  **Thread Initiation:** The main thread calls **`pthread_create()`**, specifying the `thread_function()` as the entry point for the new worker thread.
2.  **Concurrent Execution:** The worker thread immediately begins executing its designated function, where it typically prints its own unique thread ID (`pthread_self()`).
3.  **Synchronization Point:** Simultaneously, the main thread calls **`pthread_join()`**. This call ensures that the main thread halts its execution and waits for the worker thread to finish its task and terminate.
4.  **Resource Cleanup:** Once the worker thread finishes, `pthread_join()` returns, and the main thread is responsible for cleaning up the resources associated with the terminated worker thread before concluding the program.

---

## Compilation and Execution
Programs utilizing the POSIX threads library must be explicitly linked against the library using the `-pthread` (or `-lpthread`) flag during compilation.

```bash
gcc main.c -o app -pthread
./app
