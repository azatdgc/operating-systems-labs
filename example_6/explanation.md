# Example 06 – Process Synchronization using wait()

## Purpose
The primary purpose of this exercise is to demonstrate **process synchronization** in a parent-child relationship. Specifically, it illustrates how the **`wait()`** system call blocks the execution of the parent process until its associated child process terminates, thereby preventing the child from becoming a *zombie* process.

---

## System Calls / Functions Used
This application combines process creation, timing, and synchronization calls:

* **`fork()`**: Used to create the child process, which executes concurrently with the parent process.
* **`wait()`**: The crucial synchronization call; invoked by the parent process to suspend its own execution until one of its child processes changes state (typically terminates). 
* **`sleep()`**: Used within the child process to simulate a significant workload or delay, ensuring the parent enters the waiting state before the child finishes.
* **`printf()`**: Utilized to display the execution order and state changes of both the parent and child processes.

---

## Operational Mechanics
The program clearly separates the execution flow of the parent and child processes:

1.  **Process Bifurcation:** The **`fork()`** call initiates both the parent and child processes.
2.  **Parent Blockage:** The parent process immediately calls **`wait()`**. This causes the parent to pause execution and enter a blocked state, relinquishing the CPU until an event from the child occurs.
3.  **Child Simulation:** The child process executes **`sleep(2)`**, simulating a time-consuming task for 2 seconds. After the delay, the child terminates.
4.  **Resumption:** Upon the child's termination, the parent process is awakened by the kernel, allowing it to resume execution, clean up the child's resources, and conclude its own execution. This confirms successful synchronization.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain. No command-line arguments are required.

```bash
gcc main.c -o app
./app

