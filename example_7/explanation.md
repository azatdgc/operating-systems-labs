# Example 07 – The Orphan Process State

## Purpose
The primary objective of this exercise is to demonstrate the creation and subsequent adoption of an **Orphan Process**. This state occurs when a child process continues execution after its immediate parent process has unexpectedly terminated, illustrating the operating system's mechanism for process management continuity.

---

## System Calls / Functions Used
The application utilizes calls critical to process lifecycle management and status checking:

* **`fork()`**: Used to create the child process, which initially executes concurrently with the parent.
* **`sleep()`**: Introduced to force a delay in the child process's execution, guaranteeing that the parent process terminates *before* the child has completed its tasks.
* **`getppid()`**: Crucial for verification. This call retrieves the **Parent Process ID (PPID)**, which allows the child to check its parent's ID before and after the adoption event.
* **`exit()`**: Utilized by the parent process to terminate immediately upon creation of the child.

---

## Operational Mechanics
The program intentionally forces a sequence of events leading to the orphan state:

1.  **Process Bifurcation:** The **`fork()`** call creates the child process.
2.  **Parent Termination:** The parent process executes the **`exit()`** call almost immediately, failing to invoke `wait()` for its child. The parent terminates.
3.  **Child Adoption:** Once the parent dies, the kernel automatically assigns the child process to a new parent, typically the **`init` process** (or its equivalent system process manager, which always has PID 1).
4.  **Verification:** The child process, after waking up from **`sleep(3)`**, calls **`getppid()`** again. The printed PPID will be the ID of the new parent (PID 1), confirming the transition into the orphan state and subsequent adoption.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain and executed without command-line arguments.

```bash
gcc main.c -o app
./app
