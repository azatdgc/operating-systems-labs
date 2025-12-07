# Example 05 – Process Creation and Identification with fork()

## Purpose
The core objective of this laboratory exercise is to demonstrate the fundamental method for creating a new, duplicate process in Unix-like environments using the **`fork()`** system call. It focuses on how the parent and child processes are differentiated by the return value of the call.

---

## System Calls / Functions Used
This simple application highlights the essential calls required for process creation and identification:

* **`fork()`**: A critical system call that creates an **exact copy** of the calling process (the parent). This results in two separate, but initially identical, processes running concurrently. 
* **`getpid()`**: Used to retrieve the **Process ID (PID)**, which is the unique numerical identifier assigned to the calling process by the operating system kernel.
* **`printf()`**: Used for standard output operations to display process identifiers for verification.

---

## Operational Mechanics
The key to understanding `fork()` lies in its return value, which differentiates the execution paths of the two processes:

1.  **Process Duplication:** When **`fork()`** is executed once, the code splits, and execution continues simultaneously in both the parent and the newly created child process.
2.  **Child Process Differentiation:**
    * The **Child Process** receives a return value of **0** from the `fork()` call. This serves as the flag that identifies the child's execution block.
3.  **Parent Process Differentiation:**
    * The **Parent Process** receives the **Process ID (PID)** of the newly created child process (a value greater than 0). This allows the parent to track and manage its children.
4.  **Verification:** Both processes use **`getpid()`** to print their own unique ID, confirming that two distinct entities are executing the code.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain and executed without any command-line arguments.

```bash
gcc main.c -o app
./app
