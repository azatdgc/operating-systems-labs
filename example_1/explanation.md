# Example 01 – Fundamental File I/O using System Calls

## Purpose
The primary objective of this exercise is to illustrate the mechanism of **unbuffered file input and output (I/O)** by directly invoking fundamental POSIX **System Calls**. Specifically, it demonstrates how to read data from a file descriptor into a memory buffer and subsequently write that buffer content to the standard output stream (`STDOUT_FILENO`).

---

## System Calls / Functions Used
This program relies exclusively on the core low-level file manipulation system calls provided by the operating system kernel:

* **`open()`**: Used to establish a connection to a specified file, returning a **file descriptor** (a non-negative integer identifier) used for all subsequent I/O operations.
* **`read()`**: Extracts data, defined by a specific byte count, from the file associated with the given descriptor and transfers it into a user-provided memory buffer.
* **`write()`**: Transfers data, defined by a specific byte count, from a user-provided memory buffer to the file or stream associated with the given file descriptor.
* **`close()`**: Used to terminate the connection to a file by releasing its associated file descriptor, thus freeing up system resources.

---

## Operational Mechanics
The application requires the name of a source file as a command-line argument. The workflow is as follows:

1.  **File Access:** The program first attempts to open the specified source file in read-only mode using **`open()`**.
2.  **Data Transfer Loop:** It enters a loop that continuously calls **`read()`** to pull a defined chunk of bytes into a temporary buffer.
3.  **Standard Output:** Immediately following a successful read operation, the same buffer content is sent to the console via **`write()`** directed to the standard output file descriptor.
4.  **Termination:** This read-write cycle continues until the **`read()`** call returns zero, indicating the **End-Of-File (EOF)** has been reached.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain.

```bash
gcc main.c -o app
./app <filename_to_read>
