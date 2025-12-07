# Example 09 – Executing a New Program with execl()

## Purpose
The primary objective of this exercise is to demonstrate the functionality of the **`execl()`** system call. This call is fundamental for **process overlay**, where the executing process replaces its entire **process image** (code, data, stack, heap) with a new program specified by a path.

---

## System Calls / Functions Used
This application focuses on the execution environment change and basic error reporting:

* **`execl()`**: One of the functions in the `exec` family. It loads and executes a new program from the file system. If successful, the original program's code is completely replaced by the new program's code within the same Process ID (PID).
* **`printf()`**: Used to print a message *before* the `execl()` call. This message serves to verify that the original program was indeed running before the replacement.
* **`perror()`**: Essential for reporting errors. Since `execl()` never returns upon success, this function is used to indicate a failure (e.g., if the specified new program path is incorrect or the file lacks execution permissions).

---

## Operational Mechanics
The program's execution flow is characteristically linear and irreversible:

1.  **Preparation:** The program starts executing and first prints a preparatory message.
2.  **Process Overwrite:** The application then calls **`execl()`**, providing the full path to the new executable (e.g., `/bin/ls` or a custom program) and its command-line arguments.
3.  **Irreversible Change:**
    * **Success:** If `execl()` succeeds, the new program begins execution *immediately* within the original process's memory space and PID. Any code following the `execl()` call in the original program is never executed.
    * **Failure:** If `execl()` fails (e.g., file not found), it returns control to the calling program, which then executes **`perror()`** to display the error.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain. Execution simply starts the process that will attempt to replace its image.

```bash
gcc main.c -o app
./app

