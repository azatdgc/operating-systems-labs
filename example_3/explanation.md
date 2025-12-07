# Example 03 – Repositioning the File Offset with lseek()

## Purpose
The main goal of this exercise is to demonstrate the functionality and usage of the **`lseek()`** system call. This call is critical for controlling and manipulating the **read/write offset** within an open file, enabling non-sequential (random) access to file data. 

---

## System Calls / Functions Used
The application utilizes a combination of I/O operations and the file seeking mechanism:

* **`open()`**: Initializes the file access by returning a file descriptor (FD).
* **`lseek()`**: Explicitly modifies the kernel's pointer that indicates the current position within the open file. This function takes an offset value and a reference point (`SEEK_SET`, `SEEK_CUR`, or `SEEK_END`).
* **`read()`**: Reads data starting from the new position established by `lseek()`.
* **`write()`**: (Optional in this specific example, but used for demonstration in the full source code) Writes data to the file, also starting from the current offset.
* **`close()`**: Releases the file descriptor and system resources.

---

## Operational Mechanics
This program is designed to access and display specific segments of a file rather than processing it from the beginning:

1.  **File Access:** The program opens the target file for reading.
2.  **Offset Modification:** The **`lseek()`** system call is invoked using the **`SEEK_SET`** reference point, directing the kernel to move the file pointer exactly 5 bytes forward from the absolute beginning of the file (offset 0).
3.  **Sequential Reading:** Following the repositioning, the subsequent **`read()`** operation begins retrieving data from the 6th byte onwards. The remaining content is then printed to the terminal via the standard output.

---

## Compilation and Execution
The program must be compiled using GCC and requires the target filename as a command-line argument. The file must be large enough (more than 5 bytes) for the seeking operation to be effective.

```bash
gcc main.c -o app
./app <filename_to_read>

