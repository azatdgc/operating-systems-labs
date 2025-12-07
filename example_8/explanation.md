# Example 08 – Process Termination and the Zombie State

## Purpose
The primary objective of this laboratory exercise is to demonstrate the intentional creation of a **Zombie Process** (or *defunct process*). This specific state occurs when a child process terminates, but its parent process has not yet executed the **`wait()`** system call to retrieve its exit status, leaving the child's entry lingering in the system's process table.

---

## System Calls / Functions Used
The application uses calls to precisely control the lifecycle and timing of the processes:

* **`fork()`**: Used to establish the parent-child relationship, initiating the concurrent execution of two processes.
* **`exit()`**: Invoked by the child process to terminate immediately upon creation.
* **`sleep()`**: Crucially used within the **parent process** to introduce a delay. This guarantees that the parent remains active (does not terminate immediately) but also fails to call `wait()` during the child's termination phase.
* **`printf()`**: Used to display process identifiers (PIDs) and indicate process states.

---

## Operational Mechanics
The program's logic is structured to deliberately create a transient, uncleaned state:

1.  **Process Bifurcation:** The **`fork()`** call creates the child process.
2.  **Child Termination:** The child process executes its task and terminates immediately by calling **`exit()`**. The kernel cleans up its allocated memory and resources, but the entry in the process table (containing the PID and exit status) remains.
3.  **Parent Negligence:** The parent process, having intentionally omitted the **`wait()`** call, enters a **`sleep()`** state. 
4.  **Zombie State:** While the parent is sleeping, the terminated child process exists in the **Zombie state**. This process table entry consumes minimal system resources and can be verified externally (e.g., using the `ps` command) until the parent process eventually terminates or calls `wait()`.

---

## Compilation and Execution
The program is compiled using the standard GCC toolchain. No command-line arguments are required.

```bash
gcc main.c -o app
./app
