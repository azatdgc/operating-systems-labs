# Example 04 – Duplicating File Descriptors with dup()

## Purpose
The central goal of this exercise is to demonstrate the functionality of the **`dup()`** system call. `dup()` is used to create a **duplicate** of an existing file descriptor (FD), establishing a new FD that references the exact same open file description structure within the kernel.

---

## System Calls / Functions Used
The application highlights operations involving file descriptor management and I/O:

* **`open()`**: Opens the target file, returning the initial file descriptor.
* **`dup()`**: Creates a copy of the existing file descriptor. The new FD is guaranteed to be the lowest unused descriptor number available. 
* **`write()`**: Used to perform write operations using *both* the original and the duplicated file descriptors, illustrating that both FDs write to the same file.
* **`close()`**: Used to close file descriptors. Note that the file itself is only fully closed when the last reference (i.e., the last remaining file descriptor) to the open file description is closed.

---

## Operational Mechanics
This program confirms that duplicated file descriptors share critical state information:

1.  **File Access:** A file is opened, obtaining the original file descriptor (`oldfd`).
2.  **Duplication:** **`dup()`** is called, returning a new file descriptor (`newfd`). Crucially, both `oldfd` and `newfd` now point to the **same open file table entry**, meaning they share the **same file offset**.
3.  **Shared Offset:** A write operation performed using one descriptor (e.g., `oldfd`) advances the file offset. A subsequent write operation using the other descriptor (e.g., `newfd`) will begin writing immediately after the data written by the first, demonstrating the shared nature of the offset.
4.  **Verification:** The program typically writes distinct messages using both descriptors to verify that the data appears sequentially in the target file.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain. Execution requires the name of the file to be manipulated.

```bash
gcc main.c -o app
./app <filename_to_manipulate>

