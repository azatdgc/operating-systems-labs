# Example 02 – File Creation and Writing using open()

## Purpose
The objective of this application is to demonstrate the controlled creation of a new file and subsequent **unbuffered writing** of content to it, utilizing the mandatory file flags and permissions argument of the **`open()`** system call.

---

## System Calls / Functions Used
This exercise focuses on the following core I/O system calls:

* **`open()`**: Invoked with specific flags (`O_WRONLY`, `O_CREAT`, `O_TRUNC`) to either create a new file or open an existing one for writing. It returns the file descriptor (FD).
* **`write()`**: Transfers a specified sequence of bytes from a memory buffer directly to the file associated with the returned FD.
* **`close()`**: Used to release the file descriptor, ensuring data integrity and freeing up kernel resources.

---

## Operational Mechanics
The program executes the following steps:

1.  **File Creation:** The **`open()`** call is executed to create a new file named `test.txt`. The use of the `O_CREAT` flag ensures creation if the file does not exist, and the `O_WRONLY` flag sets the access mode to write-only.
2.  **Data Persistence:** A defined string message is passed via the **`write()`** system call, instructing the kernel to persist the data onto the file system via the newly created file descriptor.
3.  **Resource Release:** Finally, the **`close()`** system call is used to formally finalize the file operation and disconnect the application from the file descriptor.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain and executed without any command-line arguments, as the file name is hardcoded within the source code.

```bash
gcc main.c -o app
./app
